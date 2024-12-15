import smbus
import time
import json
import RPi.GPIO as GPIO

# Configuración del pin GPIO para el activar/desactivar alimentación del Arduino y sensores
ctr_pin = 15
GPIO.setmode(GPIO.BCM)
GPIO.setup(ctr_pin, GPIO.OUT)

# Dirección I2C del Arduino
arduino_address = 0x0B

# Inicialización del bus I2C
bus = smbus.SMBus(1)

# Tiempo en segundos entre peticiones
measurement_time = 10

# Tiempo en segundos entre activar sistema y toma de medida
wakeup_time = 20

def read_data():
    try:
        # Leer 14 bytes de datos desde el Arduino
        data = bus.read_i2c_block_data(arduino_address, 0, 14)
        
        # Decodificar los datos
        humidity_high = data[0]
        humidity_low = data[1]
        co2_high = (data[2] << 24) | (data[3] << 16) | (data[4] << 8) | data[5]
        oxygen_int = data[6]
        oxygen_decimal = data[7]
        ph_high = data[8]
        ph_low = data[9]
        ph_decimal = data[10]

        # Recuperar los valores
        humidity_percent = (humidity_high << 8 | humidity_low)
        co2 = co2_high
        oxygen = f"{oxygen_int*10}.{oxygen_decimal*10}"
        phValue = ((ph_high << 8 | ph_low) + (ph_decimal / 100.0)) * 4

        # Crear un diccionario con los datos
        data_dict = {
            "timestamp": int(time.time()),
            "humidity": humidity_percent,
            "co2": co2,
            "oxygen": oxygen,
            "pH": phValue
        }

        # Obtener la fecha actual (mes y año)
        now = time.localtime()
        file_name = f"{now.tm_mon}_{now.tm_year}.json"

        # Guardar los datos en el archivo de respaldo JSON
        with open(file_name, "a+") as file:
            json.dump(data_dict, file)
            file.write("\n")
            # Guardar los datos a transmitir
            tx_data_file = "tx_data.json"

        with open(tx_data_file, "w") as tx_file:
            json.dump(data_dict, tx_file)

            print("Datos guardados correctamente:")
            print("Humedad (%):", humidity_percent)
            print("CO2 (ppm):", co2)
            print("Oxígeno (%vol):", oxygen)
            print("pH:", phValue)

    except Exception as e:
        print("Error al leer datos:", e)

while True:
    GPIO.output(ctr_pin, GPIO.HIGH)
    time.sleep(wakeup_time) # Tiempo para despertar al sistema
    read_data()
    time.sleep(1)
    GPIO.output(ctr_pin, GPIO.LOW)
    time.sleep(measurement_time) # Esperar 20 minutos entre cada lectura