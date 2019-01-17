#include "stdafx.h"
#include "Player.h"


Player::Player() : velX(0), velY(0), Center(640, 360), isOut(false)
{
	SetSprite();
	this->SetPos(640, 360);
	cout << Center.x << endl;
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
		(*iter)->SetPos(this->Pos());
	}
}

void Player::CheckDistance()
{
	if (Center.Distance(this->Pos()) > 300)
	{
		isOut = true;
	}
	else isOut = false;

	if (isOut)
	{
		velX *= -1;
		velY *= -1;
	}
}

void Player::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	CheckDistance();
	Move(eTime);
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
