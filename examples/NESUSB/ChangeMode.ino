
boolean change = false;

void changeMode(){
  
  if( pad.Select() && pad.Start() ){
    
    if( pad.Up_changed() && pad.Up() ){
      mode = 0;
      change = true;
      digitalWrite(RED,LOW);
      digitalWrite(GRN,LOW);
      digitalWrite(BLU,HIGH);
    }
    if( pad.Right() && pad.Right_changed() ){
      mode = 1;
      change = true;
      digitalWrite(BLU,LOW);
      digitalWrite(RED,LOW);
      digitalWrite(GRN,HIGH);
    }
    if( pad.Left() && pad.Left_changed() ){
      mode = 2;
      change = true;
      digitalWrite(GRN,LOW);
      digitalWrite(BLU,LOW);
      digitalWrite(RED,HIGH);
    }
    if( pad.Down() && pad.Down_changed() ){
      mode = 3;
      change = true;
      analogWrite(BLU,170);
      digitalWrite(GRN,LOW);
      analogWrite(RED,75);
    }
  }
}
