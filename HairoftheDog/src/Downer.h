//
//  Downer.h
//  DogHair
//
//  Created by Katie Adee on 5/16/13.
//
//

#ifndef __DogHair__Downer__
#define __DogHair__Downer__

#include <iostream>
#include "ofMain.h"

class downer{
public:
    ofPoint pos;
    ofImage img;
    float xoff;
    bool consumed;
    
    downer();
    downer(float _x, float _y , string name);
    
    void update(float _speed);
    void display();
    
    
};

#endif /* defined(__DogHair__Downer__) */
