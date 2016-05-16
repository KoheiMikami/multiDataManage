//
//  SecondWindow.cpp
//  multiDataManage
//
//  Created by MikamiKohei on 5/17/16.
//
//


void SecondWindow::setup() {
   ofSetWindowTitle("SecondWindow");
    ofBackground(0);
}

void SecondWindow::update() {


}

void SecondWindow::draw() {
    dispSoundSize();
}


void SecondWindow::dispSoundSize() {
    stringstream ss;
    ss << "SoundSize" << ofToString(si->getSize(), 7);
    ofDrawBitmapString(ss.str(), 10, 20);
}
