#pragma once
#include "ofMain.h"
#define whirlpool_energy1 150
#define whirlpool_energy2 200
class Boat 
{
public:
	void setup();
	void updata(ofVec2f pos[],int energy[]);
	void draw();
	bool rsz=false;
private:
	void updata_energy();
	void updata_pos();
	void updata_spd(ofVec2f pos[], int energy[]);
	void energy_show();
	void success_check(ofVec2f pos[]);
	void boat_resize();
	void setup_boat();
	ofVec2f boat_pos;
	ofVec2f boat_spd;
	ofVec2f boat_spd1;
	ofImage img_boat;
	int boat_energy;
	double energy_time;
	ofTrueTypeFont _font;

};


