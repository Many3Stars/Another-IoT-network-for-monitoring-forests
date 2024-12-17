# Arduino

This folder contains the Arduino sketches used in **Sensor Node A** for data acquisition and preprocessing. The sketches are designed to support two operation modes: continuous data acquisition (Mode 1) and periodic data acquisition with advanced averaging techniques (Mode 2).

---

## Modes of Operation

### **Mode 1: Continuous Data Acquisition**
- **Description**:
  - In this mode, the Arduino continuously powers the sensors and acquires data without interruption.
  - The Raspberry Pi remains active and periodically requests the acquired data via I2C.
- **Use Case**:
  - Ideal for scenarios requiring real-time or near-real-time monitoring.

### **Mode 2: Periodic Data Acquisition with Power Management**
- **Description**:
  - In this mode, the system enters a low-power state between data acquisition intervals.
  - The Raspberry Pi powers down the sensors and itself, then wakes up periodically to acquire data.
  - Data is processed using either a **Trimmed Mean** or a **Winsorized Mean** to reduce the impact of noise and outliers.
  - After processing, the Arduino sends the data to the Raspberry Pi over I2C, and the Raspberry Pi transmits it using LoRa.
- **Use Case**:
  - Ideal for power-constrained environments where energy efficiency is critical.

---

## Arduino Sketches

1. **Mode_1_Continuous_Data_Acquisition.ino**
   - Implements continuous data acquisition.
   - The Arduino constantly acquires data from the sensors.
   - Responds to requests from the Raspberry Pi to send the data via I2C.

2. **Mode_1_Data_Acquisition_when_it_receives_request_from_Rasp.ino**
   - Similar to the first sketch, but data acquisition is triggered only when the Raspberry Pi sends a request.
   - Useful for reducing unnecessary sensor activity.

3. **Mode_2_Periodic_Acquisition_Trimmed_Mean.ino**
   - Implements periodic data acquisition with power management.
   - Processes acquired data using a **Trimmed Mean**, which discards extreme values to reduce the influence of outliers.

4. **Mode_2_Periodic_Acquisition_Winsorized_Mean.ino**
   - Similar to the previous sketch but processes data using a **Winsorized Mean**, which limits extreme values to reduce noise while retaining the original data structure.

---

## How It Works

1. **Sensor Activation**:
   - In **Mode 1**, sensors are always powered.
   - In **Mode 2**, sensors are activated only during the data acquisition period.

2. **Data Processing**:
   - The Arduino preprocesses the sensor data using the selected mode:
     - Continuous data stream (Mode 1).
     - Trimmed or Winsorized mean calculation (Mode 2).

3. **I2C Communication**:
   - The Arduino sends the processed data to the Raspberry Pi via I2C upon request.

4. **LoRa Transmission**:
   - The Raspberry Pi handles the transmission of the processed data via LoRa.

---

## How to Use

1. **Select the Desired Mode**:
   - Choose the appropriate sketch based on your use case (continuous or periodic data acquisition).

2. **Upload the Sketch**:
   - Open the selected `.ino` file in the Arduino IDE.
   - Upload it to the Arduino Uno.

3. **Configure the Raspberry Pi**:
   - Ensure the Raspberry Pi is configured to match the selected mode:
     - **Mode 1**: Continuous or on-request data acquisition.
     - **Mode 2**: Periodic data collection with power management.

4. **Test the System**:
   - Verify sensor readings and data transmission.
   - Check that the Raspberry Pi and Arduino communicate properly over I2C.

---

## Notes

- **Power Efficiency**:
  - Mode 2 significantly reduces power consumption by deactivating sensors and the Raspberry Pi between acquisition cycles.
  - Use this mode for long-term deployments in remote areas.

- **Data Integrity**:
  - Advanced processing methods (Trimmed and Winsorized Means) in Mode 2 ensure robust data quality by minimizing the impact of noise and outliers.

---

## Troubleshooting

- **I2C Communication Issues**:
  - Verify the wiring between the Arduino and Raspberry Pi (SDA/SCL connections).
  - Ensure the Raspberry Pi's I2C interface is enabled.

- **Unexpected Data Values**:
  - Check sensor connections and calibration.
  - Validate the averaging method used in Mode 2.

---
