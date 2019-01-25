#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include <list>
#include<iostream>
using namespace std;
#define player Player::instance()
class Player :
	public ZeroIScene
{
public:
	float velX;
	float velY;

	bool isOut;
	bool isCol;

	ZeroVec Center;

	static Player* instance();
	ZeroSprite* PlayerSprite;
	list<ZeroSprite*> ResourceList;

	Player();
	~Player();

	void SetSprite();
	void SetObject();
	void Update(float eTime);
	void Render();

	void Move(float eTime);
	void CheckDistance();
};

