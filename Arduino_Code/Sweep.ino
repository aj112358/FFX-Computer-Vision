/*
   Author: AJ Singh
   Date: Tues, June 23, 2020
   IDE V1.6.9
   Function: Better code (?) to move a servo motor for FFX challenge.
*/

#include <Servo.h>
Servo my_servo; // Initializing servo object

int start_pos = 0;
int servo_pin = 3;

char incoming_byte = 0;
String number_string = "";
boolean not_a_number = false;

int rotation_angle;


void setup() {
  Serial.begin(9600);
  
  Serial.println("<Arduino Uno is ready!>");
  Serial.println("Please enter an integer between 0 and 180:");

  my_servo.attach(servo_pin);
  my_servo.write(start_pos); // Reset servo to starting angle
}


void loop() {
  if (Serial.available() > 0) {
    incoming_byte = Serial.read();

    // If current byte is a number, keep it
    // Checking the input's ASCII values
    if ( incoming_byte >= '0' && incoming_byte <= '9' ) {
      number_string += incoming_byte;
    }

    // If it's a newline, then no more inputs
    // Check if input is good
    else if (incoming_byte == '\n') {
            rotation_angle = number_string.toInt();   
                                 
            // Check: Input is a number?
            if (not_a_number) {
              Serial.println("Not a number!");
            }
                        
            // Check: Something even entered?
            else if (number_string == "") {
              Serial.println("No input detected!");
            }

            // Check: Input is within [0,180]?

            else if (rotation_angle < 0 || rotation_angle > 180) {
              Serial.println("Integer must be between 0 and 180");
            }

            // Send results to servo motor
            else {              
              Serial.print("Rotating servo motor to ");
              Serial.print(rotation_angle);
              Serial.println(" degrees...");
              Serial.println();
              
              my_servo.write(rotation_angle);
              
              Serial.println("Please enter an integer between 0 and 180:");
            }
            
            not_a_number = false;   // reset flag
            number_string = "";     // clear the string for reuse
    } // end of: else if (incoming_byte == '\n')

    
    // Flag a non-number    
    else {
      not_a_number = true;
    }
    
  } // end of: if (Serial.available() > 0)
}
