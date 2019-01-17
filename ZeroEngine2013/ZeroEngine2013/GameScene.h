#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroCameraManager.h"
#include <list>
#include "Player.h"
#include "Bullet.h"

class GameScene :
	public ZeroIScene
{
public:
	bool isRender;
	Bullet *testBullet;
	GameScene();
	~GameScene();
	void Update(float eTime);
	void Render();
	
};
