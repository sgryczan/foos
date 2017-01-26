
#define PIN_IR 3
#define PIN_DETECT 2
#define PIN_DETECT2 4
#define PIN_STATUS 13
#define PIN_GAME 5
#define PIN_ADDRED 6
#define PIN_ADDBLACK 7


int redGoal = 0, redGoalLastState=0;
int blackGoal = 0, blackGoalLastState = 0;
int redAddGoal = 0, redAddGoalLS = 0;
int blackAddGoal = 0, blackAddGoalLS = 0;
int gameButtonState = 0, gameButtonLastState = 0;


unsigned long glastDebounceTime = 0;
unsigned long rlastDebounceTime = 0;
unsigned long blastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup()
{
  pinMode(PIN_DETECT, INPUT);
  pinMode(PIN_DETECT2, INPUT);
  pinMode(PIN_STATUS, OUTPUT);
  pinMode(PIN_GAME, INPUT);
  pinMode(PIN_ADDRED, INPUT);
  pinMode(PIN_ADDBLACK, INPUT);
  
  digitalWrite(PIN_DETECT, HIGH);
  digitalWrite(PIN_DETECT2, HIGH);


  Serial.begin(9600);
}

void loop() {
  // read states of sensors
  redGoal = digitalRead(PIN_DETECT);
  blackGoal = digitalRead(PIN_DETECT2);
  //gameButtonState = digitalRead(PIN_GAME);
  int gButtonReading = digitalRead(PIN_GAME);
  int rButtonReading = digitalRead(PIN_ADDRED);
  int bButtonReading = digitalRead(PIN_ADDBLACK);
  
  // Check if newGame button is pressed
  
  
  if (gButtonReading != gameButtonLastState) {
    glastDebounceTime = millis();  
  }
  if ((millis() - glastDebounceTime) > debounceDelay) {
    if (gButtonReading != gameButtonState) {
      gameButtonState = gButtonReading;
      if (gameButtonState == HIGH) {
        Serial.println("game.startNew");
      }
    }
  }

    if (rButtonReading != redAddGoalLS) {
    rlastDebounceTime = millis();  
  }
  if ((millis() - rlastDebounceTime) > debounceDelay) {
    if (rButtonReading != redAddGoal) {
      redAddGoal = rButtonReading;
      if (redAddGoal == HIGH) {
        Serial.println("goal.red");
      }
    }
  }
  
      if (bButtonReading != blackAddGoalLS) {
    blastDebounceTime = millis();  
  }
  if ((millis() - blastDebounceTime) > debounceDelay) {
    if (bButtonReading != blackAddGoal) {
      blackAddGoal = bButtonReading;
      if (blackAddGoal == HIGH) {
        Serial.println("goal.black");
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
    Serial.println("Red Beam Unbroken.");
  }
  if (!redGoal && redGoalLastState) {
    Serial.println("goal.red");  
  }
  if (blackGoal && !blackGoalLastState) {
    Serial.println("Black Beam Unbroken.");
  }
  if (!blackGoal && blackGoalLastState) {
    Serial.println("goal.black");  
  } 
  
  redGoalLastState = redGoal;
  blackGoalLastState = blackGoal;
  //gameButtonLastState = gameButtonState;
  gameButtonLastState = gButtonReading;
  redAddGoalLS = rButtonReading;
  blackAddGoalLS = bButtonReading;
  
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT));
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT2));
}
