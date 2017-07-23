#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void exit();;

    ofParameter<int> gridDiv;
    ofParameter<int> circleRadius;

    ofxPanel gui;
};

