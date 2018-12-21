#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroCameraManager.h"
class GameScene :
	public ZeroIScene
{
public:
	bool isRender;
	GameScene();
	~GameScene();
	void Update(float eTime);
	void Render();
	ZeroSprite * Player;
	ZeroSprite * BackGround;
};
