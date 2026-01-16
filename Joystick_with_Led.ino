int xPin = A0;
int yPin = A1;
int buttonPin = 7;

int upPin = 2;
int rightPin = 3;
int downPin = 4;
int leftPin = 5;

int xval;
int yval;
int buttonState;

void setup() {
  // put your setup code here, to run once:
for(int i=5; i<=6; i++){
  pinMode(i,INPUT);
}

for (int i = 2; i<=5; i++){
  pinMode(i,OUTPUT);
}

pinMode(buttonPin, INPUT_PULLUP);
Serial.begin(9600);
}


void loop() {
  xval = analogRead(xPin);
  yval = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonPin);
  int deadLow = 450;
  int deadHigh = 570;

  // turn all LEDs OFF
  digitalWrite(upPin, LOW);
  digitalWrite(rightPin, LOW);
  digitalWrite(downPin, LOW);
  digitalWrite(leftPin, LOW);

  // X axis
  if (xval < deadLow) {
    digitalWrite(rightPin, HIGH);
    
  }
  else if (xval > deadHigh) {
    digitalWrite(leftPin, HIGH);
  }

  // Y axis (SEPARATE!)
  if (yval < deadLow) {
    digitalWrite(upPin, HIGH);
  }
  else if (yval > deadHigh) {
    digitalWrite(downPin, HIGH);
  }
  else if(buttonState == 0){
    digitalWrite(downPin, HIGH);
    digitalWrite(upPin, HIGH);
    digitalWrite(leftPin, HIGH);
    digitalWrite(rightPin, HIGH);
  }
  delay(100);
}


