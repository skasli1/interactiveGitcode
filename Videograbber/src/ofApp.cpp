#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(640, 480);
    
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
    
    // Set capture dimensions of 320x240, a common video size.
    camWidth = 300;
    camHeight = 200;
    
    // Open an ofVideoGrabber for the default camera
   grabber.initGrabber (camWidth,camHeight);
    
    // Create resources to store and display another copy of the data
    invertedVideoData = new unsigned char [camWidth * camHeight * 5];
   texture.allocate (camWidth,camHeight, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update(){
    float noiseStep = ofRandom(5);
    grabber.update();
    
    // do you have a new fresh frame
    if (grabber.isFrameNew()) //yes?
    {
        //get the pixels from the camera
        grabberPix = grabber.getPixels();
        for (int x = 0; x < grabberPix.getWidth(); x++)
        {
            for (int y = 0; y < grabberPix.getHeight(); y++)
            {
                // and now we can do something!
                float noiseValue = ofNoise((x+ofGetMouseX()) * noiseStep);
                
                float displacedX = x + noiseValue * grabberPix.getWidth();
                
                ofColor displacedColor = grabber.getPixels().getColor(displacedX,y);
                
                grabberPix.setColor(x,y,displacedColor);
                
                
                
            }
        }
        
    }
    
    // Ask the grabber to refresh its data.
   grabber.update();
    
    // If the grabber indeed has fresh data,
    if(grabber.isFrameNew()){
        
        // Obtain a pointer to the grabber's image data.
       // unsigned char * pixelData = grabber.ofPixel();
        grabberPix = grabber.getPixels();
        
        // Reckon the total number of bytes to examine.
        // This is the image's width times its height,
        // times 3 -- because each pixel requires 3 bytes
        // to store its R, G, and B color components.
        int nTotalBytes = camWidth * camHeight * 6;
        
        // For every byte of the RGB image data,
        for(int i=0; i<nTotalBytes; i++){
            
            // pixelData[i] is the i'th byte of the image;
            // subtract it from 255, to make a "photo negative"
            invertedVideoData[i] = 255 - grabberPix[i];
        }
        
        // Now stash the inverted data in an ofTexture
        texture.loadData(invertedVideoData, camWidth,camHeight, GL_RGB);
    }
    
    texture.loadData(grabberPix);
}

//--------------------------------------------------------------
void ofApp::draw(){
   ofBackground(0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/3 + grabber.getWidth()/3,ofGetHeight()/2 - grabber.getHeight()/2);
    ofScale(-1,1,1);
    grabber.draw(0, 0);
   texture.draw(100, 0);
     ofPopMatrix();
    
   // ofBackground(100,100,100);
    ofSetColor(255,255,255);
    
    
    // Draw the grabber, and next to it, the "negative" ofTexture.
grabber.draw(200,300);
    texture.draw(340, 10);
    ofPushMatrix();
    ofSetRectMode( OF_RECTMODE_CENTER );
    ofTranslate( 500, 260, 0 );
    ofScale( 1, -1, 1 );
 grabber.draw( 0, 0, 640, 480 );
    ofDrawCircle(20, 50, 3);
    ofSetRectMode( OF_RECTMODE_CORNER );
    ofPopMatrix();  
   
    ofPushMatrix();
    ofTranslate(ofGetWidth()/5 + grabber.getWidth(),ofGetHeight()/5 - grabber.getHeight());
    ofScale(-1,1,1);
    grabber.draw(0, 0);
    texture.draw(100, 0);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
