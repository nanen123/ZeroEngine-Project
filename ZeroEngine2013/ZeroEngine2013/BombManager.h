#pragma once
#include "ZeroIScene.h"
#include "Bomb.h"
#include <list>
#define BombMGR BombManager::instance()

class BombManager :
	public ZeroIScene
{
public:
	ZeroVec Center;
	float Time;
	std::list<Bomb*> bombList; // ÆøÅº ¸®½ºÆ®

	BombManager();
	~BombManager();

	void Update(float eTime);
	void Render();

	void SpawnBomb();
	void Destroy();

	static BombManager* instance();
};

