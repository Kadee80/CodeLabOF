//
//  endScreen.cpp
//  DogHair
//
//  Created by Katie Adee on 5/17/13.
//
//

#include "endScreen.h"
#include "testApp.h"

endScreen::endScreen(): screen(100, 100, 200, "Blue Intro"){
    
}

void endScreen::setup(){
    screen::setup();
    img.loadImage("end.png");
}

void endScreen::update(){
    
}

void endScreen::draw(){
    img.draw(0,0);
}

void endScreen::mousePressed(){
    //ofLog(OF_LOG_ERROR, "THE MOUSE WAS PRESSED");
    
    testApp* app = (testApp*)ofGetAppPtr();
    app->currentScreen = &app->intro;
    
    app->currentScreen->setup();
}