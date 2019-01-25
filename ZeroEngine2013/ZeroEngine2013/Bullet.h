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

	float speed;
	int Sx, Sy;
	int dirX, dirY;

	Bullet();
	~Bullet();

	void Update(float eTime);
	void Render();

	void SetObejct();
	void CheckCol();
};
