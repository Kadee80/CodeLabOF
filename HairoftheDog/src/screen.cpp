//
//  screen.cpp
//  CodeLab08_ObjectsPart2
//
//  Created by Matthew Parker on 4/1/13.
//
//

#include "screen.h"

screen::screen(){
}

screen::screen(int r, int g, int b, string _name){
    bgColor.set(r, g, b);
    name = _name;
}

void screen::setup(){
    ofBackground(bgColor);
}

void screen::update(){

}

void screen::draw(){

}

void screen::mousePressed(){

}