#include "stdafx.h"
#include "BombManager.h"


BombManager::BombManager()
{

}


BombManager::~BombManager()
{
}

void BombManager::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	for (auto iter = bombList.begin(); iter != bombList.end(); iter++)
	{
		(*iter)->Update(eTime);
	}
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
	Bomb* bomb = new Bomb();
	bomb->AddPos(rand() % int(player->Pos().x + 30) - 30, rand() % int(player->Pos().y + 30) - 30);
	bombList.push_back(bomb);
}

BombManager *BombManager::instance()
{
	static BombManager bmgr;
	return &bmgr;
}