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
    // ofSetColor(255);  // Set the drawing color to white

    // // Draw some shapes
    // ofDrawRectangle(50, 50, 100, 100); // Top left corner at (50, 50), 100 wide x 100 high
    // ofDrawCircle(250, 100, 50); // Centered at (250, 100), radius of 50
    // ofDrawEllipse(400, 100, 80, 100); // Centered at (400 100), 80 wide x 100 high
    // ofDrawTriangle(500, 150, 550, 50, 600, 150); // Three corners: (500, 150), (550, 50), (600, 150)
    // ofDrawLine(700, 50, 700, 150); // Line from (700, 50) to (700, 150)

    // ofFill(); // If we omit this and leave ofNoFill(), all the shapes will be outlines!
    // Draw some shapes (code omitted)

    // ofNoFill();

    // basic mouse brush
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {  // If the left mouse button is pressed...
        // ofSetColor(255);
        // float randomColor = ofRandom(50, 255);
        // ofSetColor(randomColor);
        // ofSetRectMode(OF_RECTMODE_CENTER);
        // ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 50, 50);  // Draw a 50 x 50 rect centered over the mouse
        // ofSetRectMode(OF_RECTMODE_CENTER);
        int numRects = 10;
        for (int r=0; r<numRects; r++) {
             ofSetColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255));
            float width = ofRandom(5, 20);
            float height = ofRandom(5, 20);
            float distance = ofRandom(35);

            // Formula for converting from polar to Cartesian coordinates:
            //  x = cos(polar angle) * (polar distance)
            //  y = sin(polar angle) * (polar distance)

            // We need our angle to be in radians if we want to use sin() or cos()
            // so we can make use of an openFrameworks function to convert from degrees
            // to radians
            float angle = ofRandom(ofDegToRad(360.0));

            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;
            ofDrawRectangle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, width, height);
            // ofSetColor(ofRandom(50, 255));
            // float width = ofRandom(5, 20);
            // float height = ofRandom(5, 20);
            // float xOffset = ofRandom(-40, 40);
            // float yOffset = ofRandom(-40, 40);
            // ofDrawRectangle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, width, height);
        }
    }
}

void ofApp::mouseMoved(int x, int y ){
}


