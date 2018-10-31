#pragma once

#include "ofMain.h"
#include "duck.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    ofImage img1;
    ofImage img2;
    
    std::vector<duck> ducks;
    
    const int NUM_duck = 5;
    
    float xPos = ofGetWidth()/2;
    float xSpeed = 0.5;// our variable for speed
    int xDirection = 1; //our variable for direction
    
    //make variables to change the y pos of our "BALL"
    float yPos = 450; //this is the y position
    float ySpeed = 0.4;// this is the spped on the y axis
    int yDirection = 1;//this is the direction on the y axis

};
