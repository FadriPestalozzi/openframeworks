//
//  particle.hpp
//  particleSystem
//
//  Created by Fadri Pestalozzi on 22/01/23.
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>

#endif /* particle_hpp */


#include "ofMain.h"


class particle{
public:
    particle();
    
    void setup();
    void update(float speed, float noise);
    void draw(float sizeDot);
    void repel(vector<ofVec2f>repelPt);
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofVec2f repelFrc;
    float drag;
    
    
    ofVec2f uniqueVal;
    float size;
    
};

