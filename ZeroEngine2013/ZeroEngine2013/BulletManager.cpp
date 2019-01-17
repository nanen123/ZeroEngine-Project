#include "stdafx.h"
#include "BulletManager.h"


BulletManager::BulletManager()
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
	for (auto iter = BulletList.begin(); iter != BulletList.end(); iter++)
	{
		(*iter)->Update(eTime);
	}
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
	BulletList.push_back(new Bullet());
}