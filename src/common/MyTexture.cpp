#include "Common.hpp"

MyTexture::MyTexture()
{
	// 1. ����һ��������󣬲�����ΨһID
	glGenTextures(1, &mTextureId);

	// 2. ���������Ŀ��GL_TEXTURE_2D
	glBindTexture(GL_TEXTURE_2D, mTextureId);

	// 3. Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // ����s�ỷ�Ʒ�ʽΪGL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // ����t�ỷ�Ʒ�ʽΪGL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ������С���˷�ʽΪ���Թ���
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // ���÷Ŵ���˷�ʽΪ���Թ���
}

int MyTexture::loadImageData(unsigned char* data, int imageWidth, int imageHeight) 
{
	if (data == NULL) {
		return -1;
	}
	// 4. ����ͼƬ
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	// 5. ��������
	glGenerateMipmap(GL_TEXTURE_2D);
	return 0;
}

MyTexture::~MyTexture() 
{
	// 6. �ͷ����������Դ
	if (mTextureId != NULL) {
		glDeleteTextures(1, &mTextureId);
	}
}

int MyTexture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, mTextureId);
	return 0;
}