#include <IRremote.h>

#define PIN_IR 3
#define PIN_DETECT 2
#define PIN_DETECT2 4
#define PIN_STATUS 13
#define PIN_GAME 5

int redGoal = 0, redGoalLastState=0;
int blackGoal = 0, blackGoalLastState = 0;
int gameButtonState = 0, gameButtonLastState = 0;


unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


IRsend irsend;
void setup()
{
  pinMode(PIN_DETECT, INPUT);
  pinMode(PIN_DETECT2, INPUT);
  pinMode(PIN_STATUS, OUTPUT);
  pinMode(PIN_GAME, INPUT);
  irsend.enableIROut(38);
  irsend.mark(0);
  
  Serial.begin(9600);
}

void loop() {
  // read states of sensors
  redGoal = digitalRead(PIN_DETECT);
  blackGoal = digitalRead(PIN_DETECT2);
  //gameButtonState = digitalRead(PIN_GAME);
  int gButtonReading = digitalRead(PIN_GAME);
  
  // Check if newGame button is pressed
  
  
  if (gButtonReading != gameButtonLastState) {
    lastDebounceTime = millis();  
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (gButtonReading != gameButtonState) {
      gameButtonState = gButtonReading;
      if (gameButtonState == HIGH) {
        Serial.println("game.startNew");
      }
    }
  }
  
  //old button logic
 /* if (gameButtonState && !gameButtonLastState) {
    if (gameButtonState == HIGH) { 
      //lastDebounceTime = millis();
      Serial.println("game.startNew");
      }
  }*/
  
  // Check if either Sensor beam is broken
  if (redGoal && !redGoalLastState) {
    Serial.println("Red Beam Unbroken");
  }
  if (!redGoal && redGoalLastState) {
    Serial.println("goal.red");  
  }
  if (blackGoal && !blackGoalLastState) {
    Serial.println("Black Beam Unbroken");
  }
  if (!blackGoal && blackGoalLastState) {
    Serial.println("goal.black");  
  } 
  
  redGoalLastState = redGoal;
  blackGoalLastState = blackGoal;
  //gameButtonLastState = gameButtonState;
  gameButtonLastState = gButtonReading;
  
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT));
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT2));
}
