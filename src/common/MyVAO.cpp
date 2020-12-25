#include "Common.hpp"

MyVAO::MyVAO()
{
	// 1. ����VAO����
	glGenVertexArrays(1, &mVAOId);
}

int MyVAO::addVertext3D(float data[], int dataSize, unsigned int indices[], int indicesSize)
{
	// 2. ����VBO���������ݵ�GPU�Դ棬�����ö�������
	// (1) �ֱ𴴽�VAO����
	GLuint vboId = NULL;
	GLuint mEBOId = NULL;
	glGenBuffers(1, &vboId);
	glGenBuffers(1, &mEBOId);
	// (2) ��VAO����
	glBindVertexArray(mVAOId);
	// (3) ���´����Ļ���󶨵����㻺������GL_ARRAY_BUFFER��
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	// (4) ���������ݸ��Ƶ�������Դ湩OpenGLʹ��
	// ��ָ���Կ���������ģʽΪGL_STATIC_DRAW�������ݲ���򼸺�����ı�
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
	// (5) ���Ӷ�������
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
	// (6) ���VAO, VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return 0;
}

MyVAO::~MyVAO()
{
	if (mEBO != NULL) {
		delete mEBO;
	}

	// 4. �ͷ���Դ
	// (1) �ͷ�VBO��Դ
	for (int i = 0; i < mVBOIdList.size(); i++) {
		GLuint vboId = mVBOIdList[i];
		if (vboId != NULL) {
			glDeleteBuffers(1, &vboId);
			vboId = NULL;
		}
	}
	mVBOIdList.clear();
	// (2) �ͷ�VAO��Դ
	if (mVAOId != NULL) {
		glDeleteVertexArrays(1, &mVAOId);
		mVAOId = NULL;
	}
}
