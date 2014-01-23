//
//  Cloud.h
//  DogHair
//
//  Created by Katie Adee on 5/17/13.
//
//

#ifndef __DogHair__Cloud__
#define __DogHair__Cloud__

#include <iostream>
#include "ofMain.h"
class cloud{
    
public:

    ofPoint pos;
    float xoff;
    ofImage img;
    
    cloud();
    cloud(float _x, float _y , string name);
    
    void update(float _speed);
    void display();
    
};

#endif /* defined(__DogHair__Cloud__) */
