/*
infrared sensor reciver. connect signal of infrared to analog pin 0. as the distance
from an object to sensor increases/decreases, you will increase/decrease
speed of led blinks from HIGH to LOW

*/

int IR_Pin = 4;    // select the input pin for the potentiometer
int IR_Value = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  // IR_Value = analogRead(IR_Pin);
  IR_Value = digitalRead(IR_Pin);  
 
Serial.println("delay value for LED = "+ IR_Value);  //what value are we reading once an IR led is detected? 

// IR_VALUE  = constrain(IR_VALUE, 0, 100); // optional to add a strict range
}

