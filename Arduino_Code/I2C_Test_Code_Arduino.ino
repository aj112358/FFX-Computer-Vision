/*
   Author: AJ Singh
   Date: Fri, June 26, 2020
   IDE V1.6.9
   Function: Code for I2C connection between Rpi4 and Arduino
*/

#include <Wire.h>
#include <Servo.h>

Servo my_servo; // Initializing servo object
#define servo_pin  3 // Arduino pin for servo

int start_pos = 0;
const int t=200; // Delay time in milliseconds


void setup() {
  Wire.begin(0x7E); // Join I2C bus as *slave* with address 7E
  Wire.onReceive(receiveEvent); // Specifying call function when Arduino receives data 
  
  Serial.begin(9600); // Initializing serial monitor @9600baud
  Serial.println("<Arduino Uno is ready!>");
  Serial.println("Waiting for Rpi4 angle input...");

  my_servo.attach(servo_pin);
  my_servo.write(start_pos); // Reset servo to starting angle
  
}

void loop() {
  delay(t);
}

//Function to rotate servo motor based
//on data received from the Rpi4
void receiveEvent(int howMany) {
  
  while (Wire.available()) {
    
    int c = Wire.read(); // Receive byte data as an *integer* (can change)
    Serial.print("Received ");
    Serial.println(c);

    Serial.print("Turning motor to ");
    Serial.print(c);
    Serial.println(" degrees!");
    Serial.println();

    my_servo.write(c);
    delay(t);    
    
    Serial.println("Waiting for Rpi4 angle input...");

  }
}
