#pragma once

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
	MyVAO* mVAO = NULL;
};