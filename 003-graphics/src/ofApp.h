#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
        void mouseMoved(int x, int y );

        vector<ofVec2f > points;
        vector<ofVec2f > sizes;
        vector<ofVec3f > colors;
};

