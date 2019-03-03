#pragma once
#include "ZeroIScene.h"
#include "Player.h"
#include "ZeroAnimation.h"
#include<iostream>

class Bomb :
	public ZeroIScene
{
public:
	float Time; // ���� �ð�
	ZeroAnimation *anim;
	ZeroSprite *bombsprite;
	Player* p;

	Bomb();
	~Bomb();

	void Update(float eTime);
	void Render();

	void SetObject();
	void Destroy();
};
