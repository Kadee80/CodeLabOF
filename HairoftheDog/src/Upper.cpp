//
//  Upper.cpp
//  DogHair
//
//  Created by Katie Adee on 5/16/13.
//
//

#include "Upper.h"

upper::upper(){
    
}

upper::upper(float _x, float _y , string name){
    pos.set(_x,_y);
    img.loadImage(name);
    xoff =0;
    consumed = false;
}

void upper::update(float _speed){
    xoff = _speed;
    pos.x-=xoff ;
};

void upper::display(){
    img.draw(pos.x+xoff,pos.y);
};