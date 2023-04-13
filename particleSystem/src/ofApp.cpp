#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    vidPlayer.load("movies/finger.mov");
//    vidPlayer.play();
//    vidPlayer.setLoopState(OF_LOOP_NORMAL);
    
    vidGrabber.setVerbose(true);
    vidGrabber.setup(320, 240);
    
    colorImg.allocate(320, 240);
    grayImg.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);
    
    gui.setup();
    gui.add(overallSpeed.setup("speed",1,0,3));
    gui.add(noiseAmount.setup("noise",1,0,3));
    gui.add(trail.setup("trail",6.0,0,20));
    gui.add(threshold.setup("threshold",80,0,255));
    
    gui.add(bLearnBackgrounds.setup("capture bg",false));
    
    p.assign(100, particle()); // 100 particles
    
    for (int i=0; i<p.size();i++){
        p[i].setup();
    }
    
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetFrameRate(60);
    
    bool bNewFrame = false;
    
//    vidPlayer.update();
//    bNewFrame = vidPlayer.isFrameNew();
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    
    if(bNewFrame == true){
        colorImg.setFromPixels(vidGrabber.getPixels());
        grayImg = colorImg;
        
        if(bLearnBackgrounds==true){
            grayBg = grayImg;
            bLearnBackgrounds = false;
        }
        
        grayDiff.absDiff(grayBg,grayImg);
        grayDiff.threshold(threshold);
        
        contourFinder.findContours(grayDiff, 20, 340*20/2, 10, true);
        
        
    }
    
    vector<ofVec2f>blobPts;
    
    for (int i = 0; i<contourFinder.nBlobs; i++){
        for (int j=0; j<contourFinder.blobs[i].pts.size();j++){
            blobPts.push_back(contourFinder.blobs[i].pts[j] * ofGetWidth()/320);
        }
    }
    
    for (int i=0; i<p.size();i++){
        p[i].repel(blobPts);
        p[i].update(overallSpeed,noiseAmount);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 0, 0, trail);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 255, 255, 255); // rgb alpha
    
    for (int i=0; i<p.size();i++){
        p[i].draw(1);
    }
//    vidGrabber.draw(ofGetWidth()/2, ofGetHeight()/2, 320, 240);
    
    // draw incoming, grayscale, bg and threshold difference
    ofSetHexColor(0xffffff);
    colorImg.draw(20, 20, 320, 240);
    grayImg.draw(360, 20);
    grayBg.draw(20, 280);
    grayDiff.draw(360, 280);

    // draw contours
    ofFill();
    ofSetHexColor(0x333333);
    ofDrawRectangle(360, 540, 320, 240);
    ofSetHexColor(0xffffff);

    contourFinder.draw(360,540);
    
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
