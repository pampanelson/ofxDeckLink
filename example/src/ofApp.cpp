#include "ofMain.h"
#include "ofxDeckLink.h"

class ofApp : public ofBaseApp{
    ofxDeckLinkAPI::Input input;
public:
    void setup()
    {
        ofSetVerticalSync(true);
        ofSetFrameRate(60);
        
        input.setup(0);
        input.start(bmdModeHD1080i5994);
    }
    
    void update()
    {
        input.update();
    }
    
    void draw()
    {
        ofClear(0);
        input.draw(0, 0, ofGetWidth(), ofGetHeight());
        
        ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), 10, 20);
    }
    
    void keyPressed(int key)
    {
        if (key == 'f') {
            ofToggleFullscreen();
        }
        if (key == '1') {
            input.setDrawMode(ofxDeckLinkAPI::Input::DRAWMODE_PROGRESSIVE);
        }
        if (key == '2') {
            input.setDrawMode(ofxDeckLinkAPI::Input::DRAWMODE_UPPERFIELD);
        }
        if (key == '3') {
            input.setDrawMode(ofxDeckLinkAPI::Input::DRAWMODE_LOWERFIELD);
        }
        if (key == '4') {
            input.setDrawMode(ofxDeckLinkAPI::Input::DRAWMODE_AUTOFIELD);
        }
    }
};

//#include "ofAppGLFWWindow.h"
//========================================================================
int main( ){
    //    ofAppGLFWWindow window;
    //    window.setNumSamples(0);
    //    window.setMultiDisplayFullscreen(true);
    //    ofSetupOpenGL(&window, 1280, 720, OF_WINDOW);
    
    ofSetupOpenGL(1280,720,OF_WINDOW);            // <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
}