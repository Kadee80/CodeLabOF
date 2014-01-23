//
//  Downer.cpp
//  DogHair
//
//  Created by Katie Adee on 5/16/13.
//
//

#include "Downer.h"

downer::downer(){
    
}

downer::downer(float _x, float _y , string name){
    pos.set(_x,_y);
    img.loadImage(name);
    xoff =0;
    consumed = false;
}

void downer::update(float _speed){
    xoff = _speed;
    pos.x-=xoff ;
};

void downer::display(){
    img.draw(pos.x+xoff,pos.y);
};