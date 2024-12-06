# PCB Manufacturing Sheets

This folder contains all the necessary schematics and designs for the manufacturing of PCBs related to the data acquisition and power supply of soil and leaf sensors.

## Overview

The designs in this folder are intended to be used with KiCad for PCB design and fabrication. The PCBs are categorized into two primary functions:

- **Power Supply PCBs:** Provide the required voltage levels for sensors and associated circuits.
- **Datalog PCBs:** Handle data acquisition from sensors and ensure reliable data transmission to the Arduino for processing.

### Sensors Supported

1. **Soil Sensors:** Measure parameters like soil humidity, temperature, and pH.
2. **Leaf Sensors:** Measure parameters like leaf humidity, temperature, and stomatal temperature.

---

## Components and Design Highlights

### Key Components
- Voltage regulators for stable power supply.
- PMOS/NMOS transistors for energy-efficient activation/deactivation.
- Circuitry for data acquisition and sensor-specific power requirements.

### PMOS vs NMOS Switching
- **PMOS Design (Recommended):** Low leakage current in the "off" state, ensuring better energy efficiency.
- **NMOS Design:** Functional but with higher leakage current, making it less efficient for long-term applications.

---

## Folder Structure and Details

Each subfolder contains files for a specific PCB design:

### 1. **Power_Supply_PCB**
   - Contains the schematic and PCB layout for the power supply.
   - Includes voltage regulation and distribution for all components.

### 2. **Leaf_PCB_with_NMOS**
   - PCB design for leaf sensors using an NMOS transistor for switching.
   - Measures leaf-related parameters like humidity and temperature.

### 3. **Leaf_PCB_with_PMOS**
   - PCB design for leaf sensors using a PMOS transistor for switching.
   - Optimized for energy efficiency with minimal leakage current.

### 4. **Soil_PCB_with_NMOS**
   - PCB design for soil sensors using an NMOS transistor for switching.
   - Measures soil parameters like humidity, temperature, and pH.

### 5. **Soil_PCB_with_PMOS**
   - PCB design for soil sensors using a PMOS transistor for switching.
   - Designed for low-power consumption and long-term deployments.

---

## Design Recommendations

- **Use PMOS designs for both leaf and soil sensors** to minimize power consumption during standby periods.
- Ensure all components are compatible with the specific voltage and current requirements of your sensors.

---

## How to Use

1. Open the KiCad project files from the respective subfolders.
2. Verify the schematic and PCB design as per your requirements.
3. Export the Gerber files for manufacturing.
4. Assemble the PCB using the components listed in the schematic.

---
