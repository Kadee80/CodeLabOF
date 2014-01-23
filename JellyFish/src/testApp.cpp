#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ncX = 0;
    ncY =ofGetHeight()/2;
    sx= 0;
    sy =0;
    x = 100;
    y=100;
    
    //set initial values in the arrays
    for (int i =0; i<20; i++){
        xpositions[i] = (int)ofRandom(ofGetWidth());
        ypositions[i] = (int)ofRandom(ofGetHeight());
        //make sure i am getting good coordinates
        ofLog(OF_LOG_ERROR, "dot" + ofToString(i) + "=" + ofToString(ypositions[i])+"," +ofToString(ypositions[i]));
        noffset[i] = ofRandom(1000);
    }
    ofBackground(0,15,85);
    //ofSetBackgroundAuto(false);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
//    //single noise
//    ncX +=.05;
//    if(ncX> ofGetWidth()){
//        ncX =0;
//    }
//    ncY = ofNoise(ncX/100)*800;
    
    //array test
    for (int i =0; i <20; i++){
        xpositions[i] = xpositions[i]+.01;
        if (xpositions[i] > ofGetWidth()){
            xpositions [i] = 0;
        }
        
        ypositions[i] = ofNoise(/*noffset[i] + */xpositions[i]/50)*700;
    }
    
    //fish along sin curve
    
    if (sx > ofGetWidth()) {
        sx=0;
    }
    sx += 0.05;
    sy = ofGetWidth()/3 + sin(sx/50.0)*100;
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
//    //one circle noise
//    ofSetColor(255);
//    ofCircle(ncX,ncY,20);
    
    ofSetColor(150, 150, 240);
    for (int i=01;i<ofGetWidth()+50;  i+=50) {
        ofCircle(x+i-100, 30, 50);
    }
    
    //array test
    
    for (int i = 0; i <20; i++){

        //Head
        ofSetColor(30, 250, 180);
        ofRect(xpositions[i]+10, ypositions[i], 6, 2);
        ofRect(xpositions[i]+5, ypositions[i]+2, 16, 2);
        ofRect(xpositions[i]+3, ypositions[i]+4, 20, 2);
        ofRect(xpositions[i], ypositions[i]+6, 26, 8);
        ofRect(xpositions[i]+3, ypositions[i]+14, 20, 4);
        //Tentacles
        ofRect(xpositions[i]+1, ypositions[i]+18, 2, 4);
        ofRect(xpositions[i]+3, ypositions[i]+22, 2, 2);
        ofRect(xpositions[i]+1, ypositions[i]+24, 2, 4);
        ofRect(xpositions[i]+3, ypositions[i]+28, 2, 4);
        ofRect(xpositions[i]+1, ypositions[i]+32, 2, 6);
        //
        ofRect(xpositions[i]+7, ypositions[i]+18, 2, 6);
        ofRect(xpositions[i]+9, ypositions[i]+24, 2, 4);
        ofRect(xpositions[i]+7, ypositions[i]+28, 2, 6);
        ofRect(xpositions[i]+9, ypositions[i]+34, 2, 6);
        //
        ofRect(xpositions[i]+13, ypositions[i]+18, 2, 12);
        ofRect(xpositions[i]+11, ypositions[i]+30, 2, 2);
        ofRect(xpositions[i]+13, ypositions[i]+32, 2, 10);
        //
        ofRect(xpositions[i]+19, ypositions[i]+18, 2, 4);
        ofRect(xpositions[i]+17, ypositions[i]+22, 2, 6);
        ofRect(xpositions[i]+19, ypositions[i]+28, 2, 4);
        ofRect(xpositions[i]+17, ypositions[i]+32, 2, 6);
        //
        ofRect(xpositions[i]+23, ypositions[i]+18, 2, 6);
        ofRect(xpositions[i]+21, ypositions[i]+24, 2, 2);
        ofRect(xpositions[i]+23, ypositions[i]+26, 2, 8);
        ofRect(xpositions[i]+21, ypositions[i]+34, 2, 6);
        //Eypositions[i]ES
        ofSetColor(100);
        ofRect(xpositions[i]+7, ypositions[i]+5, 4, 4);
        ofRect(xpositions[i]+16, ypositions[i]+5, 4, 4);
        //
        ofSetColor(255);
        ofRect(xpositions[i]+9, ypositions[i]+7, 2, 2);
        ofRect(xpositions[i]+18, ypositions[i]+7, 2, 2);
        //MOUTH
        ofRect(xpositions[i]+7, ypositions[i]+12, 2, 2);
        ofRect(xpositions[i]+9, ypositions[i]+14, 10, 2);
        ofRect(xpositions[i]+19, ypositions[i]+12, 2, 2);

    }
    
    //goldfish
    ofSetColor(255,150,0);
    ofRect(sx, sy, 2,16);
    ofRect(sx+2, sy+2, 2, 12);
    ofRect(sx+4, sy+5, 24, 6);
    ofRect(sx+6, sy+3, 20, 10);
    ofRect(sx+8, sy+1, 16, 14);
    ofRect(sx+12, sy, 9, 16);
    //
    ofSetColor(50);
    ofRect(sx+22, sy+6, 2, 2);
    ofRect(sx+20, sy+10, 2, 2);
    ofRect(sx+22, sy+12, 4, 2);
    
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