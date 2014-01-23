//
//  gameScreen.h



#ifndef __CodeLab08_ObjectsPart2__gameScreen__
#define __CodeLab08_ObjectsPart2__gameScreen__

#include <iostream>
#include "screen.h"
#include "ofxSpriteSheetRenderer.h"
#include "Platform.h"
#include "Upper.h"
#include "Downer.h"
#include "Cloud.h"

#define LEVEL_WIDTH 513
#define LEVEL_HEIGHT 1

//create a new animation. This could be done optinally in your code andnot as a static, just by saying animation_t walkAnimation; walkAnimation.index =0, walkAnimation.frame=0 etc. I find this method the easiest though
static animation_t walkAnimation =
{	0,	/* .index			(int) - this is the index of the first animation frame. indicies start at 0 and go left to right, top to bottom by tileWidth on the spriteSheet		*/
	0,	/* .frame			(int) - this is the current frame. It's an internal variable and should always be set to 0 at init													*/
	4,	/* .totalframes		(int) - the animation length in frames																												*/
	1,	/* .width			(int) - the width of each animation frame in tiles																									*/
	1,	/* .height			(int) - the height of each animation frame in tiles																									*/
	150,	/* .frameduration	(unsigned int) - how many milliseconds each frame should be on screen. Less = faster																*/
	0,	/* .nexttick		(unsigned int) - the next time the frame should change. based on frame duration. This is an internal variable and should always be set to 0 at init	*/
	-1,	/* .loops			(int) - the number of loops to run. -1 equals infinite. This can be adjusted at runtime to pause animations, etc.									*/
	-1,	/* .finalindex		(int) - the index of the final tile to draw when the animation finishes. -1 is the default so total_frames-1 will be the last frame.				*/
	1	/* .frameskip		(int) - the incrementation of each frame. 1 should be set by default. If you wanted the animation to play backwards you could set this to -1, etc.	*/
};

class gameScreen: public screen{
    
public:
    gameScreen();
    
    void setup();
    void update();
    void draw();
    void mousePressed();
    
    void applyForce(ofVec2f force);
    void checkEdges();
    void loadLevel(string _f);
    
    float myDist(ofPoint p1, ofPoint p2);
    
    
    ofxSpriteSheetRenderer * spriteRenderer;	// our spriteRenderer
    ofPoint pos; //position
    animation_t anim;
    
    vector<platform> platVec;
    vector<upper> cafVec;
    vector<downer> beerVec;
    vector<cloud> cloudVec;
    
    ofPoint loc;
    ofVec2f vel, acc, f, gravity, jump, dir, momentum;
    float mass;
    float jheight;
    float speed;
    float score;
    float count;
    
};

#endif /* defined(__CodeLab08_ObjectsPart2__gameScreen__) */
