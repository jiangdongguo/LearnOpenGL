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

class MyTexture 
{
public:
	MyTexture();
	~MyTexture();

	int loadImageData(unsigned char* data, int imageWidth, int imageHeight);
	int bindTexture();

private:
	GLuint mTextureId = NULL;
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
	int addVertext3D(float data[], int dataSize, unsigned int indices[], int indicesSize);

	void setVertexAttribPointer(GLuint layout, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);

	// 绑定VAO
	int bindVAO();

	// 解绑VAO
	int unBindVAO();

private:
	MyEBO* mEBO = NULL;
	GLuint mVAOId = NULL;
	std::vector<GLuint> mVBOIdList;
};