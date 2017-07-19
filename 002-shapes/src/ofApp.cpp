#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fontName = "FiraCode-Bold.ttf";
    helloWorld = "Hello World";

	fontLoader.load(fontName, 32);

    // .allocate(256, 256, OF_IMAGE_COLOR_ALPHA);
    image.load("of_inverted.png");
	// blendMode = OF_BLENDMODE_ALPHA;
    //
    // for(int i=0; i<5; i++) {
    //     points.push_back(ofVec3f(
    //         int(ofRandom(ofGetWidth())),
    //         int(ofRandom(ofGetHeight())),
    //         ofRandom(90)
    //     ));
    // }
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255,255,255);
    ofSetColor(80,80,80);
    fontLoader.drawString(helloWorld,
        ofGetWidth() / 2 - int(fontLoader.stringWidth(helloWorld)) / 2,
        ofGetHeight() / 2 - int(fontLoader.stringHeight(helloWorld)) / 2
    );

	ofSetColor(255,255,255);

    int size = points.size();
    for ( int i=0; i < size; i+=2 ) {
        // ofPushMatrix();
            // ofTranslate(points[i].x, points[i].y);
            // float deg = points[i].z;
            // ofRotate(deg);
            // ofRotateX(deg);
            // ofRotateY(deg);
            // ofRotateZ(deg);
            // ofScale(ofRandom(1), ofRandom(1));
            // image.draw(points[i].x - 25, points[i].y - 25, 50,50);
        // ofPopMatrix();
    }

    ofBackground(255);
    ofPushMatrix();
        // Original rectangle in blue
        ofSetColor(0, 0, 255);
        ofDrawRectangle(500, 200, 200, 200);

        // Rotated rectangle in red
        ofRotate(45);
        ofSetColor(255, 0, 0);
        ofDrawRectangle(500, 200, 200, 200);
    ofPopMatrix();

}

void ofApp::mouseMoved(int x, int y ){
    // x += int(ofRandom(100));
    // y += int(ofRandom(100));
    float deg = ofRandom(360);
    ofVec2f mousePoint(x,y);
    // mousePoint.rotate(deg);
    points.push_back(mousePoint);
}


