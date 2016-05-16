#include "ofMain.h"
#include "ofApp.h"
#include "SecondWindow.hpp"
#include "SoundInput.hpp"

//========================================================================
int main( ){
    
    
    ofGLFWWindowSettings setting;
    setting.width = 1024;
    setting.height = 768;
    setting.setPosition(ofVec2f(0,0));
    setting.resizable = true;
    shared_ptr<ofAppBaseWindow> firstWindow = ofCreateWindow(setting);
    
    setting.width = 1024;
    setting.height = 768;
    setting.setPosition(ofVec2f(1024,0));
    setting.resizable = true;
    shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(setting);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<SecondWindow> secondApp(new SecondWindow);
    
    SoundInput input;
    input.setup();
    mainApp->si = &input;
    secondApp->si = &input;
   
    
    ofRunApp(secondWindow, secondApp);
    ofRunApp(firstWindow, mainApp);
    
    ofRunMainLoop();
}
