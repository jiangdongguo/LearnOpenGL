// LearnOpenGL.cpp: 定义应用程序的入口点。
// Create by jiangdongguo on 2020-12-10

#include "LearnOpenGL.h"

using namespace std;

int main()
{
	CreateWindow* mLsn01 = new CreateWindow();
	DrawShape* mLsn02 = new DrawShape();
	DrawTexture* mLsn03 = new DrawTexture();

	while (!mLsn01->isWindowShouldClose()) {
		mLsn01->checkCancelWindowEvent();
		mLsn01->clearWindow();

		// 绘制三角形
	    // mLsn02->drawTriangle();
		// 绘制正方形
	    // mLsn02->drawSquare();
		mLsn02->drawSquareOfUniform();
		// 绘制纹理
		//mLsn03->drawTexture();

		 mLsn01->swapBuffers();
	}

	delete mLsn02;
	return 0;
}

