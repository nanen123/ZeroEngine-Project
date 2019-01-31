#include "stdafx.h"
#include "Bomb.h"


Bomb::Bomb() : Time(0)
{
	bombsprite = new ZeroSprite("Resources/img/Bomb.png");
}


Bomb::~Bomb()
{

}

void Bomb::Update(float eTime)
{
	ZeroIScene::Update(eTime);

	if (this->Pos().Distance(player->Pos()) < 32)
	{
		player->isCol = true;
	}

	SetObject();
}

void Bomb::Render()
{
	ZeroIScene::Render();
	bombsprite->Render();
}

void Bomb::SetObject()
{
	bombsprite->SetPos(this->Pos());
}
