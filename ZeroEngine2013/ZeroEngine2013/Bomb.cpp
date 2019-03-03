#include "stdafx.h"
#include "Bomb.h"


Bomb::Bomb() : Time(0)
{
	bombsprite = new ZeroSprite("Resources/img/Bomb.png");
	anim = new ZeroAnimation(20);
}


Bomb::~Bomb()
{

}

void Bomb::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	Time += eTime;
	if (this->bombsprite->IsOverlapped(p->PlayerSprite))
	{
		p->isCol = true;
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

void Bomb::Destroy()
{
	delete this;
}