#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "OPPO A78";        // Your Wi-Fi SSID
const char* password = "p9ae6jwr";  // Your Wi-Fi Password
const char* serverURL = "http://192.168.233.188:8000/api/sensor-data/";  // Replace with your server's IP and endpoint

void setup() {
    Serial.begin(115200);
    
    WiFi.begin(ssid, password);
    Serial.println("Starting..."); 
    Serial.println("Connecting to Wi-Fi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to Wi-Fi!");
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverURL);
        http.addHeader("Content-Type", "application/json");

        int vibration = analogRead(36);  // Replace with your actual pin
        int water_level = analogRead(39); // Replace with your actual pin

        String payload = "{\"vibration\": " + String(vibration) + ", \"water_level\": " + String(water_level) + "}";

        int httpResponseCode = http.POST(payload);

        if (httpResponseCode > 0) {
            Serial.println("Data sent successfully");
            Serial.println(http.getString());
        } else {
            Serial.print("Error sending data: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    } else {
        Serial.println("Wi-Fi Disconnected!");
    }
    delay(5000);  // Send data every 5 seconds
}
