#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet() : speed(std::rand() % 400 + 300),
				   dirX(0), dirY(0)
{
	BulletSprite = new ZeroSprite("Resources/img/Bullet.png");
	std::cout << ScaledWidth() << std::endl;
	std::cout << dirX << " " << dirY << std::endl;
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
	if (this->BulletSprite->IsOverlapped(player->PlayerSprite))
	{
		player->isCol = true;
	}
}

bool Bullet::CircleCol(ZeroIScene* _scene){
	ZeroVec cpos1 = ZeroVec(m_fWidth * 0.5f, m_fHeight * 0.5f);
	ZeroVec cpos2 = ZeroVec(_scene->Width() * 0.5f, _scene->Height() * 0.5f);

	D3DXMATRIX mat1 = m_Mat;
	D3DXMATRIX mat2 = _scene->Mat();

	D3DXVec2TransformCoord(&cpos1, &cpos1, &mat1);
	D3DXVec2TransformCoord(&cpos2, &cpos2, &mat2);

	float len1 = ZeroVec(m_fScaledWidth, m_fScaledHeight).Length() * 0.5f;
	float len2 = ZeroVec(_scene->ScaledWidth(), _scene->ScaledHeight()).Length() * 0.5f;
	float len3 = cpos1.Distance(cpos2);

	return (len3 <= len1 + len2);
}
