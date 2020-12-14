#pragma once

#include <iostream>

#include "glad/glad.h"   
#include "GLFW/glfw3.h"
#include "../common/Common.hpp"

class DrawShape {
public:
	DrawShape();
	~DrawShape();

	// ����������
	void drawTriangle();

	// ����������
	void drawSquare();

private:
	MyProgram* mProgram = NULL;
	unsigned int mVBO = 0, mVAO = 0;
};