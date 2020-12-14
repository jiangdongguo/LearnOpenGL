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
	int drawElements(GLenum mode, GLsizei count, GLenum type, const void* indices);

private:
	GLuint mShaderProgramId = NULL;
};

class MyEBO
{
public:
	MyEBO();
	~MyEBO();

	int addIndexData(unsigned int indices[], int indicesSize);

private:
	GLuint mEBOId = NULL;
};


class MyVAO
{
public:
	MyVAO();
	~MyVAO();
	 
	// 添加坐标数据
	// data 3D坐标数据
	int addVertext3D(float data[], int dataSize, int layout, unsigned int indices[], int indicesSize);

	// 绑定VAO
	int BindVAO();

private:
	MyEBO* mEBO = NULL;
	GLuint mVAOId = NULL;
	std::vector<GLuint> mVBOIdList;
};