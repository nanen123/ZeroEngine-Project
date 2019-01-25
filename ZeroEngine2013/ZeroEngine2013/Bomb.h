#pragma once
#include "ZeroIScene.h"

class Bomb :
	public ZeroIScene
{
public:
	Bomb();
	~Bomb();

	void Update(float eTime);
	void Render();
};

