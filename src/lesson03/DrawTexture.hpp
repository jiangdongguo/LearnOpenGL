#pragma once

#include <iostream>

#include "../common/Common.hpp"

class DrawTexture
{
public:
	DrawTexture();
	~DrawTexture();

	int drawTexture();

private:
	MyTexture* mTexture = NULL;
	MyProgram* mProgram = NULL;
	MyVAO* mVAO = NULL;
};

