
#define PIN_DETECT 2
#define PIN_DETECT2 4
#define PIN_STATUS 13


int redGoal = 0, redGoalLastState=0;
int blackGoal = 0, blackGoalLastState = 0;



void setup()
{
  pinMode(PIN_DETECT, INPUT);
  pinMode(PIN_DETECT2, INPUT);
  pinMode(PIN_STATUS, OUTPUT);

  digitalWrite(PIN_DETECT, HIGH);
  digitalWrite(PIN_DETECT2, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // read states of sensors
  redGoal = digitalRead(PIN_DETECT);
  blackGoal = digitalRead(PIN_DETECT2);

  // Check if either Sensor beam is broken

  if (redGoal == LOW || blackGoal == LOW) {
    digitalWrite(PIN_STATUS, HIGH);
  }
  else {
    digitalWrite(PIN_STATUS, LOW);
  }
  

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
  
  // digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT));
  // digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT2));
}
