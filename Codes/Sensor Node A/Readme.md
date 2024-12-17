# Sensor Node A

This folder contains the code and configurations for **Sensor Node A**, which is responsible for data acquisition, preprocessing, and transmission in the IoT monitoring system for forest environments.

---

## Overview

**Sensor Node A** integrates two primary components:

1. **Arduino Uno**:  
   - Acquires and preprocesses data from connected sensors (e.g., soil and leaf sensors).  
   - Processes sensor readings and prepares them for transmission.  
   - Communicates with the Raspberry Pi via I2C.

2. **Raspberry Pi 4 B**:  
   - Receives the preprocessed data from the Arduino over an I2C connection.  
   - Temporarily stores the data in a JSON format.  
   - Transmits the data to the IoT network using an external LoRa communication module.

This architecture ensures efficient handling of data while leveraging the long-range capabilities of LoRa communication for remote deployments.

---

## Key Features

- **I2C Communication**:  
  The Arduino sends preprocessed sensor data to the Raspberry Pi via an I2C interface, ensuring a reliable and simple data transfer method.

- **LoRa Transmission**:  
  The Raspberry Pi uses an external LoRa module to transmit the collected data over long distances. This is ideal for remote environments with limited connectivity.

- **Power Management**:  
  The system includes routines to minimize power consumption, such as turning off sensors when not in use.

---

## Folder Structure

- `arduino/`: Contains the Arduino sketch for:
  - Data acquisition from sensors.
  - Preprocessing and sending data to the Raspberry Pi via I2C.

- `raspberry_pi/`: Contains Python scripts for:
  - Receiving data over I2C.
  - Formatting and storing data in JSON files.
  - Transmitting data using the external LoRa communication module.

---

## How to Use

1. **Arduino Setup**:
   - Open the Arduino sketch from the `arduino/` folder.
   - Upload it to the Arduino Uno.
   - Ensure sensors are properly connected to the Arduino.

2. **Raspberry Pi Setup**:
   - Install the necessary Python dependencies listed in the `requirements.txt` (if provided).
   - Run the Raspberry Pi scripts to:
     - Initialize the I2C connection.
     - Manage data storage and LoRa transmission.

3. **Hardware Connections**:
   - Connect the Arduino and Raspberry Pi via I2C:
     - **Arduino SDA (A4)** → **Raspberry Pi SDA (GPIO2)**  
     - **Arduino SCL (A5)** → **Raspberry Pi SCL (GPIO3)**  
   - Ensure the LoRa module is properly connected to the Raspberry Pi.

4. **Run the System**:
   - Power on the devices and verify that:
     - The Arduino is acquiring sensor data and sending it over I2C.
     - The Raspberry Pi is successfully receiving the data and transmitting it via LoRa.

---

## Notes

- The external LoRa module must be configured correctly for the desired frequency and region.
- Ensure that both the Arduino and Raspberry Pi share a common ground (GND) for proper I2C communication.

---

## Troubleshooting

- **No I2C Communication:** 
  - Verify SDA and SCL connections.
  - Ensure the I2C interface is enabled on the Raspberry Pi.

- **LoRa Transmission Issues:** 
  - Check the LoRa module configuration and ensure it matches the receiver settings.
  - Verify the antenna is securely attached to the LoRa module.

---
