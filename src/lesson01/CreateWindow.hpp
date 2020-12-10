#pragma once

#include <iostream>

#include "glad/glad.h"   
#include "GLFW/glfw3.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

class CreateWindow {
public: 
	CreateWindow();
	~CreateWindow();

	bool isWindowShouldClose();
	void checkCancelWindowEvent();
	void clearWindow();
	void swapBuffers();

private: 
	const unsigned int WINDWO_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 600;

	GLFWwindow* window = NULL;
};
