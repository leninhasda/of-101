#include "ofApp.h"
#include <cmath>

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(gridDiv.set("grid divide", 20, 4, 50));
	gui.add(circleRadius.set("circle Radius", 2, 1, 5));
	gui.add(lineDist.set("line length", 150, 100, 300));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	int winW = ofGetWidth();
	int winH = ofGetHeight();

	int spH = winH / int(gridDiv);
	//int spH = winH / int(gridDiv);
	ofPoint start, end;
	int X, Y, cnt;

	//printf("winH: %d <---> sph: %d\n", winH, spH);


	for (Y = 0; Y < winH; Y += spH/2) {
		X = (Y % 2 == 0) ? 0 : spH / 4;
		cnt = 0;
		while (X < winW) {
			if (Y % 2 == 0) {
				X += (cnt % 2 == 0) ? spH : spH / 2;
			}
			else {
				X += (cnt % 2 == 0) ? spH / 2 : spH;
			}

			ofSetColor(200);
			ofDrawCircle(ofPoint(X, Y), int(circleRadius));
			cnt++;

			this->maybeDrawLine(X, Y);

		}
	}

	gui.draw();
}

void ofApp::maybeDrawLine(int x, int y) {
	int xx = ofGetMouseX() - x;
	int yy = ofGetMouseY() - y;
	int distance = sqrt((xx) * (xx) + (yy) * (yy));

	if (distance <= int(lineDist)) {
		int color = distance + (250 - int(lineDist));
		printf("color: %d\n", color);

		ofSetColor(color);
		ofDrawLine(ofPoint(x, y), ofPoint(ofGetMouseX(), ofGetMouseY()));
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
