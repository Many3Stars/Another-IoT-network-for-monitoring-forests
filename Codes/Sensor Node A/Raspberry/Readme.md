 # Raspberry

This folder contains the scripts and configurations used by the Raspberry Pi in **Sensor Node A**. The Raspberry Pi plays a crucial role in managing data communication between the Arduino and the IoT network.

---

## Functionality

The Raspberry Pi handles the following tasks:

1. **Requesting Data from Arduino**:  
   - The Raspberry Pi sends periodic requests to the Arduino over the I2C interface.  
   - The Arduino responds with the preprocessed sensor data.

2. **Storing Data in JSON Format**:  
   - The received data is stored locally in a JSON file as a backup.  
   - This ensures data is not lost if the LoRa connection fails temporarily.

3. **Transmitting Data via LoRa**:  
   - The Raspberry Pi uses an external LoRa communication module to send the sensor data to the IoT network.  
   - LoRa provides long-range, low-power communication ideal for remote monitoring.

--- 

## How It Works

1. **I2C Communication**:
   - The Raspberry Pi acts as an I2C master, sending requests to the Arduino (I2C slave).
   - Data exchange format:
     - **Request:** A simple command from the Raspberry Pi to trigger data transmission.
     - **Response:** The Arduino sends sensor readings in a structured format.

2. **Data Backup**:
   - After receiving the data, the Raspberry Pi writes it to a local JSON file.
   - This file acts as a backup, allowing recovery of data if the LoRa transmission fails.

3. **LoRa Transmission**:
   - The Raspberry Pi formats the data for LoRa transmission.
   - It sends the data using the external LoRa module, ensuring it reaches the IoT network even in remote environments.

---

## Notes

- **Backup and Resilience**:
  - JSON backups ensure data integrity in case of transmission failures.
  - These files can be uploaded manually to the IoT network if needed.

- **LoRa Module**:
  - Ensure the LoRa module is configured correctly for the region and frequency.
  - Check that the antenna is securely attached for optimal signal strength.

---
