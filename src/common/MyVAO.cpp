#include "Common.hpp"

MyVAO::MyVAO()
{
	// 1. ����VAO����
	glGenVertexArrays(1, &mVAOId);
}

int MyVAO::addVertext3D(const float* data, int vertexCount, int layout)
{
	// 2. ����VBO���������ݵ�GPU�Դ棬�����ö�������
	// (1) �ֱ𴴽�VAO����
	GLuint vboId = 0;
	glGenBuffers(1, &vboId);
	// (2) ��VAO����
	glBindVertexArray(mVAOId);
	// (3) ���´����Ļ���󶨵����㻺������GL_ARRAY_BUFFER��
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	// (4) ���������ݸ��Ƶ�������Դ湩OpenGLʹ��
	// ��ָ���Կ���������ģʽΪGL_STATIC_DRAW�������ݲ���򼸺�����ı�
	glBufferData(GL_ARRAY_BUFFER, vertexCount * 3 * sizeof(data), data, GL_STATIC_DRAW);
	// (5) ���Ӷ�������
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(layout);
	// (6) ���VAO, VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	mVBOIdList.push_back(vboId);
	return 0;
}

int MyVAO::BindVAO()
{
	// 3. ��VAO
	glBindVertexArray(mVAOId);
	return 0;
}

MyVAO::~MyVAO()
{
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
