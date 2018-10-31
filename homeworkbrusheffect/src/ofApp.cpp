#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img1.load("img1.png");
    img2.load("img2.png");
     img3.load("img3.png");
    ofSetRectMode(OF_RECTMODE_CENTER); //set in center of screen
    ofBackground(ofColor::black);
    ofSetBackgroundAuto(false); //redraws background once and never again
    


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int border (20);
   
        //third image
        if(ofGetMousePressed()) // or if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
        {
            // int size = 400;
            float hue = ofRandom(255);
            ofSetColor(ofColor::fromHsb(hue,180,255)); //value of saturation and brightness are till 255
            int size = ofRandom(100,1000);
            img3.draw(ofGetMouseX(), ofGetMouseY(),size,size);
            //img3.draw(ofGetWidth()/2, ofGetHeight()/2,size,size);
            
//            if(ofGetMousePressed()) // or if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
//            {
//                // int size = 400;
//                float hue = ofRandom(255);
//                ofSetColor(ofColor::fromHsb(hue,180,255)); //value of saturation and brightness are till 255
//                int size = ofRandom(10,500);
//                img1.draw(ofGetMouseX(), 300,size,size);
//                //img1.draw(ofGetWidth()/2, ofGetHeight()/2,size,size);
//            }
            //second image
            if(ofGetMousePressed()) // or if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT))
            {
                // int size = 400;
                float hue = ofRandom(255);
                ofSetColor(ofColor::fromHsb(hue,180,255)); //value of saturation and brightness are till 255
                int size = ofRandom(50,700);
                img2.draw(ofGetMouseX(), ofGetMouseY(),size,size);
                //img2.draw(ofGetWidth()/2, ofGetHeight()/2,size,size);
            }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' ')
    {
        ofColor c = ofColor::fromHsb(ofRandom(255), 180,255);
        //ofClear(ofColor::salmon); //if space is pressed the screen will clear
        ofClear(c);
        
    }
    if (key == 's');
    {
        ofSaveScreen("screenShot_"+ofGetTimestampString()+".png");
        std::cout<<"Screen Saved! Good Work!"<<std::endl;
        
    }
    if (key == 'r');
    {
        ofSetColor(ofColor::red);
        int size = ofRandom(500,1000);
        
//         img1.draw(ofGetMouseX(), 300,size,size);
         img3.draw(ofGetMouseX(), ofGetMouseY(),size,size);
         img2.draw(800, ofGetMouseY(),size,size);
    }
    
}

