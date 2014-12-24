
void directionMode(){
  if( !change ){ 
    if( pad.A_changed() ){
      if( pad.A() )
        Keyboard.press(10);
      else
        Keyboard.release(10);
    }
  
    if( pad.B_changed() ){
      if( pad.B() )
        Keyboard.press(179);
      else
        Keyboard.release(179);
    }
  
    if( pad.Up_changed() && !change ){
      if( pad.Up() )
        Keyboard.press(218);
      else
        Keyboard.release(218);
    }
    
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
