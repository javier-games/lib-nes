#include <NES.h>

int RED = 9;
int BLU = 10;
int GRN = 11;


int mode = 0;

NES pad = NES(4,3,2,100);

void setup() {
  Keyboard.begin();
  
  pinMode(RED,OUTPUT);
  pinMode(BLU,OUTPUT);
  pinMode(GRN,OUTPUT);
  digitalWrite(RED,LOW);
  digitalWrite(GRN,LOW);
  digitalWrite(BLU,LOW);
  digitalWrite(BLU,HIGH);
  delay(100);
  digitalWrite(BLU,LOW);
  digitalWrite(RED,HIGH);
  delay(100);
  digitalWrite(RED,LOW);
  digitalWrite(GRN,HIGH);
  delay(100);
  digitalWrite(GRN,LOW);
  digitalWrite(BLU,HIGH);
    
}

void loop() {
  pad.update();
  
  changeMode();
  
  if( mode == 0 )
    directionMode();
  if( mode == 1 )
    writingMode();
    
}
