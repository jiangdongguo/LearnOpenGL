#include "Common.hpp"

MyEBO::MyEBO() {
	// 1. ����һ��EBO���󣬲����ض�Ӧ��ID
	glGenBuffers(1, &mEBOId);
}

int MyEBO::addIndexData(unsigned int indices[], int indicesSize) {
	// 2. ��EBO����Ŀ������GL_ELEMENT_ARRAY_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBOId);
	// 3. �����������ݵ�EBO����
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
	return 0;
}

MyEBO::~MyEBO() {
	// 4. �ͷ���Դ
	if (mEBOId != NULL) {
		glDeleteBuffers(1, &mEBOId);
	}
}