#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.add(spiralSpin.set("Spiral Spin", 0.5, -1, 1));
	gui.add(circleCountLine.set("Circle in line", 10, 5, 20));
	//gui.add(circleCountCircle.set("Circle in circle", 20, 5, 20));
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(255);

	int winW = ofGetWidth();
	int winH = ofGetHeight();

	ofPoint center(winW / 2, winH / 2);
	int circleStep = 30;
	int circleMax = circleStep * circleCountLine;
	int r = 5;
	int angle = 360 / 20;
	float sp = 1, sp2=1;

	for (int size = 0; size < circleMax; size += circleStep, sp += sp2) {
		for (float deg = 0; deg <= 360; deg += angle) {

			ofPoint xy;
			float angle_rad = ofDegToRad(deg+sp);
			xy.x = center.x + size * cos(angle_rad);
			xy.y = center.y + size * sin(angle_rad);

			ofSetColor(ofColor::paleVioletRed);
			ofDrawCircle(xy, r);
		}
		r += 1;
		sp2 += spiralSpin;
	}

	/*ofColor rgb = ofColor::white;
	rgb.r = 255 * ofRandom(0, 1);
	rgb.g = 255 * ofRandom(0, 1);
	rgb.b = 255 * ofRandom(0, 1);

	for (float deg = 0; deg <= 360; deg += angle, angle += 1) {
		r = 5;
		float tmpDeg = deg;
		int sp = 5;

		for (size = 0; size < 300; size += 30, tmpDeg += sp) {

			ofPoint xy;
			float angle_rad = ofDegToRad(tmpDeg);
			xy.x = center.x + size * cos(angle_rad);
			xy.y = center.y + size * sin(angle_rad);

			//ofSetColor(rgb);
			ofSetColor(ofColor::paleVioletRed);
			ofDrawCircle(xy, r);
			r += 1;
			//sp += 1;
		}
	}*/

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
