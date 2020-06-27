#!/usr/bin/env python
# Python code for 'FFX-Computer-Vision'
# To be run on the Rpi4
# Currently, just made as a test


from smbus import SMBus

addr = 0x7E # Address of the Arduino
bus = SMBus(1) # Initializing the I2C bus 1

print("Enter an angle between 0 and 180 degrees. Type '-1' to exit program.  \n")

def main():
    while True:
        
        try:
            servo_angle = int(input("\nWhat angle? >>> "))
        except:
            print("A valid integer is required!")
            continue
    
        if servo_angle == -1:
            break
        
        elif servo_angle not in range(0,181):
            print("Angle must be between 0 and 180 degrees!")
                    
        else:
            print(f"Communicating {servo_angle} degrees to the Arduino...")
            bus.write_byte(addr, int(servo_angle))
            
    print("Thanks! Closing program...")
    

if __name__ == '__main__':
    main()
