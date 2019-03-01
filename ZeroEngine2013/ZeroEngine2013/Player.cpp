#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	SetPlayer();
	SetSprite();
}

void Player::SetPlayer()
{
	this->SetPos(640, 360);
	velX = 0; velY = 0;
	isOut = false; isCol = false;
}

Player::~Player()
{
}

void Player::SetSprite()
{
	PlayerSprite = new ZeroSprite("Resources/img/Player.png");
	ResourceList.push_back(PlayerSprite);
}

void Player::SetObject()
{
	for (auto iter = ResourceList.begin(); iter != ResourceList.end(); iter++)
	{
		(*iter)->SetPos(this->Pos().x, this->Pos().y);
	}
}

void Player::CheckDistance()
{
	if (this->Pos().Distance(util->Center) > 300)
	{
		isOut = true;
	}
	else isOut = false;
	if (isOut)
	{
		velX *= -2;
		velY *= -2;
	}
}

void Player::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	Move(eTime);
	CheckDistance();
	SetObject();

}

void Player::Move(float eTime)
{
	if (velX > 0)
		velX -= 10.0f;
	else if (velX < 0)
		velX += 10.0f;

	if (velY > 0)
		velY -= 10.0f;
	else if (velY < 0)
		velY += 10.0f;

	if (ZeroInputMgr->GetKey(VK_RIGHT) == INPUTMGR_KEYON){
		if (velX < 300)
			velX += 30;
	}
	if (ZeroInputMgr->GetKey(VK_LEFT) == INPUTMGR_KEYON){
		if (velX > -300)
			velX -= 30;
	}

	if (ZeroInputMgr->GetKey(VK_UP) == INPUTMGR_KEYON){
		if (velY > -300)
			velY -= 30;
	}
	if (ZeroInputMgr->GetKey(VK_DOWN) == INPUTMGR_KEYON){
		if (velY < 300)
			velY += 30;
	}

	this->AddPos(velX * eTime, velY * eTime);
}

void Player::Render()
{
	ZeroIScene::Render();
	PlayerSprite->Render();
}

Player* Player::instance()
{
	static Player p1;
	return &p1;
}
