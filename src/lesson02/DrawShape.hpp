#pragma once

#include <iostream>

#include "glad/glad.h"   
#include "GLFW/glfw3.h"
#include "../common/Common.hpp"

class DrawShape {
public:
	DrawShape();
	~DrawShape();

	// 绘制三角形
	void drawTriangle();

	// 绘制正方形
	void drawSquare();

private:
	MyProgram* mProgram = NULL;
	MyVAO* mVAO = NULL;
};