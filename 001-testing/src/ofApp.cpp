#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fontName = "FiraCode-Bold.ttf";
    helloWorld = "Hello World";

	fontLoader.load(fontName, 32);

    // .allocate(256, 256, OF_IMAGE_COLOR_ALPHA);
    image.load("of_inverted.png");
	// blendMode = OF_BLENDMODE_ALPHA;
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255,255,255);
    ofSetColor(80,80,80);
    fontLoader.drawString(helloWorld,
        ofGetWindowWidth() / 2 - int(fontLoader.stringWidth(helloWorld)) / 2,
        ofGetWindowHeight() / 2 - int(fontLoader.stringHeight(helloWorld)) / 2
    );

	ofSetColor(255,255,255);
    image.draw(mouseX, mouseY);
}


