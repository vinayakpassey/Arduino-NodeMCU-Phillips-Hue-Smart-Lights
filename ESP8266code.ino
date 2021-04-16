//ESP8266 Header Files
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//Variable to Read Data from the Arduino
int data;



//WiFi Details
const char* user = "VikVin";
const char* password = "185Clark";
const char* hueAddress = "http://192.168.0.10/api/aBEaMMFLYnZdxfUbChE0dcyx8zGLflmgDxDO1rF8/lights/4/state";

void setup() {
  //Begin Serial Communication

  Serial.begin(9600);

  //Connect to WiFi
  WiFi.begin(user, password);


}
void loop() {



  //If the Serial port is open to communicate, begin communication between two devices
  if (Serial.available()) {



    //    //Reading data coming from Arduino
    data = Serial.parseInt();
    Serial.println(data);

    // Turn On at High Brightness
    if (data == 1) {
      turnOnHighBrightness();
    }

    //Turn On at Low Brightness
    else if (data == 2) {
      turnOnLowBrightness();
    }

    //Don't Turn On
    else if (data == 3) {
      turnOff();
    }


  }

}

void turnOnLowBrightness () {
  sendMessage("{\"on\":true, \"sat\":254, \"bri\":100,\"hue\":35000}");
}

void turnOnHighBrightness () {
  sendMessage("{\"on\":true, \"sat\":254, \"bri\":254,\"hue\":35000}");
}

void turnOff() {
  sendMessage("{\"on\":false}");
}

void sendMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(hueAddress);
    http.addHeader("Content-Type", "text/plain;charset=UTF-8");
    http.PUT(message);
    http.end();
  }


}
