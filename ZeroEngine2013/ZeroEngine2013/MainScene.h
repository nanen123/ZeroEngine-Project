#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "GameScene.h"
class MainScene : public ZeroIScene
{
public:
	MainScene();
	~MainScene();
	void Update(float eTime);
	void Render();
	ZeroSprite * Enemy;
	ZeroSprite * Button;
};

