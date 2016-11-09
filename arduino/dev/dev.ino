#define PIN_GAME 5

int gameButtonState = 0, gameButtonLastState = 0;

void setup(){
  pinMode(PIN_GAME, INPUT);
  Serial.begin(9600);
  
}

void loop(){
  gameButtonState = digitalRead(PIN_GAME);  
    // Check if newGame button is pressed
  if (gameButtonState && !gameButtonLastState) {
    if (gameButtonState == HIGH) { 
      Serial.println("Start New Game");
    }
    else {
      Serial.println(" Button off ");
    }
    delay(50);
  }
  
  gameButtonLastState = gameButtonState;
  
  Serial.println("Red Team Goal!");
  delay(1000);
  Serial.println("Black Team Goal!"); 
  delay(1000);
}
