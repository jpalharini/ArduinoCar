const int SPEED_L = 5;
const int L293_IN_L1 = 4;
const int L293_IN_L2 = 2;

const int SPEED_R = 7;
const int L293_IN_R1 = 8;
const int L293_IN_R2 = 9;

void setup()
{
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  // L293 as output
  pinMode(SPEED_L, OUTPUT);
  pinMode(L293_IN_L1, OUTPUT);
  pinMode(L293_IN_L2, OUTPUT);
  
  pinMode(SPEED_R, OUTPUT);
  pinMode(L293_IN_R1, OUTPUT);
  pinMode(L293_IN_R2, OUTPUT);
}

void goFront() {
  digitalWrite(L293_IN_L1, HIGH);
  digitalWrite(L293_IN_L2, LOW);
  
  digitalWrite(L293_IN_R1, HIGH);
  digitalWrite(L293_IN_R2, LOW);
}

void turnOff() {
  digitalWrite(L293_IN_L1, LOW);
  digitalWrite(L293_IN_L2, LOW);
  
  digitalWrite(L293_IN_R1, LOW);
  digitalWrite(L293_IN_R2, LOW);
}

void loop()
{
  // LED indicates it's on
  digitalWrite(LED_BUILTIN, HIGH);
  
  int light = analogRead(A5);
  int speed = 500;
  
  analogWrite(SPEED_L, speed);
  analogWrite(SPEED_R, speed);
  
  if (light > 950) {
    goFront();
  } else {
    turnOff();
  }
}
