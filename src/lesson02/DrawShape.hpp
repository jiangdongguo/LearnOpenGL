#pragma once

#include "../common/Common.hpp"

class DrawShape {
public:
	DrawShape();
	~DrawShape();

	// 绘制三角形
	void drawTriangle();

	// 绘制正方形
	void drawSquare();
	void drawSquareOfUniform();

private:
	MyProgram* mProgram = NULL;
	MyVAO* mVAO = NULL;
};