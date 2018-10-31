#include "ofApp.h"

#include "duck.h"

duck::duck()
{

    px = ofGetWidth()/2;
    py = ofGetHeight()/2;
    
    ax = -0.09;
    ay = -0.09;
    
    topSpeed = 20;
    vx= topSpeed;
    vy= topSpeed;
    
    dx= 1;
    dy= -1;
    

    
    c = ofColor::fromHsb(ofRandom(255),255, 255);
    
    
}
duck::~duck(){
    
}
void duck:: setup()
{
 
    

}
void duck:: update()
{
    //velocity decreases with acc
    if(vx>0)
    {
        vx+= ax;
    }
    //update posiiton with velocity
    px += vx * dx;
    py += vy * dy;
    //check our walls
    if (px < 200)
    {
        px = 200;
        dx *= -1;
        vx = topSpeed;
        vy = topSpeed -3;
    }
    if (px>ofGetWidth()/4) //right wall
    {
        px = ofGetWidth() ;
        dx *= -1;
        vx = topSpeed;
        vy = topSpeed -3;
        
    }
    if (py< 100) //top wall
    {
        py = 100;
        dy *= -1;
        vx= topSpeed-3;
        vy= topSpeed;
    }
    if (py> ofGetHeight()/4 ) //bottom wall
    {
        py = ofGetHeight() ;
        dy*= -1;
        vx= topSpeed -3;
        vy= topSpeed;
        
    }
    
    if (vy>0)
    {
        vy += ay;
    }
}

void duck:: draw()
{

    ofFill();
    float hue = ofRandom(255);
    ofSetColor(ofColor::fromHsb(hue,180,255)); //value of saturation and brightness are till 255
    int size = ofRandom(10,500);
    img1.draw(px, py,size,size);
    img2.draw(400, 450,size,size);
    
    
    
    
}

