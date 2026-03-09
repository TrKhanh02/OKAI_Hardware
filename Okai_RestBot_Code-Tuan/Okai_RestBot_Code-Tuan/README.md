# RestBot – Autonomous Delivery Robot for Restaurants

## Objective
Autonomous robot designed for restaurant delivery tasks:
- Deliver food from kitchen to customer tables  
- Avoid obstacles (static and moving)  
- Display status via LCD and LED  
- Play voice or sound notifications via MP3 module  
- Support manual remote control over WiFi / MQTT  

## System Architecture
The system includes two MCUs:
- **ESP32**: main controller for motor control, WiFi/MQTT, LCD, LED, MP3t
- **ESP8266**: main controller for ultra wide band 
- **Nuvoton MCU**: handles sensor data (UWB, LIDAR, IMU)

Communication between MCUs via UART (115200 baud, JSON or binary struct).

## Main Hardware Components
| Component | Description |
|------------|--------------|
| ESP32 | Main MCU, logic and motor control |
| ESP8266 | Main MCU, logic for ultra wide band |
| Nuvoton MCU | Sensor data processing |
| LIDAR | 360° scanning for obstacle detection |
| UWB Module | Indoor positioning (X/Y coordinates) |
| BNO08x | IMU for heading and tilt measurement |
| LCD | Display robot status and delivery info |
| LED RGB | Status indication |
| MP3 Module | Audio announcements |
| DC Motor | Movement and speed  |
| Motor Driver | Power control for motors |
| 12V/24V Battery | Power supply |

## Operation Modes
1. **Manual Mode** – controlled manually via mobile app.  
2. **Auto Mode** – navigate autonomously to target coordinates (UWB).  
3. **Avoidance Mode** – obstacle avoidance using LIDAR.  
4. **Arrived Mode** – indicate arrival with LED and MP3 playback.  

## Communication
- **ESP32 ↔ Nuvoton:** UART (115200 baud)  
- **ESP32 ↔ Server:** MQTT over WiFi  
- **Sensor data:** `{x, y, heading, lidarMap[], uwbFix}`  
- **Control command:** `{cmd, motorL, motorR}`  

## ESP32 Software
- PID motor speed control  
- Heading stabilization using BNO08x  
- Robot state machine (IDLE, MOVING, AVOIDING, ARRIVED)  
- MQTT client for command and status updates  
- LCD display control  
- LED and MP3 state indicators  

## Nuvoton Software
- Read and process UWB, LIDAR, and IMU data  
- Compute robot position (X/Y)  
- Send fused data to ESP32 (~10Hz)  
- Optional filter for sensor fusion  

## Safety Features
- Emergency stop if LIDAR detects obstacle <30cm  
- Stop on loss of UWB or WiFi signal  
- Sound alert for low battery or error state  

## Deployment Notes
- At least 3 UWB anchors are required for stable indoor positioning  
- LIDAR scan rate around 10Hz recommended  
- Use 12V 20Ah battery for adequate runtime  
- ESP32 supports OTA updates over WiFi  

## License
Internal project – not for public release.

