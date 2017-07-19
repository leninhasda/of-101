#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);  // Clear the screen with a black color

    int len = points.size();
    for(int I=0; I < len; I++) {
        ofSetColor(colors[I].x, colors[I].y, colors[I].z);
        ofDrawRectangle(points[I].x, points[I].y, sizes[I].x, sizes[I].y);
    }
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {

        int numRects = 10;
        for (int r=0; r<numRects; r++) {
            float rr = ofRandom(0, 255);
            float gg = ofRandom(0, 255);
            float bb = ofRandom(0, 255);

            // ofSetColor(r, g, b);
            ofVec3f rgb(rr,gg,bb);
            colors.push_back(rgb);

            float width = ofRandom(5, 20);
            float height = ofRandom(5, 20);
            float distance = ofRandom(35);

            float angle = ofRandom(ofDegToRad(360.0));

            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;

            float posX = ofGetMouseX()+xOffset;
            float posY = ofGetMouseY()+yOffset;

            ofVec2f size(width, height);
            sizes.push_back(size);

            ofVec2f pos(posX, posY);
            points.push_back(pos);

            // ofDrawRectangle(postX, posY, width, height);
        }
    }
}

void ofApp::mouseMoved(int x, int y ){

    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {

        int numRects = 10;
        for (int r=0; r<numRects; r++) {
            float rr = ofRandom(0, 255);
            float gg = ofRandom(0, 255);
            float bb = ofRandom(0, 255);

            // ofSetColor(r, g, b);
            ofVec3f rgb(rr,gg,bb);
            colors.push_back(rgb);

            float width = ofRandom(5, 20);
            float height = ofRandom(5, 20);
            float distance = ofRandom(35);

            float angle = ofRandom(ofDegToRad(360.0));

            float xOffset = cos(angle) * distance;
            float yOffset = sin(angle) * distance;

            float posX = ofGetMouseX()+xOffset;
            float posY = ofGetMouseY()+yOffset;

            ofVec2f size(width, height);
            sizes.push_back(size);

            ofVec2f pos(posX, posY);
            points.push_back(pos);

            // ofDrawRectangle(postX, posY, width, height);
        }
    }
}


