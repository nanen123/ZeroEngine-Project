#pragma once
#include "ZeroIScene.h"
#define util Util::instance()

class Util :
	public ZeroIScene
{
public:
	ZeroVec Center;
	Util();
	~Util();

	static Util* instance();
};
