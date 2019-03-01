#include "stdafx.h"
#include "Util.h"


Util::Util() : Center(640, 360)
{
}


Util::~Util()
{
}

Util* Util::instance()
{
	static Util ut;
	return &ut;
}