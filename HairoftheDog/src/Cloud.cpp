//
//  Cloud.cpp
//  DogHair
//
//  Created by Katie Adee on 5/17/13.
//
//

#include "Cloud.h"

cloud::cloud(){
    
}

cloud::cloud(float _x, float _y , string name){
    pos.set(_x,_y);
    img.loadImage(name);
    xoff =0;
}

void cloud::update(float _speed){
    xoff = _speed/2;
    pos.x-=xoff ;
};

void cloud::display(){
    img.draw(pos.x+xoff,pos.y);
};