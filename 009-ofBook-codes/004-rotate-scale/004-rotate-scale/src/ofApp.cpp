#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending(); // telling of to use transparency
	//ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofBackground(255);
	
	int r = ofRandom(255),
		g = ofRandom(255),
		b = ofRandom(255);
	ofSetColor(255, clearAlpha);
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofFill();
	// bg doesn't work on trasparent so draw a bg 
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(0);
	//ofSetColor(ofColor(150, g, b));
	ofNoFill();
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

		for (int i = 0; i < 100; i++) {	
			ofScale(1.1,1.1);
			//ofRotate(5);
			float time = ofGetElapsedTimef();
			float noise = ofSignedNoise(time * timeScale) * 20.0;
			ofRotate(noise);
			ofDrawRectangle(0, 0, 50,50);
		}
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	clearAlpha = ofMap(x, 0, ofGetWidth(), 0, 255);
	timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);
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
