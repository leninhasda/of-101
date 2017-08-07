#include "ofApp.h"
#include "ofMain.h"

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

ofPoint ofApp::hex_corner(ofPoint center, int size, int i) {
	float angle_deg = 60 * i + 30;
	float angle_rad = ofDegToRad(angle_deg);
	
	return ofPoint(
		center.x + size * cos(angle_rad), 
		center.y + size * sin(angle_rad)
	);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	int winW = ofGetWidth();
	int winH = ofGetHeight();

	int halfSize = winW / int(gridDiv);
	int r = winW / int(gridDiv);
	int fullSize = halfSize * 2;

	ofPoint start, end;
	int cnt=0;
	int xI, yI;

	ofPoint xy(ofGetMouseX(), ofGetMouseY());
	int height = r * 2;
	int width = sqrt(3) / 2 * height;
	int hsp = height * 3 / 4;

	for (yI = 0,cnt=0; yI < winH; yI += hsp, cnt++) {
		xI = (cnt % 2 == 0) ? 0 : width / 2;
		for (; xI < winW; xI += width) {
			// xI, yI is the center of hexagone
			//ofSetColor(ofColor::red);
			//ofDrawCircle(xI, yI, int(circleRadius));

			for (int i = 0; i < 6; i++) {
				ofPoint hexDot = hex_corner(ofPoint(xI, yI), r, i);
				//if (!xI && !yI) {
					//printf("dot xy: %f, %f", hexDot.x, hexDot.y);
					//ofLog(OF_LOG_NOTICE, "the number is " + ofToString(hexDot.x));
				//}
				
				ofSetColor(ofColor::blue);
				ofDrawCircle(hexDot, int(circleRadius));
				//ofSetColor(230);
				//ofDrawLine(ofPoint(xI, yI), hexDot);
				
				//ofDrawCircle(ofPoint(xI, yI), int(circleRadius));
				maybeDrawLine(hexDot);
			}
		}
	}

	gui.draw();
}

void ofApp::maybeDrawLine(ofPoint point) {
	int sqrdDist = ofDistSquared(ofGetMouseX(), ofGetMouseY(), point.x, point.y);
	ofColor lineColor = ofColor::red;

	if (sqrdDist <= int(lineDist*lineDist)) {
		// range scaling
		// from 0~lineDist^2
		int a = 0, b = lineDist * lineDist; 
		// to 5 ~ 150
		int y = 1, z = 255;
		int opacity = z - ( (z-y) * (sqrdDist - a)) / (b-a) + y;
		lineColor.a = opacity; // a = alpha
		

		ofSetColor(lineColor);
		ofDrawLine(point, ofPoint(ofGetMouseX(), ofGetMouseY()));
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
