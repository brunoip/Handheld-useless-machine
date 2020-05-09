
#include <Servo.h>
int incomingByte = 0; // for incoming serial data

#define ServoPin 4  
#define StopPin   2 

// variables
int servoPosition =44;
int buttonState = 0; // variable for reading the pushbutton status
Servo servo;  //create servo object

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(StopPin, INPUT);
  servo.attach(ServoPin); // Attach the servo to pin
  servo.write(servoPosition); // Tell servo to go to position
  delay(100);  
}

void loop()  {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(StopPin);

  // check if the pushbutton is pressed.
  if (buttonState == LOW) {
    delay(20); 
    buttonState = digitalRead(StopPin);
    if (buttonState == LOW) {
        servo.write(44);
        delay(300); 
        servo.write(128);
        delay(300); 
        servo.write(44);
        delay(300);
    }
  }
    Serial.print("Input: ");
    Serial.println(buttonState);

    Serial.print("Servo position: ");
    Serial.println(servoPosition, DEC);    
}
