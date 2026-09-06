# STM32-Based Vehicle Reverse Parking Assistance System

An embedded parking assistance system designed to detect obstacles behind a vehicle and provide visual and audible warnings based on distance.

## Features

- Ultrasonic distance measurement using HC-SR04
- STM32 NUCLEO-L031K6 microcontroller
- Three-level obstacle warning system
- Green LED for safe distance
- Orange LED with intermittent buzzer for warning
- Red LED with continuous buzzer for danger
- Distance displayed in meters
- Two 7-segment displays
- Two 74HC595 shift registers
- Reverse mode controlled by a switch
- Fully simulated and tested using Wokwi

## Distance Warning System

| Distance | Status | Warning |
|----------|--------|---------|
| > 120 cm | Safe | Green LED |
| 30–120 cm | Warning | Orange LED + intermittent buzzer |
| < 30 cm | Danger | Red LED + continuous buzzer |

## Components

- STM32 NUCLEO-L031K6
- HC-SR04 ultrasonic sensor
- 2 × 74HC595 shift registers
- 2 × 7-segment displays
- Red LED
- Orange LED
- Green LED
- Buzzer
- Slide switch
- 220 Ω resistors

## Simulation

This project was built and tested in [Wokwi](https://wokwi.com/), using `diagram.json` to define the circuit and `parking_assistance.ino` for the firmware.

## Technologies

- C/C++
- STM32
- Arduino Framework
- Embedded Systems
- Digital Electronics
- Wokwi
