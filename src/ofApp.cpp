#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);

    this->gui_manager.gui.setup("Parameters", "settings.xml" );
    this->gui_manager.gui.add(gui_manager.radius.setup("radius", 140, 10, 300));
    this->gui_manager.button.setBackgroundColor(ofColor(0,255,100));
    
    this->gui_manager.gui.add(gui_manager.button.setup("main_button",100,100));
    this->gui_manager.gui.add(gui_manager.countX.setup( "countX", 50, 0, 200 ) );
    this->gui_manager.gui.add(gui_manager.stepX.setup( "stepX", 20, 0, 200 ) );
    this->gui_manager.gui.add(gui_manager.twistX.setup( "twistX", 5, -45, 45 ) );
    this->gui_manager.gui.loadFromFile( "settings.xml" );

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
  ofPushMatrix();
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
  stripePattern();
//   ofDrawCircle(0, 0, gui_manager.radius);
  ofPopMatrix();
  gui_manager.gui.draw();
}

void ofApp::stripePattern() {
  ofSetColor(ofColor::black);
  ofSetLineWidth(3.0);
  ofNoFill();
  for (int i = -gui_manager.countX; i <= gui_manager.countX; i++) {
    ofPushMatrix();
    ofTranslate(i * gui_manager.stepX, 0);
    ofRotateDeg(i * gui_manager.twistX);
    ofScale(6, 6);
    ofDrawTriangle(0, 0, -50, 100, 50, 100);
    ofPopMatrix();
  }
}
void ofApp::exit() { this->gui_manager.gui.saveToFile("settings.xml"); }

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
