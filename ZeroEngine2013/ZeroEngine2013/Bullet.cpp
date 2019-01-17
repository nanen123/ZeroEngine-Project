#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet() : speed(std::rand() % 300)
{
	BulletSprite = new ZeroSprite("Resources/img/Bullet.png");
}


Bullet::~Bullet()
{

}

void Bullet::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	this->AddPosY(speed * eTime);
	SetObejct();
}

void Bullet::Render()
{
	ZeroIScene::Render();
	BulletSprite->Render();
}

void Bullet::SetObejct()
{
	BulletSprite->SetPos(this->Pos());
}