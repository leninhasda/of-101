#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);  // Clear the screen with a black color
    ofSetColor(255);  // Set the drawing color to white

    // Draw some shapes
    ofDrawRectangle(50, 50, 100, 100); // Top left corner at (50, 50), 100 wide x 100 high
    ofDrawCircle(250, 100, 50); // Centered at (250, 100), radius of 50
    ofDrawEllipse(400, 100, 80, 100); // Centered at (400 100), 80 wide x 100 high
    ofDrawTriangle(500, 150, 550, 50, 600, 150); // Three corners: (500, 150), (550, 50), (600, 150)
    ofDrawLine(700, 50, 700, 150); // Line from (700, 50) to (700, 150)

    ofFill(); // If we omit this and leave ofNoFill(), all the shapes will be outlines!
    // Draw some shapes (code omitted)

    ofNoFill();
}

void ofApp::mouseMoved(int x, int y ){
}


