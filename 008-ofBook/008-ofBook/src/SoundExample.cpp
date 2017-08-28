#include "SoundExample.h"

void SoundExample::setup() {
	sound.loadSound("17.wav");
	sound.play();
	sound.setVolume(0.7);
}

void SoundExample::draw() {
	//float xPos = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, ofGetWidth());
	//ofRect(xPos, ofGetHeight() / 2, 10, 10);
	ofSetColor(ofColor::black);
	ofDrawBitmapString(
		"" + ofToString(sound.getPan()), 10, 50
	);
}