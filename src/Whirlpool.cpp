#include "Whirlpool.h"
void Whirlpool::setup()
{
	
	setup_whirlpool();
	field_information_setup();
}
void Whirlpool::updata(bool& rsz)
{
	updata_whirlpool();
	whirlpool_resize(rsz);
}
void Whirlpool::draw()
{
	draw_whirlpool();
	field_information_draw();
}
void Whirlpool::setup_whirlpool()
{
	img_interval[0] = 50;
	img_interval[1] = 50;
	//旋涡图片的载入
	for (int i = 0; i < 14; i++)
	{
		img_whirlpool[i].load("whirlpool" + ofToString(i + 1) + ".tif");
		img_whirlpool[i].resize(100, 100);
	}
	//旋涡初始坐标、初始能量、初始图片的设置、矫正
	for (int i = 0; i < 10; i++)
	{
		whirlpool_pos[i].x = ofRandom(300,ofGetWidth());
		whirlpool_pos[i].y = ofRandom(ofGetHeight());
		whirlpool_energy[i] = 0;
		img_now[i] = 0;
		lasttime[i] = -img_interval[0];
	}
}
void Whirlpool::updata_whirlpool()
{
	//旋涡图片的更新
	for (int i = 0; i<10; i++)
	{
		switch (whirlpool_energy[i])
		{
		case 0:
			if ((ofGetLastFrameTime() - lasttime[i])>img_interval[0])
			{
				if (img_now[i] < 13)
				{
					img_now[i]++;
				}
				else
				{
					img_now[i] = 0;
				}
			}
			break;
		case 1:
			if ((ofGetLastFrameTime() - lasttime[i])>img_interval[1])
			{
				if (img_now[i] < 13)
				{
					img_now[i]++;
				}
				else
				{
					img_now[i] = 0;
				}
			}
			break;
		default:
			break;
		}
	}
}
void Whirlpool::draw_whirlpool()
{
	for (int i = 0; i < 10; i++)
	{
		img_whirlpool[img_now[i]].draw(whirlpool_pos[i]-ofVec2f(50,50));
	}
}
void Whirlpool::field_information_draw()
{
	if (field_information_condition)
	{
		for (int i = 0; i < 60; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				ofVec2f boat_pos = ofVec2f((i + 1) * 20, (j + 1) * 20);
				ofDrawArrow(boat_pos - field_information[i][j]*5/ field_information[i][j].distance(ofVec2f(0,0)), boat_pos + field_information[i][j] * 5 / field_information[i][j].distance(ofVec2f(0, 0)), 2.5f);
			}
		}
	}
}
void Whirlpool::field_information_setup()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			ofVec2f boat_pos = ofVec2f((i + 1) * 20, (j + 1) * 20);
			for (int k = 0; k < 10; k++)
			{
				float dis = whirlpool_pos[k].distance(boat_pos);
				field_information[i][j] += 100 / dis*((whirlpool_pos[k] - boat_pos) / dis);
			}
		}
	}
}
void Whirlpool::whirlpool_resize(bool&rsz)
{
	if (rsz)
	{
		setup_whirlpool();
		field_information_setup();
		rsz = false;
	}
}
