#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
	ofEnableSmoothing();
    currentScreen = &intro;
    
    currentScreen->setup();
}

//--------------------------------------------------------------
void testApp::update(){
    currentScreen->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    currentScreen->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    currentScreen->mousePressed();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}