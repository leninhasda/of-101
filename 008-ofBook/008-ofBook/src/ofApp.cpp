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

		/*int maxRadius = 100;  // Increase for a wider brush
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
		}*/

		/*int numLines = 30;
		int minRadius = 25;
		int maxRadius = 125;
		for (int i = 0; i<numLines; i++) {
			float angle = ofRandom(ofDegToRad(360.0));
			float distance = ofRandom(minRadius, maxRadius);
			float xOffset = cos(angle) * distance;
			float yOffset = sin(angle) * distance;
			float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);  // Make shorter lines more opaque
			ofSetColor(255, alpha);
			ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX() + xOffset, ofGetMouseY() + yOffset);
		}*/

		int numTriangles = 10;
		int minOffset = 5;
		int maxOffset = 70;
		int alpha = 150;

		for (int t = 0; t<numTriangles; ++t) {
			float offsetDistance = ofRandom(minOffset, maxOffset);

			ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

			// Define a triangle at the origin (0,0) that points to the right
			ofVec2f p1(0, 6.25);
			ofVec2f p2(25, 0);
			ofVec2f p3(0, -6.25);

			float rotation = ofRandom(360); // The rotate function uses degrees!
			p1.rotate(rotation);
			p2.rotate(rotation);
			p3.rotate(rotation);

			ofVec2f triangleOffset(offsetDistance, 0.0);
			triangleOffset.rotate(rotation);

			p1 += mousePos + triangleOffset;
			p2 += mousePos + triangleOffset;
			p3 += mousePos + triangleOffset;

			ofColor aqua(0, 252, 255, alpha);
			ofColor purple(198, 0, 205, alpha);
			ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
			ofSetColor(inbetween);

			ofDrawTriangle(p1, p2, p3);
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
	if (key == 's') {
		// It's strange that we can compare the int key to a character like `s`, right?  Well, the super short
		// explanation is that characters are represented by numbers in programming.  `s` and 115 are the same
		// thing.  If you want to know more, check out the wiki for ASCII.
		glReadBuffer(GL_FRONT);  // HACK: only needed on windows, when using ofSetAutoBackground(false)
		ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
	}
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
