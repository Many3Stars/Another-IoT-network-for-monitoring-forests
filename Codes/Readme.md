# Codes

This directory contains the source codes for the two types of sensor nodes used in the IoT monitoring system for forest environments: **Sensor Node A** and **Sensor Node B**. These nodes handle data acquisition, preprocessing, and transmission to the IoT network.

---

## Sensor Nodes Overview

### **Sensor Node A**
- **Functionality:** 
  - This node is designed to acquire and process data from various sensors.
  - The sensors are connected to an Arduino Uno, which handles data acquisition and preprocessing.
  - The processed data is then transmitted to a Raspberry Pi 4 B, which:
    - Powers the sensors.
    - Temporarily stores the data in a JSON file.
    - Transmits the data via LoRa communication to the IoT network.
- **Communication Protocol:** LoRa (long-range, low-power communication).
- **Use Case:** Suitable for applications requiring robust communication over long distances in remote environments.

### **Sensor Node B**
- **Functionality:**
  - This node uses Dragino devices (NBSN95 and LSN50) for data acquisition, preprocessing, and transmission.
  - Each device serves a specific purpose:
    - **NBSN95:** Transmits data via NB-IoT, leveraging GSM networks for mobile communication.
    - **LSN50:** Transmits data via LoRa for long-distance communication.
  - These nodes are compact and support plug-and-play operation, ideal for rapid deployment.
- **Communication Protocols:** 
  - NB-IoT (NBSN95)
  - LoRa (LSN50)
- **Use Case:** Versatile for environments with varying communication infrastructure.

---

## Folder Structure

### **Sensor_Node_A**
- Contains the source code for Sensor Node A.
- Key Features:
  - Arduino sketch for data acquisition and preprocessing.
  - Raspberry Pi scripts for:
    - JSON-based temporary data storage.
    - Transmission using LoRa communication.
  - Power management routines for efficient operation.

### **Sensor_Node_B**
- Contains the source code for Sensor Node B.
- Key Features:
  - Firmware for Dragino NBSN95 and LSN50 devices.
  - Configurations for sensor data acquisition and transmission.
  - NB-IoT and LoRa-specific implementations for data handling.

---

## How to Use

1. **Select the Appropriate Node:**
   - Use **Sensor Node A** for scenarios requiring detailed control via Arduino and Raspberry Pi.
   - Use **Sensor Node B** for rapid deployment with Dragino devices.

2. **Upload the Code:**
   - For Sensor Node A:
     - Upload the Arduino sketch to the Arduino Uno.
     - Deploy the Raspberry Pi scripts.
   - For Sensor Node B:
     - Configure and upload the firmware to the NBSN95 and LSN50 devices.

3. **Test the Nodes:**
   - Verify sensor data acquisition and preprocessing.
   - Ensure successful data transmission via the appropriate protocol (LoRa or NB-IoT).

---

## Notes

- Ensure all hardware components are correctly connected and powered before uploading the code.
- Customize the configuration files as needed for your specific sensors and deployment environment.
- Detailed instructions for setting up and calibrating the nodes can be found in the respective subfolders.

---

## Support

If you encounter issues or have questions:
- Refer to the comments in the code for additional guidance.
- Open an issue in this repository or contact the repository maintainer for further assistance.

---
