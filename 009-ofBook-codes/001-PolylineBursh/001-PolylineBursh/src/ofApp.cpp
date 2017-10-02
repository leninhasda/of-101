#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	minDistance = 10;
	leftMouseButtonPressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (leftMouseButtonPressed) {
		ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
		if (lastPoint.distance(mousePos) >= minDistance) {
			currentPolyline.curveTo(mousePos);
			lastPoint = mousePos;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);

	for (int i = 0; i < polylines.size(); i++) {
		ofPolyline polyline = polylines[i];
		polyline.draw();
	}

	ofSetColor(255, 100, 0);
	currentPolyline.draw();
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
	if (button == OF_MOUSE_BUTTON_LEFT) {
		leftMouseButtonPressed = true;
		currentPolyline.curveTo(x, y);
		currentPolyline.curveTo(x, y);
		lastPoint.set(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		leftMouseButtonPressed = false;
		currentPolyline.curveTo(x, y);
		polylines.push_back(currentPolyline);
		currentPolyline.clear();
	}
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
