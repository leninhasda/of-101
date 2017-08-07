#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	int winW = ofGetWidth();
	int winH = ofGetHeight();

	ofPoint center(winW / 2, winH / 2);
	int size = 50;
	int r = 5;
	int angle = 18;

	/*for (size = 0; size < 300; size += 30) {
		for (float deg = 0; deg <= 360; deg += angle) {

			ofPoint xy;
			float angle_rad = ofDegToRad(deg);
			xy.x = center.x + size * cos(angle_rad);
			xy.y = center.y + size * sin(angle_rad);

			ofSetColor(20);
			ofDrawCircle(xy, r);
		}
		r += 1;
	}*/


	for (float deg = 0; deg <= 360; deg += angle, angle += 1) {
		r = 5;
		float tmpDeg = deg;
		int sp = 1;
		for (size = 360; size >= 0; size -= 30, tmpDeg += sp) {

			ofPoint xy;
			float angle_rad = ofDegToRad(tmpDeg);
			xy.x = center.x + size * cos(angle_rad);
			xy.y = center.y + size * sin(angle_rad);

			ofSetColor(
				255 * ofRandom(0, 1),
				255 * ofRandom(0, 1),
				255 * ofRandom(0, 1)
			);
			ofDrawCircle(xy, r);
			r += 1;
			sp += 1;
		}
	}

	gui.draw();
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
