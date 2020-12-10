// LearnOpenGL.cpp: 定义应用程序的入口点。
// Create by jiangdongguo on 20201210

#include "LearnOpenGL.h"

using namespace std;

int main()
{
	CreateWindow* mCreateWindow = new CreateWindow();

	while (! mCreateWindow->isWindowShouldClose()) {
		mCreateWindow->checkCancelWindowEvent();

		// render
		// ...

		mCreateWindow->clearWindowAndSwapBuffers();
	}

	return 0;
}

