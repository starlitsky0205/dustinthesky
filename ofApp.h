#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define NUM 500     //送料とりあえず決めておいたんご

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //int displayNum = 300;
    
    bool mouse_pressed;
    
    float loc_x[NUM],loc_y[NUM],speed_x[NUM],speed_y[NUM], dist, radius[NUM],dist2;
    
    ofVbo vbo;
    ofxPanel gui;
    ofxIntSlider num;   //実際に使う方のnum
  
};
