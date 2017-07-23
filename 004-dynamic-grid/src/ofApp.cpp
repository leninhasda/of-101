#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);

    gui.setup();
    gui.add(gridDiv.set("gridDiv", 20, 2, 50));
    gui.add(circleRadius.set("circleRad", 5, 2, 10));
}

//--------------------------------------------------------------
void ofApp::exit(){
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(200);

    int winW = ofGetWidth();
    int winH = ofGetHeight();
    int spW = winW / int(gridDiv);
    int spH = winH / int(gridDiv);
    ofPoint start, end;

    for (int X = 0; X < winW ; X += spW) {
        start.set(X, 0); end.set(X, winH);
        ofDrawLine(start, end);
        for (int Y = 0; Y < winH; Y += spH) {
            if(X == 0) {
                start.set(0, Y); end.set(winW, Y);
                ofDrawLine(start, end);
            }

            ofDrawCircle(ofPoint(X, Y), int(circleRadius));
        }
    }

    gui.draw();
}
