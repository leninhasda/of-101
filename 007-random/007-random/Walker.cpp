#include "Walker.h"

#include "ofMain.h"

Walker::Walker()
{
}


Walker::~Walker()
{
}

void Walker::setup()
{
}

void Walker::update()
{
	point p;
	
	int mx = ofGetMouseX();
	int my = ofGetMouseY();
	p.p.x = ofRandom(mx-100, mx+100);
	p.p.y = ofRandom(my-100, my+100);
	p.c = ofColor(
			ofRandom(255), // r
			ofRandom(255), // g
			ofRandom(255) // b
			,ofRandom(255)  // a
		);
	p.r = ofRandom(ofRandom(1,50));
	if (points.size() > 100) {
		points.erase(points.begin()+1);
	}
	points.push_back(p);
}

void Walker::draw()
{
	for (int I = 0, locsSize = points.size(); I < locsSize; I++) {
		point p = points[I];
		ofSetColor(p.c);
		ofDrawCircle(p.p, p.r);
	}
}
