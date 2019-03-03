#include "stdafx.h"
#include "BombManager.h"


BombManager::BombManager(Player* p) : Center(640, 360), Time(0)
{
	this->p = p;
}


BombManager::~BombManager()
{
}

void BombManager::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	Time += eTime;
	if (Time > 3)
	{
		SpawnBomb();
		Time -= 3;
	}

	for (auto iter = bombList.begin(); iter != bombList.end(); iter++)
	{
		(*iter)->Update(eTime);
	}
	Destroy();
}

void BombManager::Render()
{
	ZeroIScene::Render();

	for (auto iter = bombList.begin(); iter != bombList.end(); iter++)
	{
		(*iter)->Render();
	}
}

void BombManager::SpawnBomb()
{
	Bomb *bomb = new Bomb();
	bomb->p = p;
	while (true)
	{
		bomb->Pos().x = rand() % 1280; // 640
		bomb->Pos().y = rand() % 720; // 360
		if (bomb->Pos().Distance(Center) < 300) break;
	}

	bombList.push_back(bomb);
}

void BombManager::Destroy()
{
	for (auto iter = bombList.begin(); iter != bombList.end();)
	{
		if ((*iter)->Time > 1.5f)
		{
			delete *iter;
			iter = bombList.erase(iter);
		}
		else iter++;
	}
}