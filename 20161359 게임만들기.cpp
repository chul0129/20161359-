#include<windows.h>
#include <iostream>
#include <bangtal>
#include <ctime>

using namespace bangtal;
using namespace std;

bool check(int f,int a, int b, int c, int d, int e) {
	if ((f >= 250) && (f <= 400))
	{
		if ((a < b) && (a + 90 < b) || (a > b + 150))
			return TRUE;
		else
			return FALSE;
	}
	else if ((f >= 500) && (f <= 650)) {
		if ((a < c) && (a + 90 < c) || (a > c + 150))
			return TRUE;
		else
			return FALSE;

	}
	else if ((f >= 800) && (f <= 950)) {
		if ((a < d) && (a + 90 < d) || (a > d + 150))
			return TRUE;
		else
			return FALSE;
	}
	else if ((f >= 1050) && (f <= 1200)) {
		if ((a < e) && (a + 90 < e) || (a > e + 150))
			return TRUE;
		else
			return FALSE;
	}

	else
		return TRUE;
	}


int main()
{
	srand(time(NULL));
	auto scene = Scene::create("피해서 지나가기 Game", "gimage/장면.jpg");
	int dogx = 0, dogy = 400;
	
	int candy_x = 250, squ_x=500, rab_x=800, cloud_x=1050;
	int a, b, c, d;
	
	
		a = rand()%600;
		b = rand()%600;
		c = rand()%600;
		d = rand()%600;
	
	int candy_y = a, squ_y = b, rab_y = c, cloud_y = d;

	auto dog = Object::create("gimage/강아지.jpg", scene, dogx, dogy);
	auto candy = Object::create("gimage/사탕.jpg", scene, candy_x, candy_y);
	auto cloud = Object::create("gimage/번개.png", scene, cloud_x, cloud_y);
	auto squ = Object::create("gimage/다람쥐.jpg", scene, squ_x, squ_y);
	auto rab = Object::create("gimage/토끼.jpg", scene, rab_x, rab_y);
	int cnt = 0;
	auto timer1 = Timer::create(0.02f);
	auto timer2 = Timer::create(0.02f);
	auto timer3 = Timer::create(1.0f);

	auto count = 0;
	
	timer1->setOnTimerCallback([&](TimerPtr timer)->bool {  //타이머 호출 게임 시작
			dogx+=5;
			dogy-=5;
			dog->locate(scene, dogx, dogy);
			
			dog->setOnMouseCallback([&](ObjectPtr object,int x, int y, MouseAction action)->bool {
				dogy += 70;
				dog->locate(scene, dogx, dogy);
				
					return true;
				});
			
			if (check(dogx, dogy, candy_y, squ_y, rab_y, cloud_y))
			{
				if (dogx < 1190 && dogy>0) {
					timer1->set(0.02f);
					timer1->start();
				}

				if (dogx >= 1190)
				{
					dogx = 0;
					dogy = 400;
					a = rand() % 600;
					b = rand() % 600;
					c = rand() % 600;
					d = rand() % 600;
					candy_y = a, squ_y = b, rab_y = c, cloud_y = d;
					candy->locate(scene, candy_x, candy_y);
					cloud->locate(scene, cloud_x, cloud_y);
					rab->locate(scene, rab_x, rab_y);
					squ->locate(scene, squ_x, squ_y);

					timer1->start();
				}
				if (dogy <= 0)
				{
					showMessage("게임 종료");
				}
			}
			else
			{
				showMessage("게임 종료");

			}
			


		return true;
		});













	timer1->start();
	timer3->start();

	startGame(scene);
	


	return 0;
}