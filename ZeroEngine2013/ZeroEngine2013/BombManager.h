#pragma once
#include "ZeroIScene.h"
#include "Bomb.h"
#include <list>
#define BombMGR BombManager::instance()

class BombManager :
	public ZeroIScene
{
public:
	float x, y; // 积己 谅钎
	std::list<Bomb*> bombList; // 气藕 府胶飘

	BombManager();
	~BombManager();

	void Update(float eTime);
	void Render();

	void SpawnBomb();

	static BombManager* instance();
};

