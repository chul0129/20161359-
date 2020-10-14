#include<windows.h>
#include <iostream>
#include <bangtal.h>
#include <ctime>

using namespace bangtal;
using namespace std;

int main()
{
	auto scene = Scene::create("피해서 지나가기 Game", "gimage/장면.jpg");
	int dogx = 300, dogy = 500;
	auto dog = Object::create("gimage/강아지.jpg", scene, dogx, dogy);
	auto cloud = Object::create("gimage/사탕.jpg", scene, 600, 500);
	auto candy = Object::create("gimage/번개.png", scene, 100, 500);
	int cnt = 0;
	auto timer = Timer::create(0.02f);
	auto count = 0;
	
	
	timer->setOnTimerCallback([&](TimerPtr timer)->bool {  //타이머 호출 게임 시작
			dogx+=5;
			dogy-=5;
			cnt++;
			dog->locate(scene, dogx, dogy);
			dog->setOnMouseCallback([&](ObjectPtr object,int x, int y, MouseAction action)->bool {
				dogy += 35;
				dog->locate(scene, dogx, dogy);
				return true;
				});
		count++;
		if (count < 1000) {
			timer->set(0.02f);
			timer->start();
		}
		return true;
		});

	timer->start();


	startGame(scene);
	


	return 0;
}