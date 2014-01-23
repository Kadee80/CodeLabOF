//
//  gameScreen.cpp
//
//

#include "gameScreen.h"
#include "Platform.h"
#include "ofxSpriteSheetRenderer.h"
#include "testApp.h"


gameScreen::gameScreen(): screen(255, 0, 0, "Level 1"){
    
}

void gameScreen::setup(){
    screen::setup();
    loadLevel("cloud.txt");
    loadLevel("level.txt");
    
    ofBackground(50,125,255);
    ofSetFrameRate(60);
    score = ofGetElapsedTimeMillis()/100;
    
    
    //character stuff
    
    jheight = -20;
    
    loc.set(ofGetWidth()/2, ofGetHeight()/2);
    
    dir.set(23,7);
    dir.normalize();
    
    vel.set(0,0);
    acc.set(0,0);
    
    gravity.set(0, 1);
    momentum.set(0,0);
    jump.set(0,jheight);
    
    //sprites
    anim = walkAnimation;
    spriteRenderer = new ofxSpriteSheetRenderer(2, 200, 0, 64);
    spriteRenderer->loadTexture("KateSprite.png", 512, GL_NEAREST);
    
    //platform speed variable
    speed =3.5;
    count=0;

    
}

void gameScreen::update(){
    checkEdges();
    applyForce(gravity);
    //only jump if you are standing on ground
    
    for (int i=0; i< platVec.size(); i++){
        if (loc.x > platVec[i].pos.x & loc.x<platVec[i].pos.x+50){
            if (loc.y == platVec[i].pos.y-48) {
                jump.set(0,jheight);
                if(ofGetKeyPressed(32)){
                    applyForce(jump);
                    vel.limit(50);
                }
                if (loc.y < platVec[i].pos.y-60) {
                    speed = 0;
                }
                
                
            }
            
        }
        //stop the platform movement when you hit the end
        if (platVec[platVec.size()-1].pos.x <= 50+ofGetWidth()/2){
            platVec[i].xoff=0;
            speed =0;
            count++;
            if(count ==50){
            testApp* app = (testApp*)ofGetAppPtr();
            app->currentScreen = &app->end;
            app->currentScreen->setup();
            }
        }
        
    }
    //remove  coffee when consumed
    for (int i=0; i< cafVec.size(); i++){
        if(myDist(loc, cafVec[i].pos)<35){
            speed = speed+.5;
            cafVec[i].consumed = true;
            cafVec.erase (cafVec.begin()+i);
        }
    }
    //remove  beer when consumed
    for (int i=0; i< beerVec.size(); i++){
        if(myDist(loc, beerVec[i].pos)<30){
            speed = speed-.5;
            beerVec[i].consumed = true;
            beerVec.erase (beerVec.begin()+i);
        }
    }
    
    
    loc+=vel;
    vel+=acc;
    acc.set(0,0);
    
    //friction
    vel*=.95;
    
    
    spriteRenderer->clear(); // clear the sheet
	spriteRenderer->update(ofGetElapsedTimeMillis()); //update the time in the renderer, this is necessary for animations to advance
    
    //link pos to me sprite
    spriteRenderer->addCenteredTile(&anim, loc.x, loc.y); // add them to the sprite renderer (add their animation at their position, there are a lot more options for what could happen here, scale, tint, rotation, etc, but the animation, x and y are the only variables that are required)
}

void gameScreen::draw(){
    ofColor DarkBlue(20,25,142);
    ofColor LightBlue(50,125,255);
    ofBackgroundGradient(LightBlue,DarkBlue,OF_GRADIENT_LINEAR);
    score = ofGetElapsedTimeMillis()/100;
    ofSetColor(255);
    //ofDrawBitmapString("Score = " +ofToString(score), ofGetWidth()-100,20);
    
    //draw cloud
    for (int i=0; i< cloudVec.size(); i++){
        cloudVec[i].display();
        cloudVec[i].update(speed);
    }
    //draw platforms
    for (int i=0; i< platVec.size(); i++){
        platVec[i].display();
        platVec[i].update(speed);
        //cout <<  platVec.size() <<endl;
        
    }
    //draw coffee
    for (int i=0; i< cafVec.size(); i++){
            cafVec[i].display();
            cafVec[i].update(speed);
    }
    //draw booze
    for (int i=0; i< beerVec.size(); i++){
        beerVec[i].display();
        beerVec[i].update(speed);
    }

    spriteRenderer->draw(); //draw me
    
}

void gameScreen::mousePressed(){
    
}

//-----------------------------------------------------
void gameScreen::checkEdges(){
    for (int i=0; i< platVec.size(); i++){
        if (loc.x > platVec[i].pos.x & loc.x<platVec[i].pos.x+55){
            if (loc.y > platVec[i].pos.y-48){
                //.8 is damping
                acc.y*= -.8;
                loc.y = platVec[i].pos.y-48;
                
            }
            
        }
    }
    if(loc.y > ofGetHeight()-150){
        speed = 0;
        
        count++;
        if(count ==50){
            cafVec.resize(0);
            beerVec.resize(0);
            platVec.resize(0);
            cloudVec.resize(0);

                testApp* app = (testApp*)ofGetAppPtr();
                app->currentScreen = &app->intro;
                app->currentScreen->setup();
        }
        
    }
}
//-----------------------------------------------------
void gameScreen::applyForce(ofVec2f force){
    f.set(force/mass);
    acc+=f;
}

//-----------------------------------------------------
void gameScreen::loadLevel(string _f){
    
    
    ofFile level = ofFile(_f, ofFile::ReadOnly);
    
    string line;
    
    for(int y = 0; y < LEVEL_HEIGHT; y++){
        level >> line;
        
        for(int x = 0; x < LEVEL_WIDTH; x++){
            char c = line.at(x);
            
            if(c == 'C'){
                cafVec.push_back(upper(x*50,200,"coffee.png"));
            }
            if(c == 'c'){
                cafVec.push_back(upper(x*50,250,"coffee.png"));
            }
            
            //top platform
            if(c == 'q'){
                platVec.push_back(platform(x*50, 300, "platLF.png"));
            }
            if(c == 'o'){
                platVec.push_back(platform(x*50, 300, "platM.png"));
            }
            if(c == 'p'){
                platVec.push_back(platform(x*50, 300, "platRT.png"));
            }
            
            //middle platform
            if(c == 'L'){
                platVec.push_back(platform(x*50, 350, "platLF.png"));
            }
            if(c == 'X'){
                platVec.push_back(platform(x*50, 350, "platM.png"));
            }
            if(c == 'R'){
                platVec.push_back(platform(x*50, 350, "platRT.png"));
            }
           
            if(c == 'B'){
                platVec.push_back(platform(x*50, 350, "platM.png"));
                beerVec.push_back(downer(x*50,310,"beer.png"));
            }
            //lower platform
            if(c == 'l'){
                platVec.push_back(platform(x*50, 400, "platLF.png"));
            }
            if(c == 'x'){
                platVec.push_back(platform(x*50, 400, "platM.png"));
            }

            if(c == 'r'){
                platVec.push_back(platform(x*50, 400, "platRT.png"));
            }
            
            if(c == 'b'){
                platVec.push_back(platform(x*50, 400, "platM.png"));
                beerVec.push_back(downer(x*50,360,"beer.png"));
            }
            if(c == 't'){
                platVec.push_back(platform(x*50, 400, "platM.png"));
                beerVec.push_back(downer(x*50,360,"beer.png"));
                cafVec.push_back(upper(x*50,230,"coffee.png"));
            }
            
            if(c == 'U'){
                cloudVec.push_back(cloud(x*160,50,"cloud.png"));
            }
            if(c == 'u'){
                cloudVec.push_back(cloud(x*160,125,"cloud.png"));
            }
            
            
            else {
                // do nothing
            }
        }
        
        
    }
    
    
    level.close();
}

//--------------------------------------------------------------
float gameScreen::myDist(ofPoint p1, ofPoint p2){
    return ofDist(p1.x, p1.y, p2.x, p2.y);
}

//--------------------------------------------------------------
