#pragma once
#include "ZeroIScene.h"
#include "Bomb.h"
#include <list>
#define BombMGR BombManager::instance()

class BombManager :
	public ZeroIScene
{
public:
	float x, y; // ���� ��ǥ
	std::list<Bomb*> bombList; // ��ź ����Ʈ

	BombManager();
	~BombManager();

	void Update(float eTime);
	void Render();

	void SpawnBomb();

	static BombManager* instance();
};

