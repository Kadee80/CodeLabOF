//
//  screen.h
//  CodeLab08_ObjectsPart2
//
//  Created by Matthew Parker on 4/1/13.
//
//

#ifndef __CodeLab08_ObjectsPart2__screen__
#define __CodeLab08_ObjectsPart2__screen__

#include <iostream>
#include "ofMain.h"

class screen{

public:
    ofColor bgColor;
    string name;
    
    screen();
    screen(int r, int g, int b, string _name);
    
    virtual void setup();
    virtual void update();
    virtual void draw();
    
    virtual void mousePressed();
};

#endif /* defined(__CodeLab08_ObjectsPart2__screen__) */
