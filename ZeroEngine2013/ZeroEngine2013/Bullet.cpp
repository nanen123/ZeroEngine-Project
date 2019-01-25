#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet() : speed(std::rand() % 300 + 100),
Sx(rand() % 1080), Sy(rand() % 720),
dirX(0), dirY(0)
{
	BulletSprite = new ZeroSprite("Resources/img/Bullet.png");
	this->Pos().x = Sx;
	this->Pos().y = Sy;

	if (this->Pos().x > 1080 / 2)
	{
		dirX = -1;
	}
	else dirX = 1;

	if (this->Pos().y > 720 / 2)
	{
		dirY = -1;
	}
	else dirY = 1;
}


Bullet::~Bullet()
{

}

void Bullet::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	this->AddPosY(speed * eTime * dirY);
	this->AddPosX(speed * eTime * dirX);
	SetObejct();
	CheckCol();
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

void Bullet::CheckCol(){
	if (/*this->Pos().Distance(player->Pos()) < 30*/IsOverlapped(player))
	{
		player->isCol = true;
	}
}
