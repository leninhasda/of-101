#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::white);

	for (int rows = 1; rows <= 4; rows++) {

		ofPushMatrix();

			for (int cols = 1; cols <= 4; cols++) {
			

				// Draw the stick figure family
				ofSetColor(ofColor::cornflowerBlue);
				ofDrawCircle(30, 30, 30);
				ofDrawRectangle(5, 70, 50, 100);

				ofSetColor(ofColor::hotPink);
				ofDrawCircle(95, 30, 30);
				ofDrawRectangle(70, 70, 50, 100);

				ofSetColor(ofColor::hotPink);
				ofDrawCircle(45, 90, 15);
				ofDrawRectangle(30, 110, 30, 60);

				ofSetColor(ofColor::cornflowerBlue);
				ofDrawCircle(80, 90, 15);
				ofDrawRectangle(65, 110, 30, 60);

				ofTranslate(150, 0);

			}

		ofPopMatrix();

		ofTranslate(0, 200);
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
