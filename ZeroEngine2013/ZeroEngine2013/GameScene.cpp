#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
	Stage = new ZeroSprite("Resources/img/Circle.png");
	Stage->SetPos(340,60);
	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetScreen(1280, 720);
}

GameScene::~GameScene()
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	BMGR->Update(eTime);
	player->Update(eTime);
	BombMGR->Update(eTime);
	//if (player->isCol)
		//ZeroSceneMgr->ChangeScene(new MainScene());
}

void GameScene::Render()
{
	ZeroIScene::Render();
	Stage->Render();
	BMGR->Render();
	player->Render();
	BombMGR->Render();
}
