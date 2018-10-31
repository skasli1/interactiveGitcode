#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img1.load("duck.png");
    img2.load("water.png");
    ofSetRectMode(OF_RECTMODE_CENTER); //set in center of screen
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(false); //redraws background once and never again
   
   
    for (int i = 0; i<NUM_duck; i++)
    {
        duck tempduck;
        tempduck.px = ofRandom(ofGetWidth()/4);
        tempduck.py = ofRandom(ofGetHeight()/4);
        tempduck.ax = -ofRandom(0.01,0.3);
        tempduck.ay = -ofRandom(0.01,0.3);
      
        
        ducks.push_back(tempduck); //will get pushed into this vector
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < ducks.size(); i++)
    {
        
        ducks[i].update();
        
        
        //maybe add something to change/animate the radius of the ball
    }
    //xPos is GLOBAL, which means its valid everywhere in our program
    //lets incriment xPos by xSpeed every update() loop
    xPos += xSpeed * xDirection;
    
    //do the same thing for y
    yPos += ySpeed * yDirection;
    
    //if our ball reaches the edge of the screen, go in the opposite direction
    //lets check our right edge
    if (xPos > ofGetWidth())
    {
        //lets have x speed increase everytime it hits the wall
        xSpeed += 1;
        xDirection *= -1;
    }
    
    //lets check our left edge
    if (xPos < 0)
    {
        xSpeed += 1; //increase the speed
        xDirection *= -1;
    }
    //check our bottom edge
    if (yPos > ofGetHeight()/3)
    {
        yDirection *= -1;
        
    }
    //check out top edge
    if (yPos < 600)
    {
        yDirection *= -1;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < ducks.size(); i++)
    {
        ofFill();
        //float hue = ofRandom(255);
       // ofSetColor(ofColor::fromHsb(hue,180,255)); //value of saturation and brightness are till 255
        int size = ofRandom(900,900);
        img2.draw(450, 450,size,size);
    }
    
    
   for (int i = 0; i < ducks.size(); i++)
    {
        ofFill();
//        float hue = ofRandom(255);
//        ofSetColor(ofColor::fromHsb(hue,180,255)); //value of saturation and brightness are till 255
        int size = ofRandom(200,200);
        img1.draw(xPos, yPos,size,size);
        
        
      
        ducks[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
