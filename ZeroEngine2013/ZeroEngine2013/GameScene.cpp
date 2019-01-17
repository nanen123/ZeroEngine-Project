#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetScreen(1280, 720);
	testBullet = new Bullet();
}

GameScene::~GameScene()
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	testBullet->Update(eTime);
	player->Update(eTime);
	
}

void GameScene::Render()
{
	ZeroIScene::Render();
	testBullet->Render();
	player->Render();
}
