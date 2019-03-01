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
	float angle;
	if (Time >= 1)
	{
		Bullet* newB = new Bullet();

		while (true)
		{
			newB->Pos().x = rand() % 1280; // 640
			newB->Pos().y = rand() % 720; // 360
			if (newB->Pos().Distance(Center) > 300) break;
		}
		angle = atan2(rand() % 660 + 60 - newB->Pos().y, rand() % 940 + 340 - newB->Pos().x);
		/*if (newB->Pos().x > 1080 / 2)
		{
			newB->dirX = -cos(rand() % 90);
		}
		else newB->dirX = cos(rand() % 90);

		if (newB->Pos().y > 720 / 2)
		{
			newB->dirY = -sin(rand() % 90);
		}
		else newB->dirY = sin(rand() % 90);*/
		newB->dirX = cos(angle);
		newB->dirY = sin(angle);
		
		BulletList.push_back(newB);
		Time -= 1;
	}
}
