#include "Common.hpp"

MyTexture::MyTexture()
{
	// 1. 生成一个纹理对象，并返回唯一ID
	glGenTextures(1, &mTextureId);

	// 2. 绑定纹理对象到目标GL_TEXTURE_2D
	glBindTexture(GL_TEXTURE_2D, mTextureId);

	// 3. 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // 设置s轴环绕方式为GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // 设置t轴环绕方式为GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 设置缩小过滤方式为线性过滤
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置放大过滤方式为线性过滤
}

int MyTexture::loadImageData(unsigned char* data, int imageWidth, int imageHeight) 
{
	if (data == NULL) {
		return -1;
	}
	// 4. 加载图片
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	// 5. 生成纹理
	glGenerateMipmap(GL_TEXTURE_2D);
	return 0;
}

MyTexture::~MyTexture() 
{
	// 6. 释放纹理对象资源
	if (mTextureId != NULL) {
		glDeleteTextures(1, &mTextureId);
	}
}

int MyTexture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, mTextureId);
	return 0;
}