// LearnOpenGL.cpp: 定义应用程序的入口点。
// Create by jiangdongguo on 2020-12-10

#include "LearnOpenGL.h"

using namespace std;

int main()
{
	CreateWindow* mCreateWindow = new CreateWindow();
	DrawShape* mLsn02 = new DrawShape();

	while (! mCreateWindow->isWindowShouldClose()) {
		mCreateWindow->checkCancelWindowEvent();
		mCreateWindow->clearWindow();

		// 绘制三角形
	    // mLsn02->drawTriangle();
		// 绘制正方形
	     mLsn02->drawSquare();

		mCreateWindow->swapBuffers();
	}

	delete mLsn02;
	return 0;
}

