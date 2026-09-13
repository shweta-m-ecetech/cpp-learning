# Smart Parking System

This project uses an Arduino Uno, an HC-SR04 ultrasonic sensor, a micro servo motor, and jumper wires to simulate an automatic parking barrier.

## Overview

The system detects a vehicle approaching the barrier using distance measurement. When the vehicle is within a set range, the servo opens the barrier. After the vehicle has passed and enough time has elapsed, the barrier closes automatically.

## Components

- Arduino Uno
- HC-SR04 ultrasonic sensor
- SG90 micro servo motor
- Breadboard
- Jumper wires
- 5V power supply

## How it works

1. The ultrasonic sensor measures distance continuously.
2. If the measured distance is less than or equal to 25 cm, the system considers a vehicle is near.
3. The servo rotates to the open position (90°).
4. The gate stays open for at least 5 seconds.
5. Once the vehicle moves away and the measured distance is greater than or equal to 35 cm, the barrier closes.

## Wiring

- Ultrasonic sensor TRIG -> Arduino pin 7
- Ultrasonic sensor ECHO -> Arduino pin 6
- Servo signal pin -> Arduino pin 9
- Servo VCC -> 5V
- Servo GND -> GND
- Sensor VCC -> 5V
- Sensor GND -> GND

## Project behavior

The serial monitor prints values such as:

- `Distance: 30 cm`
- `Vehicle detected!`
- `Opening barrier...`
- `Vehicle passed.`
- `Closing barrier...`
- `Barrier closed.`

## Build and upload

This project is configured for PlatformIO.

1. Open the project folder in VS Code.
2. Ensure PlatformIO is installed.
3. Run the build:
   ```bash
   platformio run
   ```
4. Upload to the Arduino Uno:
   ```bash
   platformio run --target upload
   ```
5. Open the serial monitor to view sensor readings and system messages.

## Notes

- The servo is used to represent the barrier arm.
- The detection threshold and close threshold are defined in the code as `DETECT_DISTANCE` and `CLEAR_DISTANCE`.
- This is a simple prototype for a parking access system and can be extended with LEDs, a second sensor, or a more realistic gate mechanism.

## File structure

- `src/main.cpp` — Arduino logic for distance detection and barrier control
- `platformio.ini` — PlatformIO board configuration

## Example output

```text
SMART PARKING BARRIER READY
Distance: 22 cm
Vehicle detected!
Opening barrier...
Distance: 42 cm
Vehicle passed.
Closing barrier...
Barrier closed.
```