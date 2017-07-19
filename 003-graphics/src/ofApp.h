#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
        void mouseMoved(int x, int y );

        ofImage image;
		ofTrueTypeFont 	fontLoader;
        string helloWorld;
        string fontName;

        vector<ofVec2f > points;
};

