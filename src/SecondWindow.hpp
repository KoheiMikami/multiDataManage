//
//  SecondWindow.hpp
//  multiDataManage
//
//  Created by MikamiKohei on 5/17/16.
//
//

#ifndef SecondWindow_hpp
#define SecondWindow_hpp

#include "ofMain.h"
#include "SoundInput.hpp"

class SecondWindow: public ofBaseApp{
    
    
    
public:
    void setup();
    void update();
    void draw();
    void dispSoundSize();
    
    SoundInput *si;
};

#endif /* SecondWindow_hpp */
