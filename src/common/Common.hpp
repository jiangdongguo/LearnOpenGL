#pragma once

#include <iostream>

#include "glad/glad.h"   
#include "GLFW/glfw3.h"


enum ShaderType
{
	TYPE_VERTEX_SHADER = 1,
	TYPE_FRAGMENT_SHADER = 2
};

class MyShader
{
public:
	MyShader(const char* shaderStr, ShaderType type);
	~MyShader();

	GLuint getShaderId();

private:
	GLuint mShaderId = 0;
};


class MyProgram
{
public:
	MyProgram();
	MyProgram(GLuint vertexShaderId, GLuint fragmentShaderId);
	~MyProgram();

	GLuint getShaderProgramId();

private:
	GLuint mShaderProgramId = 0;
};