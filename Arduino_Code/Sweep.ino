/*
   Author: AJ Singh
   Date: Mon, June 22, 2020
   IDE V1.6.9
   Function: To move a servo motor for FFX challenge.
*/

#include <Servo.h>
Servo my_servo; // Initializing servo object
int pos = 0;
int servo_pin = 3;
int delay_time1 = 10;
int delay_time2 = 10;
//int pos;
int incoming_data = 0;


const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false; // Tracks if data is inputted still exists in serial monitor

int dataNumber = 0; 



void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino Uni is ready!>");
  Serial.println("Please enter an angle between [0,180] degrees...");

  my_servo.attach(servo_pin);
}

void loop() {

  //    if (Serial.available() == 0) {
    //    }


  while (Serial.available() == 0) {
    // just waiting
  }

  recvWithEndMarker();
  showNewNumber();
}




void recvWithEndMarker() {
  static byte index = 0;
  char endMarker = '\n'; // Select "newline" as line-ending in serial monitor
  char received;



  if (Serial.available() > 0) {
    received = Serial.read();

    if (received != endMarker) {
      receivedChars[index] = received;
      index++;

      if (index >= numChars) {
        index = numChars - 1;
      }
    }
    else {
      receivedChars[index] = '\0'; // terminate the string
      index = 0;
      newData = true;
    }
  }
}

void showNewNumber() {
      dataNumber = 0;
  
  if (newData == true) {

    dataNumber = atoi(receivedChars);   // Convert ASCII number to integer
    
    Serial.print("Turning the servo motor to ");
    Serial.print(dataNumber);
    Serial.println(" degrees...");
    Serial.println();
    
    newData = false;
    Serial.println("Please enter an integer between 0 and 180: ");


  }
}






////////////////////////

// OLD CODE

//
//while (Serial.available() == 0) {
//  // Waiting for user input
//}
//
//  incoming_data = Serial.read;
//
//
//
////  for (pos = 0; pos <= 180; pos+=1) {
//////    Serial.println(pos);
////
//////    pos = my_servo.read();
//////    Serial.println(pos);
////    my_servo.write(pos);
//////    delayMicroseconds(delay_time1);
////    delay(delay_time2);
////  }
////
//////  for (pos = 180; pos >= 0; pos-=1) {
//////    my_servo.write(pos);
////////    delayMicroseconds(delay_time1);
//////    delay(delay_time2);
//////  }
