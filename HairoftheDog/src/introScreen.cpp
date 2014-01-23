//
//  introScreen.cpp
//  CodeLab08_ObjectsPart2
//
//  Created by Matthew Parker on 4/1/13.
//
//

#include "introScreen.h"
#include "testApp.h"

introScreen::introScreen(): screen(100, 100, 200, "Blue Intro"){

}

void introScreen::setup(){
    screen::setup();
    img.loadImage("start.png");
}

void introScreen::update(){

}

void introScreen::draw(){
    img.draw(0,0);
}

void introScreen::mousePressed(){
    //ofLog(OF_LOG_ERROR, "THE MOUSE WAS PRESSED");
    
    testApp* app = (testApp*)ofGetAppPtr();
    app->currentScreen = &app->game;
    
    app->currentScreen->setup();
}