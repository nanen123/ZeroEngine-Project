#include "stdafx.h"
#include "MainScene.h"
#include<iostream>

MainScene::MainScene()
{
	Enemy = new ZeroSprite("Resources/img/Square.png");
	Enemy->SetPos(100, 100);
	Button = new ZeroSprite("Resources/img/Button.png");
	Button->SetPos(500, 500);
}


MainScene::~MainScene()
{
}

void MainScene::Update(float eTime){
	ZeroIScene::Update(eTime);
	//Enemy->AddPos(100 * eTime, 100 * eTime);
	//Enemy->AddScale(0.1, 0.1);
	//Enemy->AddRot(10);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN){
		if (Button->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new GameScene());
			return;
		}
	}
}

void MainScene::Render(){
	ZeroIScene::Render();
	Enemy->Render();
	Button->Render();
}