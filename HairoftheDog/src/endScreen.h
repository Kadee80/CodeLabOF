//
//  endScreen.h
//  DogHair
//
//  Created by Katie Adee on 5/17/13.
//
//

#ifndef __DogHair__endScreen__
#define __DogHair__endScreen__

#include <iostream>
#include "screen.h"

class endScreen: public screen{
    
public:
    endScreen();
    
    void setup();
    void update();
    void draw();
    
    void mousePressed();
    ofImage img;
};

#endif /* defined(__DogHair__endScreen__) */
