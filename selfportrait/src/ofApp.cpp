#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        float xPos = ofGetMouseX();
    xPos = 5;  // horizontal start position
    ofBackground(248,199,3);
    
    float yPos = ofGetMouseY();
    yPos = 5;  // horizontal start position
    ofBackground(248,199,3);
    
    
    
    
}


//--------------------------------------------------------------
void ofApp::update(){
        float xPos = ofGetMouseX();
    xPos += 2;
    if(ofGetWidth()<xPos){  // if horizontal position is off the screen (width)
        xPos = 5;             // reset horizontal position
    }
    float yPos = ofGetMouseY();
    yPos += 2;
    if(ofGetHeight()<yPos){  // if vertical position is off the screen (height)
        yPos = 5;             // reset verticall position
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float xPos = ofGetMouseX();
      float yPos = ofGetMouseY();

    ofBackground(248,199,3);
    
    //rectangle
    ofFill();
    ofSetColor(188, 141, 128);
    ofDrawRectangle(450, 280, 230, 140);
    //hair
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(400, 280, 50, 215); //side hair
    ofDrawRectangle(680, 280, 50, 215);//side hair
     ofDrawRectangle(450, 160, 230, 120);
     ofDrawTriangle(400, 280, 450, 160, 500, 280);
     ofDrawTriangle(680, 280, 680, 160, 730, 280);
    
   

    
    //triangle
    ofFill();
    ofSetColor(188, 141, 128);
    ofDrawTriangle(450, 280, 610, 190, 680, 280);
    
    //nose
    ofFill();
    ofSetColor(218, 186, 171);
    ofDrawTriangle(535, 405, 535, 320, 570, 405);
    
    //draw a circle
    ofFill();
    ofSetColor(255);
    ofDrawCircle(500, 320, 23);
    ofDrawCircle(620, 320, 23);
    ofFill();
    ofSetColor(0);
//    ofDrawCircle(505, 330, 9);
  ofDrawCircle(625, yPos, 9);
   
    ofDrawCircle(xPos, yPos, 9);   // draw a circle at the (variable) horizontal position, 100 pixels from the top with a 9 pixel diameter
    
    
//
    //chin
    ofFill();
    ofSetColor(188, 141, 128);
    ofDrawTriangle(450, 420, 523, 500, 523, 420);
    ofDrawRectangle(523, 420, 74, 80);
    ofDrawTriangle(597, 420, 597, 500, 680, 420);
    
    //mouth
    ofFill();
    ofSetColor(197,98,123);
    ofDrawRectangle(530, 425, 60, 15);
    ofDrawTriangle(590, 440, 590, 425, 610, 425);
    
    //neck
    ofFill();
    ofSetColor(188, 141, 128);
    ofDrawRectangle(518, 475, 84, 95);
    
    //body
    ofFill();
    ofSetColor(ofColor::skyBlue);
    ofDrawRectangle(463, 540, 194, 95);
     ofDrawTriangle(657, 635, 657, 540, 730, 635);
    ofDrawTriangle(463, 635, 463, 540, 390, 635);
    
   
    
    
    
    
   
}

