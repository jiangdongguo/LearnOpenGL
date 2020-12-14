#include "Common.hpp"

MyShader::MyShader(const char* shaderStr, ShaderType type)
{	
	int success;
	char infoLog[512];

	// 1. �������ʹ���һ��Shader���󣬲�������ΨһID
	// GL_VERTEX_SHADER  ������ɫ��
	// GL_FRAGMENT_SHADER Ƭ����ɫ��
	if (type == ShaderType::TYPE_FRAGMENT_SHADER){
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
}

MyShader::~MyShader() 
{
	// 4. �ͷ���ɫ����Դ
	if (mShaderId != NULL) {
		glDeleteShader(mShaderId);
		mShaderId = NULL;
	}
}

GLuint MyShader::getShaderId()
{
	return mShaderId;
}
