#include "stdafx.h"
#include "BulletManager.h"


BulletManager::BulletManager() : Time(0)
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
		BulletList.push_back(new Bullet());
		Time -= 1;
	}
}