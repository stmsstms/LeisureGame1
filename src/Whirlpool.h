#pragma once
#include "ofMain.h"
class Whirlpool
{
public:
	void setup();
	void updata(bool& rsz);
	void draw();
	ofVec2f whirlpool_pos[10];
	int whirlpool_energy[10];
	bool field_information_condition = false;
private:
	void setup_whirlpool();
	void updata_whirlpool();
	void draw_whirlpool();
	void spd_resize(ofVec2f& spd);
	void field_information_draw();
	void field_information_setup();
	void whirlpool_resize(bool& rsz);
	ofVec2f field_information[60][25];
	ofImage img_whirlpool[14];
	int img_now[10];
	double lasttime[10];
	float img_interval[2];
	
};


