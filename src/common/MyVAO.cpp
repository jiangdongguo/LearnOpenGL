#include "Common.hpp"

MyVAO::MyVAO()
{
	// 1. 创建VAO对象
	glGenVertexArrays(1, &mVAOId);
}

int MyVAO::addVertext3D(float data[], int dataSize, unsigned int indices[], int indicesSize)
{
	// 2. 创建VBO，拷贝数据到GPU显存，再配置顶点属性
	// (1) 分别创建VAO对象
	GLuint vboId = NULL;
	GLuint mEBOId = NULL;
	glGenBuffers(1, &vboId);
	glGenBuffers(1, &mEBOId);
	// (2) 绑定VAO对象
	glBindVertexArray(mVAOId);
	// (3) 将新创建的缓冲绑定到顶点缓冲类型GL_ARRAY_BUFFER上
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	// (4) 将顶点数据复制到缓冲的显存供OpenGL使用
	// 并指定显卡管理数据模式为GL_STATIC_DRAW，即数据不会或几乎不会改变
    glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

	if (indices != NULL) {
		mEBO = new MyEBO();
		mEBO->addIndexData(indices, indicesSize);
	}

	mVBOIdList.push_back(vboId);
	return 0;
}

void MyVAO::setVertexAttribPointer(GLuint layout, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
	// (5) 链接顶点属性
	glVertexAttribPointer(layout, size, type, normalized, stride, pointer);
	glEnableVertexAttribArray(layout);
}

int MyVAO::bindVAO()
{
	glBindVertexArray(mVAOId);
	return 0;
}

int MyVAO::unBindVAO()
{
	// (6) 解绑VAO, VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return 0;
}

MyVAO::~MyVAO()
{
	if (mEBO != NULL) {
		delete mEBO;
	}

	// 4. 释放资源
	// (1) 释放VBO资源
	for (int i = 0; i < mVBOIdList.size(); i++) {
		GLuint vboId = mVBOIdList[i];
		if (vboId != NULL) {
			glDeleteBuffers(1, &vboId);
			vboId = NULL;
		}
	}
	mVBOIdList.clear();
	// (2) 释放VAO资源
	if (mVAOId != NULL) {
		glDeleteVertexArrays(1, &mVAOId);
		mVAOId = NULL;
	}
}
