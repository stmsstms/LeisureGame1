#include "Boat.h"
void Boat::setup()
{
	setup_boat();
	
}
void Boat::updata(ofVec2f pos[], int energy[])
{
	updata_energy();
	updata_pos();
	updata_spd(pos,energy);
	success_check(pos);
	boat_resize();
}
void Boat::draw()
{
	img_boat.draw(boat_pos-ofVec2f(img_boat.getWidth()/2,img_boat.getHeight()/2));
	energy_show();
}
void Boat::updata_energy()
{
	if (ofGetKeyPressed('w') || ofGetKeyPressed('s'))
	{
		if (boat_energy > 0)
		{
			boat_energy -= 1;
		}
	}
	if ((ofGetElapsedTimef() - energy_time > 0.1)&&(boat_energy!=200))
	{
		boat_energy++;
		energy_time = ofGetElapsedTimef();
	}
}
void Boat::updata_pos()
{
	boat_pos += boat_spd;
	boat_pos += ofVec2f(0,boat_spd1.y);
	if (boat_energy > 0)
	{
		if (ofGetKeyPressed('w'))
		{
			boat_pos += ofVec2f(0, -3);
		}
		if (ofGetKeyPressed('s'))
		{
			boat_pos += ofVec2f(0, 3);
		}
	}
	for (int i = 0; i < 10; i++)
	{

	}
}
void Boat::updata_spd(ofVec2f pos[], int energy[])
{
	boat_spd1 = ofVec2f(0,0);
	for (int i = 0; i < 10; i++)
	{
		if (energy[i] == 0)
		{
			boat_spd1 = boat_spd1 + whirlpool_energy1 / pos[i].distance(boat_pos)*((pos[i]-boat_pos)/ pos[i].distance(boat_pos));
		}
		else if (energy[i] == 1)
		{
			boat_spd1 = boat_spd1 + whirlpool_energy2 / pos[i].distance(boat_pos)*((pos[i] - boat_pos) / pos[i].distance(boat_pos));
		}
	}
}
void Boat::energy_show()
{
	ofPushStyle();
	ofDrawRectangle(20, 20, 200, 20);
	ofPopStyle();
	ofPushStyle();
	ofSetColor(0, 0, 0);
	ofDrawRectangle(20, 20, boat_energy, 20);
	ofPopStyle();
	if (boat_energy < 50)
	{
		_font.drawString(ofToString("ENERGY IS EMPTY"), 100, 50);
	}
}
void Boat::success_check(ofVec2f pos[])
{
	for (int i = 0; i < 10; i++)
	{
		if (boat_pos.distance(	pos[i]) < 10)
		{
			rsz = true;
			Sleep(2000);
		}
	}
	if (boat_pos.x > ofGetWidth())
	{
		rsz = true;
		Sleep(2000);
	}
}
void Boat::boat_resize()
{
	if (rsz)
	{
		setup_boat();
	}
}
void Boat::setup_boat()
{
	energy_time = 0;
	boat_energy = 200;
	_font.load("vag.ttf", 10);
	boat_pos = ofVec2f(20, ofGetHeight() / 2);
	img_boat.load("boat.tif");
	img_boat.resize(ofGetWidth() / 15, ofGetHeight() / 15);
	boat_spd = ofVec2f(1, 0);
	boat_spd1 = ofVec2f(0, 0);
}

