#include "Common.hpp"

MyProgram::MyProgram()
{
}

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
	if (mShaderProgramId != NULL) {
		glDeleteProgram(mShaderProgramId);
	}
}

GLuint MyProgram::getShaderProgramId()
{
	return mShaderProgramId;
}

