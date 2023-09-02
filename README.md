# Smart Hearth Project 

![Smart Hearth Logo](images/smart-hearth-logo.png)

## Table of Contents
- [Introduction](#introduction)
  - [Product Overview](#product-overview)
  - [Key Components](#key-components)
- [Development](#development)
  - [Circuit Design](#circuit-design)
  - [Arduino Implementation](#arduino-implementation)
  - [Breadboard Implementation](#breadboard-implementation)
  - [PCB Design](#pcb-design)
  - [Enclosure Design](#enclosure-design)
- [List of Components](#list-of-components)
- [UI and UX](#ui-and-ux)
- [Testing and Results](#testing-and-results)
- [Further Improvements](#further-improvements)
- [Discussions](#discussions)
- [Bibliography](#bibliography)



## Introduction

### Product Overview

The Smart Hearth project is designed to address the challenges faced by households relying on traditional hearths for cooking. It introduces a system that automates temperature regulation, improving the cooking experience and reducing user intervention. The core components of the device include the ATmega328P microcontroller, MAX6675 Temperature Sensor, OLED display, potentiometer, DC fan, and more.

### Key Components

- **ATmega328-PU:** This high-performance microcontroller forms the heart of the system, controlling various aspects of the Smart Hearth's functionality.

- **MAX6675 Temperature Sensor:** Responsible for accurately measuring the temperature of the hearth, ensuring precise control.

- **OLED Display:** Provides users with real-time information about the selected temperature range and system status.

- **Potentiometer:** Enables users to choose from six predefined temperature ranges, enhancing user-friendliness.

- **DC Fan:** Regulates the heat by adjusting its speed based on the temperature sensor readings.

## Development

### Circuit Design

The project began with circuit design using the EasyEDA software, ensuring the proper connections among components. The schematic design encompassed various elements, including temperature sensors, microcontrollers, and motor driver modules.

### Arduino Implementation

The initial implementation involved testing the circuit with LED bulbs to assess brightness control based on temperature levels. Subsequently, a DC fan was integrated into the circuit, followed by the addition of a buzzer to alert users of abnormalities. The OLED display was also incorporated to visualize temperature settings.

### Breadboard Implementation

To move from Arduino testing to a standalone system, the circuit was replicated on a standalone ATmega328-PU microcontroller. This step ensured the transition to a more compact and functional setup.

### PCB Design

Altium software was used for designing a single-layer PCB, considering factors like trace width and power requirements. The design aimed to optimize the circuit layout for efficient performance.

### Enclosure Design

The physical enclosure for the Smart Hearth underwent careful consideration. A conical shape was chosen for the hearth's opening to facilitate efficient heat transfer. Aluminum was selected as the primary material for its durability and resistance to cracking. A wooden box surrounded the aluminum structure to prevent user harm from the heated material. The design also featured openings for the fan, LCD, potentiometer, and temperature sensor.

## List of Components

- **ATmega328-PU:** The microcontroller at the heart of the system.
- **MAX6675 Temperature Sensor:** Responsible for precise temperature measurements.
- **OLED Display:** Provides real-time information to users.
- **Potentiometer:** Enables user selection of temperature ranges.
- **DC Fan:** Regulates heat by adjusting speed.
- **L9110 Motor Driver Module:** Controls the fan's speed.
- **12V Power Pack:** Provides power to the system.

## UI and UX

The user interface consists of an OLED display and a potentiometer. Users can select from six temperature ranges, each represented by a specific color on the potentiometer. The selected range is displayed on the OLED, making it easy for users to monitor and adjust settings.

## Testing and Results

Extensive testing was conducted to ensure the system's functionality. Individual component testing was performed using Arduino, including LED brightness control, fan speed adjustment, buzzer functionality, and OLED output validation. The system successfully regulated temperature within selected ranges.

## Further Improvements

Future enhancements to the Smart Hearth system could include:

- Smoke disposal system for improved air quality.
- Development of a mobile app for remote control and monitoring.
- Enhanced product packaging for user convenience and safety.


## Discussions

During development, several challenges were addressed, including:

- Material selection for the hearth enclosure.
- Overlapping OLED display terms.
- Determining the optimal time for the buzzer to activate.


## Bibliography

- [Guide for I2C OLED Display with Arduino](https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/)
- [Spherical and Cylindrical Pressure Vessels](https://www.wermac.org/equipment/pressurevessel.html)
- [Getting Started With the ATMega328P](https://www.instructables.com/Getting-Started-With-the-ATMega328P/)
- [Temperature based Fan Speed Control](https://create.arduino.cc/projecthub/embeddedlab786/temperature-based-fan-speed-control-945f9d)
- [WHEN TO USE ALUMINUM VS STAINLESS STEEL](https://www.kloecknermetals.com/blog/when-to-use-aluminum-vs-stainless-steel/#:~:text=When%20comparing%20stainless%20steel%20vs,over%20steel%20in%20cold%20temperatures.)
- [The Laws of Thermo-Culinary Dynamics](https
