#include "Common.hpp"

MyEBO::MyEBO() {
	// 1. 创建一个EBO对象，并返回对应的ID
	glGenBuffers(1, &mEBOId);
}

int MyEBO::addIndexData(unsigned int indices[], int indicesSize) {
	// 2. 绑定EBO对象到目标类型GL_ELEMENT_ARRAY_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBOId);
	// 3. 拷贝索引数据到EBO缓存
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
	return 0;
}

MyEBO::~MyEBO() {
	// 4. 释放资源
	if (mEBOId != NULL) {
		glDeleteBuffers(1, &mEBOId);
	}
}