#pragma once
#include "ZeroIScene.h"
#include <list>
#include "Bullet.h"
#include "Player.h"
#include "BombManager.h"


class BulletManager :
	public ZeroIScene
{
public:
	float Time;
	Player* p;

	ZeroVec Center;
	BulletManager(Player* p);
	~BulletManager();

	std::list<Bullet*> BulletList;

	void Update(float eTime);
	void Render();

	void SpawnBullet();
};
