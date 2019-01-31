#include "stdafx.h"
#include "BulletManager.h"


BulletManager::BulletManager() : Time(0), Center(640, 360)
{
}


BulletManager::~BulletManager()
{
}

BulletManager* BulletManager::instance()
{
	static BulletManager bmgr;
	return &bmgr;
}

void BulletManager::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	Time += eTime;
	for (auto iter = BulletList.begin(); iter != BulletList.end(); iter++)
	{
		(*iter)->Update(eTime);
	}
	SpawnBullet();

}

void BulletManager::Render()
{
	ZeroIScene::Render();
	for (auto iter = BulletList.begin(); iter != BulletList.end(); iter++)
	{
		(*iter)->Render();
	}
}

void BulletManager::SpawnBullet()
{

	if (Time >= 1)
	{
		Bullet* newB = new Bullet();

		while (true)
		{
			newB->Pos().x = rand() % 1080;
			newB->Pos().y = rand() % 720;
			if (newB->Pos().Distance(Center) > 300) break;
		}

		if (newB->Pos().x > 1080 / 2)
		{
			newB->dirX = -cos(rand() % 90);
		}
		else newB->dirX = cos(rand() % 90);

		if (newB->Pos().y > 720 / 2)
		{
			newB->dirY = -sin(rand() % 90);
		}
		else newB->dirY = sin(rand() % 90);

		
		BulletList.push_back(newB);
		Time -= 1;
	}
}
