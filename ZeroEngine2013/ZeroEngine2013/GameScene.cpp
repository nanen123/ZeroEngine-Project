#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
	Stage = new ZeroSprite("Resources/img/Circle.png");
	Stage->SetPos(340,60);
	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetScreen(1280, 720);
	p = new Player();
	bullet = new BulletManager(p);
	Bomb = new BombManager(p);
}

GameScene::~GameScene()
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	bullet->Update(eTime);
	p->Update(eTime);
	Bomb->Update(eTime);
	if (p->isCol){
		ZeroSceneMgr->ChangeScene(new MainScene());
	}
}

void GameScene::Render()
{
	ZeroIScene::Render();
	Stage->Render();
	bullet->Render();
	p->Render();
	Bomb->Render();
}
