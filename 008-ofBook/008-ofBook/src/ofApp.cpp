#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//soundExample = SoundExample();
	//soundExample.setup();

	ofSetBackgroundAuto(false); // now the draw will work like processing
	// cool :D

	ofSetFrameRate(60);
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//soundExample.draw();

	ofSetBackgroundColor(0);

	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {  // If the left mouse button is pressed...
		//float randomColor = ofRandom(50, 255);
		//ofSetColor(randomColor);
		ofSetRectMode(OF_RECTMODE_CENTER);
		//ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 50, 50);  // Draw a 50 x 50 rect centered over the mouse
		/*int numRects = 10;
		for (int r = 0; r<numRects; r++) {
			ofSetColor(ofRandom(50, 255));
			float width = ofRandom(5, 20);
			float height = ofRandom(5, 20);
			float angle = ofRandom(ofDegToRad(360.0));
			float distance = ofRandom(35);
			float xOffset = cos(angle) * distance;
			float yOffset = sin(angle) * distance;
			ofDrawRectangle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, width, height);
		}*/

		int maxRadius = 100;  // Increase for a wider brush
		int radiusStepSize = 10;  // Decrease for more circles (i.e. a more opaque brush)
		int alpha = 3;  // Increase for a more opaque brush
		int maxOffsetDistance = 100;  // Increase for a larger spread of circles
									  // draw smaller and smaller circles and layering (increasing) opaqueness
		for (int radius = maxRadius; radius>0; radius -= radiusStepSize) {
			float angle = ofRandom(ofDegToRad(360.0));
			float distance = ofRandom(maxOffsetDistance);
			float xOffset = cos(angle) * distance;
			float yOffset = sin(angle) * distance;

			ofColor myOrange(255, 0, 0, alpha);
			ofColor myRed(0, 255, 0, alpha);
			ofColor inBetween = myOrange.getLerped(myRed, ofRandom(1.0));
			ofSetColor(inBetween);

			//ofSetColor(255, alpha);
			ofDrawCircle(ofGetMouseX() + xOffset, ofGetMouseY() + yOffset, radius);
		}
	}
	else if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {  // If the right mouse button is pressed...
		ofSetColor(0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 50, 50);  // Draw a 50 x 50 rect centered over the mouse
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
