//
//  introScreen.h
//  CodeLab08_ObjectsPart2
//
//  Created by Matthew Parker on 4/1/13.
//
//

#ifndef __CodeLab08_ObjectsPart2__introScreen__
#define __CodeLab08_ObjectsPart2__introScreen__

#include <iostream>
#include "screen.h"

class introScreen : public screen{

public:
    introScreen();
    
    void setup();
    void update();
    void draw();
    
    void mousePressed();
    ofImage img;
};

#endif /* defined(__CodeLab08_ObjectsPart2__introScreen__) */
