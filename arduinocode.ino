#include <ArduinoJson.h>


//Defining Pins for the Ultrasonic Sensor
#define echoPin 2
#define trigPin 3



//Defining Variables to Calculate the Distance
long duration;
int distance;

int value;

//Defining Pins for the Photoresistor
const int prPin = A0;


void setup() {
  //Setting pinMode for the PR 
  pinMode (prPin, INPUT);
  
  //Setting the Different pinModes for the Ultrasonic Sensor
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);

  //Begin Serial Communication
  Serial.begin(9600);

}

void loop() {
   //Reading of Room Brightness with PR
  int brightness = analogRead(prPin);

  //Dividing Brightness Value by 8 to Limit Level to 128 (
  brightness = brightness / 8;
  
  //Clearing the trigPins to reset
  digitalWrite(trigPin, LOW);

  //Setting the trigPin to high to obtain values
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);

  //Reading from the echoPin
  duration = pulseInLong(echoPin, HIGH);

  //Calculating the Distance Value
  distance = duration/58;

  //Send 1 Over Serial for High Brightness
  if (20 > distance && 35 > brightness) {
    Serial.println(1);
  }

  //Send 2 Over Serial for Low Brightness
  else if (20 > distance  && brightness > 35) {
    Serial.println(2);
  }

  //Send 3 Over Serial if Ultrasonic Sensor is not Triggered
  else if (distance > 20) {
    Serial.println(3);
  }
  
  
 
  
  
  
}
