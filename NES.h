//
//  NES.h
//  
//
//  Created by Francisco Javier García Gutiérrez on 22/12/14.
//
//

#include <Arduino.h>
#ifndef _NES_h
#define _NES_h

class NES{
    
public:
    
    NES();
    NES(int _Q5,int _PL,int _CP,int _tp);
    
    void update();
    
    bool A();
    bool B();
    bool Select();
    bool Start();
    bool Up();
    bool Down();
    bool Left();
    bool Right();
    bool Btn(int _btn);
    
    bool A_changed();
    bool B_changed();
    bool Select_changed();
    bool Start_changed();
    bool Up_changed();
    bool Down_changed();
    bool Left_changed();
    bool Right_changed();
    
private:
    //Variables
    unsigned long current_time; //Current time
    unsigned long last_time;    //Time saved
    bool btn[8];                //Buttons from the gamepad
    bool btp[8];                //Buttons from the gamepad
    bool latch;                 //Is it the clock is in high state?
    int  count;                 //Current count of the 8 buttons
    //Constants
    int Q5;             //Serial output of the 4021 IC
    int PL;             //Parallel load input of the 4021 IC
    int CP;             //Clock input of the 4021 IC
    int tp;             //Period of the clock signal
};

#endif