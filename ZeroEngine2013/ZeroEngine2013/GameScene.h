#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroCameraManager.h"
#include <list>
#include "Player.h"
#include "BulletManager.h"
#include "MainScene.h"
#include "ZeroSceneManager.h"

class GameScene :
	public ZeroIScene
{
public:
	bool isRender;
	ZeroSprite* Stage;

	GameScene();
	~GameScene();

	void Update(float eTime);
	void Render();
	
};
