//
//  NES.cpp
//  
//
//  Created by Francisco Javier García Gutiérrez on 22/12/14.
//
//

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <NES.h>

NES::NES(int _Q5,int _PL,int _CP,int _tp):Q5(_Q5),PL(_PL),CP(_CP),tp(_tp){
    
    pinMode(CP,OUTPUT);
    pinMode(PL,OUTPUT);
    pinMode(Q5,INPUT );
    
    for( int i = 0 ; i < 8 ; i++ ){
        btn[i] = 0;
        btp[i] = 0;
    }
    current_time = 0;
    last_time = 0;
    latch = false;
    count = 0;
}

void NES::update(){
    current_time = micros();
    
    if( current_time-last_time > tp/2 ){
        
        latch=!latch;
        
        if(latch){
            
            if( count++ >= 8 )
                count = 0;
            
            if( count != 0 ){
                btp[count-1] = btn[count-1];
                btn[count-1] = !digitalRead(Q5);
                digitalWrite(CP,HIGH);
            }
            else
                digitalWrite(PL,HIGH);
            
        }
        else{
            
            if( count == 0 )
                digitalWrite(PL,LOW);
            else
                digitalWrite(CP,LOW);
            
        }
        last_time = current_time;
    }
}


bool NES::A(){
    return btn[0];
}
bool NES::B(){
    return btn[1];
}
bool NES::Select(){
    return btn[2];
}
bool NES::Start(){
    return btn[3];
}
bool NES::Up(){
    return btn[4];
}
bool NES::Down(){
    return btn[5];
}
bool NES::Left(){
    return btn[6];
}
bool NES::Right(){
    return btn[7];
}
bool NES::Btn(int _btn){
    return btn[_btn];
}
bool NES::A_changed(){
    return btn[0]^btp[0];
}
bool NES::B_changed(){
    return btn[1]^btp[1];
}
bool NES::Select_changed(){
    return btn[2]^btp[2];
}
bool NES::Start_changed(){
    return btn[3]^btp[3];
}
bool NES::Up_changed(){
    return btn[4]^btp[4];
}
bool NES::Down_changed(){
    return btn[5]^btp[5];
}
bool NES::Left_changed(){
    return btn[6]^btp[6];
}
bool NES::Right_changed(){
    return btn[7]^btp[7];
}

