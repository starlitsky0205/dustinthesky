#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    
    mouse_pressed=false;
   
    num=NUM;
    for (int i=0;i<num;i++){
    loc_x[i]=ofGetWidth()/2;
    loc_y[i]=ofGetHeight()/2;
    speed_x[i]=ofRandom(-5,5);
    speed_y[i]=ofRandom(-5,5);
    radius[i]=3;
  }
    gui.setup();
    gui.add(num.setup("NUM",1,1,300));
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<num;i++){
        if(mouse_pressed == true){
            speed_x[i]=ofRandom(0,(ofGetMouseX()-loc_x[i])/20);
            speed_y[i]=ofRandom(0,(ofGetMouseY()-loc_y[i])/20);
        }
        loc_x[i]=loc_x[i]+speed_x[i];
        loc_y[i]=loc_y[i]+speed_y[i];
        
        if(ofDist(loc_x[i],loc_y[i],ofGetWidth()/2,ofGetHeight()/2)>290){
            speed_x[i]=-speed_x[i];
            speed_y[i]=-speed_y[i];}
    }
    mouse_pressed=false;
}


//--------------------------------------------------------------
void ofApp::draw(){
    
   ofBackgroundGradient(ofColor(0,146,202),ofColor(28,62,172),OF_GRADIENT_LINEAR);
    ofSetCircleResolution(64);
    ofSetColor(21,22,128);
    ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,300);
  
    for(int i=0; i<num;i++){
        ofSetColor(255);
        ofDrawCircle(loc_x[i],loc_y[i],radius[i]);
        for(int j=0; j<num;j++){
            dist=sqrt((loc_x[i]-loc_x[j])*(loc_x[i]-loc_x[j])+(loc_y[i]-loc_y[j])*(loc_y[i]-loc_y[j]));
            if(dist<100){
                ofSetColor(255,255,255,100);
                ofSetLineWidth(0.3);
                ofDrawLine(loc_x[i],loc_y[i],loc_x[j],loc_y[j] );
                for(int k=0; k<num;k++){
                    if(ofDist(loc_x[i],loc_y[i],loc_x[j],loc_y[j],loc_x[k],loc_y[k])<10){
                        ofFill();
                    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255),127);
                    ofDrawTriangle(loc_x[i],loc_y[i],loc_x[j],loc_y[j],loc_x[k],loc_y[k] );
                        
                    }
                }
            }
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
    
    mouse_pressed=true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouse_pressed==false;

    for(int i=0; i<NUM;i++){
    speed_x[i]=ofRandom(-5,5);
    speed_y[i]=ofRandom(-5,5);
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
