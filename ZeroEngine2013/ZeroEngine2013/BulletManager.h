#pragma once
#include "ZeroIScene.h"
#include <list>
#include "Bullet.h"
#include "Player.h"
#include "BombManager.h"

#define BMGR BulletManager::instance()

class BulletManager :
	public ZeroIScene
{
public:
	float Time;
	static BulletManager* instance();
	ZeroVec Center;
	BulletManager();
	~BulletManager();

	std::list<Bullet*> BulletList;

	void Update(float eTime);
	void Render();

	void SpawnBullet();
};
