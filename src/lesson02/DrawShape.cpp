#include "DrawShape.hpp"

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
float mVertices1[] = {
   -0.5f, -0.5f, 0.0f,		// left
   0.5f, -0.5f, 0.0f,		// right
   0.0f, 0.5f, 0.0f		// top
};
// ��������
float mVertices2[] = {
	0.5f, 0.5f, 0.0f,   // ���Ͻ�
	0.5f, -0.5f, 0.0f,  // ���½�
	-0.5f, -0.5f, 0.0f, // ���½�
	-0.5f, 0.5f, 0.0f   // ���Ͻ�
};

// ��������
unsigned int indices[] = { // ע��������0��ʼ! 
	0, 1, 3, // ��һ��������
	1, 2, 3  // �ڶ���������
};

DrawShape::DrawShape() 
{
	// 1. ����������ɫ����Ƭ����ɫ��
	MyShader vertexShader(mVertexShaderStr, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr, ShaderType::TYPE_FRAGMENT_SHADER);

	// 2. �����������
	mProgram = new MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	// 3. ����VBO��VAO��EBO�����Ӷ�������
	// 3.1 ����VBO��VAO��EBO����
	mVAO = new MyVAO();
	mVAO->addVertext3D(mVertices2,sizeof(mVertices2), indices, sizeof(indices));
	// ע�⣺������õ���drawTriangle,������������
	// ����Ӧ����ô����
	// mVAO->addVertext3D(mVertices1,sizeof(mVertices1), 0, NULL, 0);

	// 3.2 ���Ӷ�������(λ������)�����VAO
	mVAO->setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	mVAO->unBindVAO();
}

void DrawShape::drawTriangle()
{	
	// 4. ʹ�ó���
	mProgram->UseProgram();
	// 5. ��VAO
	mVAO->bindVAO();
	// 6. ����������
	mProgram->drawArrays(GL_TRIANGLES, 0, 3);
}

void DrawShape::drawSquare()
{
	// 4. ʹ�ó���
	mProgram->UseProgram();
	// 5. ��EBO
	mVAO->bindVAO();
	// 6. ����������
	mProgram->drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

DrawShape::~DrawShape()
{
	// 7. �ͷ���Դ
	delete mVAO;
	delete mProgram;
}
