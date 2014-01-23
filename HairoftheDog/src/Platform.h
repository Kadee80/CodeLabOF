//
//  Platform.h
//  LevelEditor
//
//  Created by Katie Adee on 5/15/13.
//
//

#ifndef __LevelEditor__Platform__
#define __LevelEditor__Platform__

#include <iostream>
#include "ofMain.h"


class platform{
    
public:
    ofImage platforms[3];
    ofPoint pos;
    float xoff;
    ofImage img;
    
    platform();
    platform(float _x, float _y , string name);
    
    void update(float _speed);
    void display();
    
};


#endif /* defined(__LevelEditor__Platform__) */
