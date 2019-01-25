#pragma once
#include "ZeroIScene.h"
#include <list>
#include "Bullet.h"

#define BMGR BulletManager::instance()

class BulletManager :
	public ZeroIScene
{
public:
	float Time;
	static BulletManager* instance();

	BulletManager();
	~BulletManager();

	std::list<Bullet*> BulletList;

	void Update(float eTime);
	void Render();

	void SpawnBullet();
};
