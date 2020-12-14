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
	// 5. �ͷ���Դ
	if (mShaderProgramId != NULL) {
		glDeleteProgram(mShaderProgramId);
		mShaderProgramId = NULL;
	}
}

int MyProgram::UseProgram()
{
	// 4. ʹ����ɫ������
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

