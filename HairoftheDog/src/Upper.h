//
//  Upper.h
//  DogHair
//
//  Created by Katie Adee on 5/16/13.
//
//

#ifndef __DogHair__Upper__
#define __DogHair__Upper__

#include <iostream>
#include "ofMain.h"

class upper{
public:
    ofPoint pos;
    ofImage img;
    float xoff;
    bool consumed;
    
    upper();
    upper(float _x, float _y , string name);
    
    void update(float _speed);
    void display();
    
    
};


#endif /* defined(__DogHair__Upper__) */
