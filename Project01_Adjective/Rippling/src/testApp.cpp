#include "testApp.h"
#define NUM_CIRCLES 5

ofPoint pos[NUM_CIRCLES];

int circlex[NUM_CIRCLES];
int circley[NUM_CIRCLES];
int circleradius[NUM_CIRCLES];
int xpos[NUM_CIRCLES];
int ypos[NUM_CIRCLES];

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(20);
    ofSetCircleResolution(40);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(0, 0, 0);
    ofSetColor(100 ,100, 100);
    ofEnableSmoothing();

    for(int i=0; i<NUM_CIRCLES; i++){
        xpos[i]+=circlex[i] * ofGetLastFrameTime();
        ypos[i]+=circley[i] * ofGetLastFrameTime();
        
        if(xpos[i] > ofGetWidth()-circleradius[i]){
            xpos[i] = ofGetWidth()-circleradius[i];
            circlex[i] *= -2;
        }
        
        if(xpos[i] < circleradius[i]){
            xpos[i] = circleradius[i];
            circlex[i] *= -2;
        }
        
        if(ypos[i] > ofGetHeight()-circleradius[i]){
            ypos[i] = ofGetHeight()-circleradius[i];
            circley[i] *= -2;
        }
        
        if(ypos[i] < circleradius[i]){
            ypos[i] =circleradius[i];
            circley[i] *= -2;
        }
            
            circleradius[i]++;
            
        if(circleradius[i] > 2000){
            circleradius[i] = 5000;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
     
    ofBackgroundGradient(255, 0);
    ofNoFill();
    
    for(int i=0; i<NUM_CIRCLES; i++){
        
        ofCircle(pos[i].x, pos[i].y, circleradius[i]);
        ofCircle(pos[i].x, pos[i].y, circleradius[i]/2);
        ofCircle(pos[i].x, pos[i].y, circleradius[i]/4);
        ofCircle(pos[i].x, pos[i].y, circleradius[i]/6);
        ofCircle(pos[i].x, pos[i].y, circleradius[i]/8);
        ofCircle(pos[i].x, pos[i].y, circleradius[i]/16);
        ofCircle(pos[i].x, pos[i].y, circleradius[i]/32);
        ofCircle(pos[i].x, pos[i].y, circleradius[i]/64);
        
        circlex[i] = ofRandomWidth();
        circley[i] = ofRandomHeight();
        
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    ofSetColor(100, 100, 100);
    
    for(int i=0; i<NUM_CIRCLES; i++){
        circleradius[i] = ofRandom(1000);
    }

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    ofSetColor(100 ,100, 100);
    
    for(int i=0; i<NUM_CIRCLES; i++){
        
        circleradius[i] = ofRandom(500);
        
        pos[i].x = ofRandomWidth();
        pos[i].y = ofRandomHeight();
        
        circlex[i] = ofRandom(50, 100);
        circley[i] = ofRandom(50, 100);
        circleradius[i] = ofRandom(500);
        
    }
    

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}