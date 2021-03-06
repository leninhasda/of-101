#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	gui.add(r.set("Red", 255, 0, 255));
	gui.add(g.set("Green", 255, 0, 255));
	gui.add(b.set("Blue", 255, 0, 255));

	minDistance = 10;
	leftMouseButtonPressed = false;

	isSavingPDF = false;
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
	if (isSavingPDF) {
		ofBeginSaveScreenAsPDF("savedScreenshot_" + ofGetTimestampString() + ".pdf");
	}

	ofBackground(0);

	for (int i = 0; i < polylines.size(); i++) {
		ofPolyline polyline = polylines[i];

		ofSetColor(colors[i]);
		polyline.draw();

		/*vector <ofVec3f> vertices = polyline.getVertices();
		for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
			ofVec3f vertex = vertices[vertexIndex];
			ofDrawCircle(vertex, 5);
		}*/
		/*for (int p = 0; p<100; p += 10) {
			ofVec3f point = polyline.getPointAtPercent(p / 100.0);  // Returns a point at a percentage along the polyline
			ofDrawCircle(point, 5);
		}*/
		
		/*vector <ofVec3f> vertices = polyline.getVertices();
		float normalLength = 50;
		for (int vertexIndex = 0; vertexIndex < vertices.size(); vertexIndex++) {
			ofVec3f vertex = vertices[vertexIndex];
			ofVec3f normal = polyline.getNormalAtIndex(vertexIndex) * normalLength;
			ofDrawLine(vertex-normal/2, vertex+normal/2);
		}*/

		/*float normalLength = 50;
		for (int p = 0; p<500; p += 1) {
			ofVec3f point = polyline.getPointAtPercent(p / 500.0);
			float floatIndex = polyline.getIndexAtPercent(p / 500.0);
			ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
			ofSetColor(255, 100);
			ofDrawLine(point - normal / 2, point + normal / 2);
		}*/

		/*vector<ofVec3f> vertices = polyline.getVertices();
		float tangentLength = 80;
		for (int vertexIndex = 0; vertexIndex<vertices.size(); vertexIndex++) {
			ofVec3f vertex = vertices[vertexIndex];
			ofVec3f tangent = polyline.getTangentAtIndex(vertexIndex) * tangentLength;
			ofDrawLine(vertex - tangent / 2, vertex + tangent / 2);
		}*/

		ofSetColor(colors[i], 50);
		float tangentLength = 300;
		for (int p = 0; p<500; p += 1) {
			ofVec3f point = polyline.getPointAtPercent(p / 500.0);
			float floatIndex = polyline.getIndexAtPercent(p / 500.0);
			ofVec3f tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
			ofDrawLine(point - tangent / 2, point + tangent / 2);
		}

	}

	ofSetColor(255, 100, 0);
	currentPolyline.draw();

	gui.draw();

	if (isSavingPDF) {
		ofEndSaveScreenAsPDF();
		isSavingPDF = false;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		// isSavingPDF is a flag that lets us know whether or not save a PDF
		isSavingPDF = true;
	}
	if (key == 'p') {
		img.grabScreen(0, 0,
			ofGetWidth(), ofGetHeight()
		);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	int size;
	if (key == 'u') {
		size = polylines.size();
		if (size > 0) {
			undos.push(polylines.at(size - 1));
			undoColors.push(colors.at(size - 1));

			polylines.pop_back();
			colors.pop_back();
		}
	}
	if (key == 'r') {
		size = undos.size();
		if (size > 0) {
			polylines.push_back(undos.top());
			colors.push_back(undoColors.top());

			undos.pop();
			undoColors.pop();
		}
	}

	if (key == 'p') {
		img.save("savedScreenshot_" + ofGetTimestampString() + ".png", OF_IMAGE_QUALITY_BEST);
	}
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
		colors.push_back(ofColor(r, g, b));
		currentPolyline.simplify(.9);
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
