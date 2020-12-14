#include "Common.hpp"

MyProgram::MyProgram(GLuint vertexShaderId, GLuint fragmentShaderId) {
	int success;
	char infoLog[512];

	// 1. ����һ��������󣬲����ظö����ID����
	mShaderProgramId = glCreateProgram();

	// 2. ������õ���ɫ�����ӵ��������
	glAttachShader(mShaderProgramId, vertexShaderId);
	glAttachShader(mShaderProgramId, fragmentShaderId);
	
	// 3. ������Щ��ɫ��
	// ������glGetProgramiv����Ƿ����ӳɹ�
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
		mShaderProgramId = 0;
	}
}

int MyProgram::UseProgram()
{
	glUseProgram(mShaderProgramId);
	return 0;
}

