#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"

class Bullet :
	public ZeroIScene
{
public:
	ZeroSprite* BulletSprite;

	float speed;

	Bullet();
	~Bullet();

	void Update(float eTime);
	void Render();

	void SetObejct();
};
