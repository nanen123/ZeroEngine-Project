#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "Player.h"
#include <iostream>

class Bullet :
	public ZeroIScene
{
public:
	ZeroSprite* BulletSprite;
	Player* p;

	float speed;
	int Sx, Sy;
	float dirX, dirY;


	Bullet();
	~Bullet();

	void Update(float eTime);
	void Render();

	void SetObejct();
	void CheckCol();

	bool CircleCol(ZeroIScene* _scene);
};
