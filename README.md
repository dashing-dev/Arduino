# IoT Sensor Data Transmission

This project demonstrates how to send sensor data (vibration and water level readings) from an ESP32 to a server via HTTP. The ESP32 is connected to a Wi-Fi network, reads data from analog sensors, and sends the data to a server in JSON format every 5 seconds.
Components Required

    ESP32 development board (e.g., ESP32 DevKitC)
    Vibration sensor (Analog output)
    Water level sensor (Analog output)
    Jumper wires
    Breadboard (optional)
    Wi-Fi network (for connecting the ESP32)

Libraries Used

    WiFi.h: For managing Wi-Fi connectivity.
    HTTPClient.h: For making HTTP requests.

Wiring

    Vibration sensor: Connect the analog output pin of the vibration sensor to pin 36 (ADC0) of the ESP32.
    Water level sensor: Connect the analog output pin of the water level sensor to pin 39 (ADC3) of the ESP32.

Software Requirements

    Arduino IDE: The project is written in C++ and uses the Arduino IDE for programming the ESP32.
    ESP32 board support: Ensure that the ESP32 board is installed in the Arduino IDE via the Board Manager.

Setup

    Install Arduino IDE: If not already installed, download and install the Arduino IDE.
    Install ESP32 support:
        Go to File > Preferences and add the following URL to the Additional Board Manager URLs:

    https://dl.espressif.com/dl/package_esp32_index.json

    Then, go to Tools > Board > Boards Manager, search for esp32, and install the latest version.

Connect the ESP32 to your computer using a USB cable.
