# Home Automation Without Internet to Run Electrical Devices

A WiFi-based home automation system that operates without internet connectivity using NodeMCU ESP8266 and Soft Access Point (AP) protocol. This project also published in IEEE paper:https://ieeexplore.ieee.org/abstract/document/11007453

## Overview

This project creates a local home automation network that allows users to control electrical devices like lights, fans, and appliances through any WiFi-enabled device (smartphone, laptop, tablet) without requiring an internet connection. The system uses NodeMCU ESP8266 as the main controller with relay modules to switch electrical loads.

## Key Features

- **Internet-free operation** - Works entirely on local WiFi network
- **Multi-device control** - Control up to 4 electrical appliances
- **Cross-platform compatibility** - Works with any device having WiFi capability
- **Web-based interface** - Simple HTML/CSS/JavaScript control panel
- **Real-time feedback** - Visual status indicators for each device
- **EEPROM memory** - Remembers device states after power cycles
- **Secure local network** - Password-protected Soft AP

## Hardware Components

### Required Components
- NodeMCU ESP8266-CP2102-12E Development Board
- 4-Channel 5V Relay Module
- Jumper wires
- LEDs for status indication
- Electrical sockets/appliances
- USB cable for programming
- 12V DC adapter for power supply
- Buzzer (optional)

### Pin Configuration
```
NodeMCU Pin -> Relay Module
D0 -> Relay 1 (IN1)
D1 -> Relay 2 (IN2)  
D2 -> Relay 3 (IN3)
D3 -> Relay 4 (IN4)
3.3V -> VCC
GND -> GND
```

## Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (Latest version recommended)
- ESP8266 Board Package
- EEPROM Library (built-in)
- ESP8266WiFi Library (built-in)
- ESP8266WebServer Library (built-in)

## Installation & Setup

### 1. Arduino IDE Setup

1. Download and install Arduino IDE from [official website](https://www.arduino.cc/en/software)
2. Open Arduino IDE
3. Go to `File > Preferences`
4. Add this URL to "Additional Board Manager URLs":
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
5. Go to `Tools > Board > Boards Manager`
6. Search for "ESP8266" and install the latest version
7. Select board: `Tools > Board > NodeMCU 1.0 (ESP-12E Module)`

### 2. Code Upload

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/home-automation-without-internet.git
   cd home-automation-without-internet
   ```

2. Open the `home_automation.ino` file in Arduino IDE

3. Modify WiFi credentials in the code:
   ```cpp
   const char* userid = "PROJECT E3";     // Your AP name
   const char* password = "E3PROJECT";    // Your AP password
   ```

4. Connect NodeMCU via USB cable
5. Select correct COM port: `Tools > Port`
6. Click Upload button

## How to Use

### 1. Initial Setup
1. Power on the NodeMCU system
2. Open WiFi settings on your phone/laptop
3. Connect to network "PROJECT E3" using password "E3PROJECT"
4. Open web browser and navigate to `192.168.4.1`

### 2. Device Control
- The web interface shows 4 controllable loads
- Click ON/OFF buttons to control each device
- Green circle = Device ON
- Red circle = Device OFF
- Status is automatically saved to memory

### 3. System Features
- **Load 1-4**: Individual control for each connected appliance
- **Status Display**: Real-time status indicators
- **Memory Function**: Device states preserved after power loss
- **Responsive Design**: Works on all screen sizes

## Circuit Diagram

```
NodeMCU ESP8266
    |
    +-- 4-Channel Relay Module
            |
            +-- Load 1 (Light/Fan)
            +-- Load 2 (Light/Fan)  
            +-- Load 3 (Appliance)
            +-- Load 4 (Appliance)
```

## Code Structure

### Main Functions
- `setup()` - Initialize system, WiFi AP, and web server
- `loop()` - Handle client requests and update relay states
- `SendHTML()` - Generate web interface
- `L1on()/L1off()` - Control functions for each load
- `data()` - Save states to EEPROM

### Key Libraries Used
```cpp
#include <ESP8266WiFi.h>        // WiFi functionality
#include <ESP8266WebServer.h>   // Web server
#include <EEPROM.h>             // Memory storage
```

## Technical Specifications

- **Microcontroller**: ESP8266 (32-bit, 80MHz)
- **WiFi Standard**: 802.11 b/g/n
- **Operating Voltage**: 3.3V
- **Input Voltage**: 7-12V
- **Relay Rating**: 5V, 10A
- **Communication**: HTTP protocol
- **Range**: 50-100 meters (depending on environment)

## Advantages

- **No Internet Dependency** - Works during internet outages
- **Low Cost** - Affordable components
- **Easy Installation** - No complex wiring
- **Secure** - Local network only
- **Reliable** - Simple architecture
- **Scalable** - Can be expanded for more devices

## Applications

- **Home Automation** - Control lights, fans, appliances
- **Office Automation** - Meeting room controls
- **Industrial Control** - Basic machine controls
- **Security Systems** - Door locks, alarms
- **Energy Management** - Automated power control

## Troubleshooting

### Common Issues

1. **Cannot connect to AP**
   - Check AP name and password
   - Restart NodeMCU
   - Clear WiFi cache on device

2. **Web page not loading**
   - Ensure connected to correct network
   - Try IP address: 192.168.4.1
   - Check serial monitor for errors

3. **Relays not switching**
   - Verify wiring connections
   - Check power supply voltage
   - Test relay module separately

### Serial Monitor Debug
Set baud rate to 115200 in serial monitor to view system status and IP address.

## Future Enhancements

- Voice control integration
- Mobile app development  
- Additional sensor inputs
- Timer and scheduling features
- Multiple room support
- Energy consumption monitoring

## Safety Warnings

- Always disconnect mains power before wiring
- Use proper electrical safety practices
- Ensure relay ratings match connected loads
- Install appropriate fuses/circuit breakers
- Test system thoroughly before permanent installation

## Contributing

This project is part of my learning journey in embedded systems and IoT development. Suggestions and improvements are welcome through issues and pull requests.

## License

This project is open source and available under the [MIT License](LICENSE).

**Note**: This project is designed for educational purposes and demonstrates practical implementation of IoT concepts without internet dependency. Always follow local electrical codes and safety regulations when working with mains electricity.

