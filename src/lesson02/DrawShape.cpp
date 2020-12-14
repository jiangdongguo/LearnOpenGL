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
const float mVertices[] = {
	-0.5f, -0.5f, 0.0f,		// left
	0.5f, -0.5f, 0.0f,		// right
	0.0f, 0.5f, 0.0f		// top
};

DrawShape::DrawShape() 
{
	// 1. ����������ɫ����Ƭ����ɫ��
	MyShader vertexShader(mVertexShaderStr, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr, ShaderType::TYPE_FRAGMENT_SHADER);

	// 2. �����������
	mProgram = new MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	
	// 3. �������㻺�����(VBO)�Ͷ����������(VAO)
	// �����Ӷ�������
	mVAO = new MyVAO();
	mVAO->addVertext3D(mVertices, 3, 0);
}

void DrawShape::drawTriangle()
{	
	// 4. ʹ�ó���
	mProgram->UseProgram();
	// 5. ��VAO
	mVAO->BindVAO();
	// 6. ����������
	mProgram->drawArrays(GL_TRIANGLES, 0, 3);
}

void DrawShape::drawSquare()
{
}

DrawShape::~DrawShape()
{
	// 7. �ͷ���Դ
	delete mVAO;
	delete mProgram;
}
