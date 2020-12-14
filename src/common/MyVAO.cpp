#include "Common.hpp"

MyVAO::MyVAO()
{
	// 1. 创建VAO对象
	glGenVertexArrays(1, &mVAOId);
}

int MyVAO::addVertext3D(const float* data, int vertexCount, int layout)
{
	// 2. 创建VBO，拷贝数据到GPU显存，再配置顶点属性
	// (1) 分别创建VAO对象
	GLuint vboId = 0;
	glGenBuffers(1, &vboId);
	// (2) 绑定VAO对象
	glBindVertexArray(mVAOId);
	// (3) 将新创建的缓冲绑定到顶点缓冲类型GL_ARRAY_BUFFER上
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	// (4) 将顶点数据复制到缓冲的显存供OpenGL使用
	// 并指定显卡管理数据模式为GL_STATIC_DRAW，即数据不会或几乎不会改变
	glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(data), data, GL_STATIC_DRAW);
	// (5) 链接顶点属性
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(layout);
	// (6) 解绑VAO, VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	mVBOIdList.push_back(vboId);
	return 0;
}

int MyVAO::BindVAO()
{
	// 3. 绑定VAO
	glBindVertexArray(mVAOId);
	return 0;
}

MyVAO::~MyVAO()
{
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
