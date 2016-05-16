//
//  SoundInput.cpp
//  multiDataManage
//
//  Created by MikamiKohei on 5/17/16.
//
//

#include "SoundInput.hpp"


void SoundInput::setup() {
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(0, 2, 44100, bufferSize, 4);
    soundStream.setInput(this);
    
}

float SoundInput::getSize() {
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }

    return scaledVol * 100.0;
}

void SoundInput::audioIn( float * input, int bufferSize, int nChannels )
{
    float curVol = 0.0;
    int numCounted = 0;
    
    for ( int i=0; i<bufferSize; i++ )
    {
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
        
    }
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
}