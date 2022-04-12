#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

}

//--------------------------------------------------------------
void ofApp::draw() {

	auto span = 60; 

	ofSetColor(255);
	for (int x = span; x < ofGetWidth(); x += span) {

		for (int y = 0; y < ofGetHeight(); y += 3) {

			auto noise_value = ofNoise(x * 0.05, y * 0.008 - ofGetFrameNum() * 0.01);

			if (noise_value > 0.45) {

				auto radius = ofMap(noise_value, 0.45, 1, 0.1, span * 0.5);


				ofNoFill();
				ofDrawCircle(x, y, radius);
			}
		}
	}


	ofSetColor(0);
	for (int x = span; x < ofGetWidth(); x += span) {

		for (int y = 0; y < ofGetHeight(); y += 18) {

			auto noise_value = ofNoise(x * 0.05, y * 0.008 - ofGetFrameNum() * 0.01);

			if (noise_value > 0.45) {

				auto radius = ofMap(noise_value, 0.45, 1, 0.1, span * 0.5);

				ofFill();
				ofDrawCircle(x, y, radius);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}