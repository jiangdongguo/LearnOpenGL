#include "Common.hpp"

MyProgram::MyProgram(GLuint vertexShaderId, GLuint fragmentShaderId) {
	int success;
	char infoLog[512];

	// 1. 创建一个程序对象，并返回该对象的ID引用
	mShaderProgramId = glCreateProgram();

	// 2. 将编译好的着色器附加到程序对象
	glAttachShader(mShaderProgramId, vertexShaderId);
	glAttachShader(mShaderProgramId, fragmentShaderId);
	
	// 3. 链接这些着色器
	// 并调用glGetProgramiv检查是否链接成功
	glLinkProgram(mShaderProgramId);
	glGetProgramiv(mShaderProgramId, GL_LINK_STATUS, &success);
	if (!success) {
		glDeleteProgram(mShaderProgramId);
		glGetProgramInfoLog(mShaderProgramId, 512, NULL, infoLog);
		printf(infoLog);
		std::cout << "link shader failed\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	std::cout << "create program success\n" << std::endl;
}

MyProgram::~MyProgram() {
	// 5. 释放资源
	if (mShaderProgramId != NULL) {
		glDeleteProgram(mShaderProgramId);
		mShaderProgramId = NULL;
	}
}

int MyProgram::UseProgram()
{
	// 4. 使用着色器程序
	glUseProgram(mShaderProgramId);
	return 0;
}

int MyProgram::drawArrays(GLenum mode, GLint first, GLsizei count)
{
	glDrawArrays(mode, first, count);
	return 0;
}

int MyProgram::drawElement()
{
	return 0;
}

