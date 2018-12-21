#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetSpeed(0);
	ZeroCameraMgr->SetPos(0, 0);
	Player = new ZeroSprite("Resources/img/Circle.png");
	BackGround = new ZeroSprite("Resources/BackGround/BackGround.png");
	isRender = true;
}

GameScene::~GameScene()
{
	isRender = false;
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x + 200 * eTime, ZeroCameraMgr->Pos().y);
	}
	if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x - 200 * eTime, ZeroCameraMgr->Pos().y);
	}
	if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x, ZeroCameraMgr->Pos().y - 200 * eTime);
	}
	if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON){
		ZeroCameraMgr->SetPos(ZeroCameraMgr->Pos().x, ZeroCameraMgr->Pos().y + 200 * eTime);
	}
	if (ZeroInputMgr->GetKey('A') == INPUTMGR_KEYDOWN){
		isRender = !isRender;
	}
}
void GameScene::Render()
{
	ZeroIScene::Render();
	BackGround->Render();
	if (isRender){
		Player->Render();
	}
}
