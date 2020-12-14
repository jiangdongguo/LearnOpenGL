#include "Common.hpp"

MyShader::MyShader(const char* shaderStr, int type)
{	
	int success;
	char infoLog[512];

	// 1. �������ʹ���һ��Shader���󣬲�������ΨһID
	// GL_VERTEX_SHADER  ������ɫ��
	// GL_FRAGMENT_SHADER Ƭ����ɫ��
	if (type == 1) {
		mShaderId = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (type = 2){
		mShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else {
		mShaderId = glCreateShader(GL_VERTEX_SHADER);
	}
	
	// 2. ����ɫ��Դ�븽�ŵ���ɫ����
	glShaderSource(mShaderId, 1, &shaderStr, NULL);

	// 3. ������ɫ��Դ��
	// ������glGetShaderiv�������Ƿ�ɹ�
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
	// 4. �ͷ���ɫ����Դ
	if (mShaderId != 0) {
		glDeleteShader(mShaderId);
		mShaderId = 0;
	}
}

GLuint MyShader::getShaderId()
{
	return mShaderId;
}
