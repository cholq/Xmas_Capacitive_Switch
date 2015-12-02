#define RELAY_PIN       0
#define TOUCH_PIN       2
#define CURR_PIN        4
#define PREV_PIN        5

uint8_t VirtualPortNb;
boolean RelayState;
int TouchValue;
int PrevValue;

void setup() {

  pinMode(TOUCH_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(CURR_PIN, OUTPUT);
  pinMode(PREV_PIN, OUTPUT);

  RelayState = LOW;
  TouchValue = 0;
  PrevValue = 0;

}

void TouchDetected(void)
{  
    RelayState = !RelayState;
    
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(CURR_PIN, TouchValue);
  digitalWrite(PREV_PIN, PrevValue);

  TouchValue = digitalRead(TOUCH_PIN);
  if (TouchValue == HIGH)
  {
    if (PrevValue == LOW) 
    {
      TouchDetected();
    }
  }

  PrevValue = TouchValue;
  digitalWrite(RELAY_PIN, RelayState);
  delay(20);

}
