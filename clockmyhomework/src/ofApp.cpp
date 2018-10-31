#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
 img1.load("img1.png");
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(false); //redraws background once and never again
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    //get the minutes, seconds, hours!
    
    int seconds = ofGetSeconds();
    int minutes = ofGetMinutes();
    int hours = ofGetHours(); //hours is in 24 hour time
    
    //map these numbers to a rotation
    float sDegree = ofMap (seconds, 0, 60,0,360); //or float sRotation
    float mDegree = ofMap (minutes, 0, 60,0,360);
    float hDegree = ofMap (hours, 0,24,0,720);
    
    //get the time
   // float time = ofGetElapsedTimef();
    //set the speed of our sine wave
    float freq =0.015;
    
    for (int i = 0; i<800; i++)
    {
        
        //float sineValue = sin(sDegree*freq*i);
        float yPos = sDegree;
        // float tanValue = tan(time*freq*i);
        //map our sine numbers to the height of the screen
       // float yPos = ofMap(sineValue,-1,1,0,ofGetHeight()-600);
        //float xPos = ofMap(sineValue,-1,1,0,ofGetWidth());
    //draw some circles (about 800)
        //ofSetColor(ofColor::hotPink);
       // ofFill();
       // ofDrawCircle(i, yPos, 2);
        if(ofGetMousePressed());
        float hue = ofRandom(255);
        ofSetColor(ofColor::fromHsb(hue,0,255));
        int size = ofRandom(20,200);
       img1.draw(yPos, ofGetMouseX(),size,size);
    
}
    for (int i = 0; i<800; i++)
    {
        
        float sineValue = sin(mDegree*freq*i);
        // float tanValue = tan(time*freq*i);
        //map our sine numbers to the height of the screen
        float yPos = ofMap(sineValue,-1,1,200,ofGetHeight()-300);
        float xPos = ofMap(sineValue,-1,1,0,ofGetWidth());
        //draw some circles (about 800)
        ofSetColor(ofColor::skyBlue);
        ofFill();
        ofDrawCircle(i*2, yPos, 4);
    }
    for (int i = 0; i<800; i++)
    {
        
        float sineValue = sin(hDegree*freq*i);
        // float tanValue = tan(time*freq*i);
        //map our sine numbers to the height of the screen
        float yPos = ofMap(sineValue,-1,1,500,ofGetHeight());
        float xPos = ofMap(sineValue,-1,1,0,ofGetWidth());
        //draw some circles (about 800)
        ofSetColor(ofColor::mediumPurple);
        ofFill();
        ofDrawCircle(i*3, yPos, 6);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

