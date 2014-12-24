float letter = 0;//26
boolean capital = false;
float spd = 0.06;

void writingMode(){
  if( !change ){
    if( pad.A_changed() ){
      if( pad.A() )
        Keyboard.press(65);
      else
        Keyboard.release(65);
      letter = 0;
      capital = true;
    } 
    if( pad.B_changed() ){
      if( pad.B() )
        Keyboard.press(178);
      else
        Keyboard.release(178);
    }
  
    if( pad.Up_changed() ){
      if( pad.Up() ){
        letter+=spd;
        Keyboard.press(178);
        Keyboard.press(65+round(letter));
      }
      else{
        Keyboard.release(178);
        Keyboard.release(65+round(letter));
      }
    }
    if(letter>25)
      letter = 0;
    if(letter<0)it
      letter = 0;
                                                                                            
    
  
    if( pad.Down_changed() ){
      if( pad.Down() )
        Keyboard.press(217);
      else
        Keyboard.release(217);
    }
  
    if( pad.Left_changed() ){
      if( pad.Left() )
        Keyboard.press(216);
      else
        Keyboard.release(216);
    }
    
    if( pad.Right_changed() ){
      if( pad.Right() )
        Keyboard.press(215);
      else
        Keyboard.release(215);
    }
  }
  else
    change = false;
}

