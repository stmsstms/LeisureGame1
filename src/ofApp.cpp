#include "ofApp.h"
#include "Whirlpool.h"
#include "Boat.h"
Whirlpool whirlpool;
Boat boat;
//--------------------------------------------------------------
void ofApp::setup()
{
	whirlpool.setup();
	boat.setup();
}

//--------------------------------------------------------------
void ofApp::update()
{
	whirlpool.updata(boat.rsz);
	boat.updata(whirlpool.whirlpool_pos,whirlpool.whirlpool_energy);
}

//--------------------------------------------------------------
void ofApp::draw()
{
	whirlpool.draw();
	boat.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	switch (key)
	{
	case OF_KEY_F1:
		whirlpool.field_information_condition = !whirlpool.field_information_condition;
		break;
	default:
		break;
	}
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
