#pragma once
#include "ofMain.h"
//#include "<vector>"
class Walker
{
public:
	Walker();
	~Walker();

	struct point {
		ofPoint p;
		ofColor c;
		int r;
	};

	vector<point> points;

	void setup();
	void update();
	void draw();
};

