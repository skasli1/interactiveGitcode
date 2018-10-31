#pragma once

#include "ofMain.h"

class duck {
public:
    duck(); //constructor
    ~duck(); //destructor
    
    void setup ();
    
    void update();
    
    
    void draw();
    
    
    
    //has position
    float px;
    float py;
    
    //has velocity
    float vx;
    float vy;
    
    //has acceleration
    float ax;
    float ay;
    
    //duck has a direction
    int dx;
    int dy;
    
    //a top speed
    float topSpeed;
    
    //has a size
    int radius;
    
    //has a color
    ofColor c;
    float hue;
    
    float size;
    ofImage img1;
    ofImage img2;

    
};
