# IoT Monitoring System for Forest Environments

Author: Manuel Álvarez Herrera  
Supervisor: José Antonio García Souto  
Year: 2024

## Abstract

This project implements an IoT system to monitor forest environments, particularly coniferous and oak forests, aiming to study the effects of climate change. The IoT network consists of sensor nodes, intermediate nodes, and a database, enabling the collection and analysis of environmental and tree health data.

## Objectives

The primary objective is to observe the impact of climate change on trees by collecting relevant data such as temperature, humidity, solar radiation, and other key indicators.

## Technologies Used

- **Hardware:** Arduino, Raspberry Pi, Dragino NBSN95, LSN50, temperature, humidity sensors, and more.
- **Communication Protocols:** LoRa, NB-IoT, WiFi.
- **Databases:** InfluxDB, ThingsBoard, Home Assistant.
- **Weather Stations:** Ecowitt, Wunderground, Weathercloud.

## IoT Network Structure

1. **Sensor Node A:** Arduino Uno, Raspberry Pi 4 B, sensors for foliage and soil.
2. **Sensor Node B:** Dragino NBSN95 and LSN50 devices.
3. **Sensor Node C:** Sainlogic WS3500 weather station.

## Results

The system was successfully tested in a controlled environment, obtaining accurate data for forest environment analysis. The tests demonstrated the system's viability for monitoring remote forests.

## Conclusion

The designed IoT system is scalable, energy-efficient, and adaptable to various environments, including farms and urban forest areas.

## Repository

The code and additional documentation are available in the following GitHub repository:  
[Another IoT network for monitoring forests](https://github.com/Many3Stars/IoT-network-for-monitoring-forests)

## References

1. K. Raviteja, M. Supriya, "IoT-Based Agriculture Monitoring System", Springer, 2020.
2. N. Suma, S. Samson, "Recent Innovations in Computing and Communication", 2021.
3. Kazuho M., Takeshi O., "Dependence of Stomatal Conductance on Leaf Chlorophyll Concentration", 2025.

---
