#pragma once

#include <iostream>
#include <vector>
#include "glad/glad.h"   
#include "GLFW/glfw3.h"

enum class ShaderType
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
	GLuint mShaderId = NULL;
};


class MyProgram
{
public:
	MyProgram(GLuint vertexShaderId, GLuint fragmentShaderId);
	~MyProgram();

	int UseProgram();
	int drawArrays(GLenum mode, GLint first, GLsizei count);
	int drawElement();

private:
	GLuint mShaderProgramId = NULL;
};


class MyVAO
{
public:
	MyVAO();
	~MyVAO();
	 
	// 添加坐标数据
	// data 3D坐标数据
	// vertexCount 
	// layout
	int addVertext3D(const float* data, int vertexCount, int layout);

	// 绑定VAO
	int BindVAO();

private:
	GLuint mVAOId = NULL;
	std::vector<GLuint> mVBOIdList;
};