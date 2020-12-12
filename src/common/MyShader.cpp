#include "Common.hpp"

MyShader::MyShader(const char* shaderStr, int type)
{	
	int success;
	char infoLog[512];

	// 1. 根据类型创建一个Shader对象，并返回其唯一ID
	// GL_VERTEX_SHADER  顶点着色器
	// GL_FRAGMENT_SHADER 片段着色器
	if (type == 1) {
		mShaderId = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (type = 2){
		mShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else {
		mShaderId = glCreateShader(GL_VERTEX_SHADER);
	}
	
	// 2. 将着色器源码附着到着色器上
	glShaderSource(mShaderId, 1, &shaderStr, NULL);

	// 3. 编译着色器源码
	// 并调用glGetShaderiv检查编译是否成功
	glCompileShader(mShaderId);
	glGetShaderiv(mShaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		glDeleteShader(mShaderId);
		glGetShaderInfoLog(mShaderId, 512, NULL, infoLog);
		std::cout << "compile shader failed\n" << infoLog << std::endl;
	}
	std::cout << "create shader success\n" << type << std::endl;
}

MyShader::~MyShader() 
{
	// 4. 释放着色器资源
	if (mShaderId != 0) {
		glDeleteShader(mShaderId);
		mShaderId = 0;
	}
}

GLuint MyShader::getShaderId()
{
	return mShaderId;
}
