#include <Wire.h>
#include "DFRobot_OxygenSensor.h"

#define I2C_SLAVE_ADDRESS 0x0B
#define pwmPin 5
#define humPin A0
#define phPin A1

// Variables globales para mantener los valores actualizados
float oxygenData = 0.0;
float humidity_percent = 0.0; // Variable para la humedad relativa en %
float pHValue = 0.0; // Variable para el valor de pH
float ppmAvg = 0.0; // Variable para la media de CO2 durante 30 segundos
unsigned int sampleCount = 0;

// Configuración del sensor de oxígeno
#define Oxygen_IICAddress ADDRESS_3
#define COLLECT_NUMBER 10
DFRobot_OxygenSensor oxygen;

// OFFSET para el sensor de pH
float OFFSET = 0.0; // Ajusta esto según las especificaciones del sensor

// Tanto por ciento del los límites
#define limPercent 40

// Tiempo en que se toman las medidas en ms
#define MEAS_TIME 30000

unsigned long requestStartTime = 0;
bool isDataCollecting = false;

void requestEvent();

float calculateAverage(float values[], int count) {
  // Calcular la media inicial
  float sum = 0.0;
  for (int i = 0; i < count; i++) {
    sum += values[i];
  }
  float initialMean = sum / count;

  // Calcular los límites superior e inferior
  float upperLimit = initialMean * (1.0 + limPercent / 100.0);
  float lowerLimit = initialMean * (1.0 - limPercent / 100.0);

  // Calcular la media truncada
  sum = 0.0;
  int validCount = 0;
  for (int i = 0; i < count; i++) {
    if (values[i] >= lowerLimit && values[i] <= upperLimit) {
      sum += values[i];
      validCount++;
    }
  }

  if (validCount > 0) {
    return sum / validCount;
  } else {
    return initialMean;
  }
}

void resetAverages() {
  for (int i = 0; i < sampleCount; i++) {
    ppmValues[i] = 0.0;
    humidityValues[i] = 0.0;
    oxygenValues[i] = 0.0;
    pHValues[i] = 0.0;
  }
  sampleCount = 0;
}

void setup() {
  Serial.begin(9600);
  pinMode(pwmPin, INPUT);
  Wire.begin(I2C_SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);

  // Inicialización del sensor de oxígeno
  while (!oxygen.begin(Oxygen_IICAddress)) {
    Serial.println("Error al conectar con el sensor de oxígeno.");
    delay(1000);
  }
  Serial.println("Conexión exitosa con el sensor de oxígeno.");
}

void loop() {

  if (isDataCollecting) {
    unsigned long elapsedTime = millis() - requestStartTime;

    long tt = millis();
    int myVal = digitalRead(pwmPin);

    if (myVal == HIGH) {
      if (myVal != prevVal) {
        h = tt;
        tl = h - l;
        prevVal = myVal;
      }
    } else {
      if (myVal != prevVal) {
        l = tt;
        th = l - h;
        prevVal = myVal;
        ppm = 2000 * (th - 2) / (th + tl - 4);
      }
    }

    // Lectura de datos del sensor de oxígeno
    oxygenData = oxygen.getOxygenData(COLLECT_NUMBER);

    // Lectura de humedad y conversión a porcentaje
    int humRaw = analogRead(humPin);
    humidity_percent = map(humRaw, 0, 1023, 0, 100);

    // Lectura del sensor de pH
    int phRaw = analogRead(phPin);
    pHValue = 3.5 * (phRaw / 1023.0) + OFFSET;

    if (elapsedTime >= MEAS_TIME) { // 30 segundos
      // Calcular las medias de cada sensor durante 30 segundos
      float avgCO2 = calculateAverage(ppmValues, sampleCount);
      float avgHumi = calculateAverage(humidityValues, sampleCount);
      float avgOxygen = calculateAverage(oxygenValues, sampleCount);
      float avgPH = calculateAverage(pHValues, sampleCount);

      // Enviar medias por I2C
      byte dataToSend[14];

      // Mostrar valores por pantalla
      Serial.print("Humedad (%): ");
      Serial.println(humidity_percent);
      Serial.print("CO2 (ppm): ");
      Serial.println(ppm);
      Serial.print("Oxígeno (%vol): ");
      Serial.println(oxygenData);
      Serial.print("pH: ");
      Serial.println(pHValue);

      // Enviar datos por I2C
      byte dataToSend[14];
      dataToSend[0] = (int(humidity_percent) >> 8) & 0xFF; // High byte of humidity
      dataToSend[1] = int(humidity_percent) & 0xFF; // Low byte of humidity
      dataToSend[2] = (ppm >> 24) & 0xFF; // Highest byte of CO2
      dataToSend[3] = (ppm >> 16) & 0xFF; // High byte of CO2
      dataToSend[4] = (ppm >> 8) & 0xFF; // Middle byte of CO2
      dataToSend[5] = ppm & 0xFF; // Low byte of CO2
      dataToSend[6] = int(oxygenData); // Valor entero de oxígeno
      dataToSend[7] = int((oxygenData * 10) - int(oxygenData) * 10); // Decimal de oxígeno
      dataToSend[8] = (int(pHValue) >> 8) & 0xFF; // High byte of pH
      dataToSend[9] = int(pHValue) & 0xFF; // Low byte of pH
      dataToSend[10] = int((pHValue - int(pHValue)) * 100); // Parte decimal de pH
      
      Wire.write(dataToSend, sizeof(dataToSend));

      // Reiniciar variables para la siguiente medición
      resetAverages();
      isDataCollecting = false;
    }
  }
}