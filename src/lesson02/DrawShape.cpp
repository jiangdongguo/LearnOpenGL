#include "DrawShape.hpp"

DrawShape::DrawShape() 
{
	// ������ɫ��Դ��
	const char* mVertexShaderStr = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"out vec3 outPos;\n"
		"void main()\n"
		"{\n"
		"	outPos = aPos;"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	// Ƭ����ɫ��Դ��
	const char* mFragmentShaderStr = "#version 330 core\n"
		"out vec4 rgbColor;\n"
		"in vec3 outPos;\n"
		"void main()\n"
		"{\n"
		"   rgbColor = vec4(outPos, 1.0f);\n"
		"}\n\0";

	// ��������
	const float mVertices[] = {
		-0.5f, -0.5f, 0.0f,		// left
		0.5f, -0.5f, 0.0f,		// right
		0.0f, 0.5f, 0.0f		// top
	};

	// 1. ����������ɫ����Ƭ����ɫ��
	MyShader vertexShader(mVertexShaderStr, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr, ShaderType::TYPE_FRAGMENT_SHADER);

	// 2. �����������
    mProgram = MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	
	// 3. �������㻺�����(VBO)�Ͷ����������(VAO)�������Ӷ�������
	// (1) �ֱ𴴽�VAO��VBO����
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	// (2) ��VAO����
	glBindVertexArray(mVAO);
	// (3) ���´����Ļ���󶨵����㻺������GL_ARRAY_BUFFER��
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	// (4) ���������ݸ��Ƶ�������Դ湩OpenGLʹ��
	// ��ָ���Կ���������ģʽΪGL_STATIC_DRAW�������ݲ���򼸺�����ı�
	glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);
	// (5) ���Ӷ�������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// (6) ���VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void DrawShape::drawTriangle()
{	
	// 4. ʹ�ó���
	glUseProgram(mProgram.getShaderProgramId());
	// 5. ��VAO
	glBindVertexArray(mVAO);
	// 6. ����
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DrawShape::drawSquare()
{
}

DrawShape::~DrawShape()
{
	// 7. �ͷ���Դ
	glDeleteVertexArrays(1, &mVAO);
	glDeleteBuffers(1,&mVBO);
}
