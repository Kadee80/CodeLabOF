//
//  Platform.cpp
//  LevelEditor
//
//  Created by Katie Adee on 5/15/13.
//
//

#include "Platform.h"



platform::platform(){
    
}

platform::platform(float _x, float _y , string name){
    pos.set(_x,_y);
    img.loadImage(name);
    xoff =0;
}

void platform::update(float _speed){
        xoff = _speed;
        pos.x-=xoff ;
};

void platform::display(){
   img.draw(pos.x+xoff,pos.y);
};