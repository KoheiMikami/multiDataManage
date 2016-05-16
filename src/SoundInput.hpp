//
//  SoundInput.hpp
//  multiDataManage
//
//  Created by MikamiKohei on 5/17/16.
//
//

#ifndef SoundInput_hpp
#define SoundInput_hpp

#include "ofMain.h"

class SoundInput : public ofBaseSoundInput {
    
private:
    float level;
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    ofSoundStream soundStream;
    
public:
    

    virtual void audioIn(float * input, int bufferSize, int nChannels);
    void setup();
    float getSize();
    
};


#endif /* SoundInput_hpp */
