#define PIN_GAME 5

int gameButtonState = 0, gameButtonLastState = 0;

void setup(){
  Serial.begin(9600);
  
}

void loop(){
    Serial.println("goal.red");
    delay(1500);
    Serial.println("goal.black"); 
    delay(1500);
}
