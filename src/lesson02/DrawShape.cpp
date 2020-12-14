#include "DrawShape.hpp"

// 顶点着色器源码
const char* mVertexShaderStr = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"out vec3 outPos;\n"
"void main()\n"
"{\n"
"	outPos = aPos;"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
// 片段着色器源码
const char* mFragmentShaderStr = "#version 330 core\n"
"out vec4 rgbColor;\n"
"in vec3 outPos;\n"
"void main()\n"
"{\n"
"   rgbColor = vec4(outPos, 1.0f);\n"
"}\n\0";

// 顶点数据
const float mVertices[] = {
	-0.5f, -0.5f, 0.0f,		// left
	0.5f, -0.5f, 0.0f,		// right
	0.0f, 0.5f, 0.0f		// top
};

DrawShape::DrawShape() 
{
	// 1. 创建顶点着色器、片段着色器
	MyShader vertexShader(mVertexShaderStr, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr, ShaderType::TYPE_FRAGMENT_SHADER);

	// 2. 创建程序对象
	mProgram = new MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	
	// 3. 创建顶点缓冲对象(VBO)和顶点数组对象(VAO)
	// 并链接顶点属性
	mVAO = new MyVAO();
	mVAO->addVertext3D(mVertices, 3, 0);
}

void DrawShape::drawTriangle()
{	
	// 4. 使用程序
	mProgram->UseProgram();
	// 5. 绑定VAO
	mVAO->BindVAO();
	// 6. 绘制三角形
	mProgram->drawArrays(GL_TRIANGLES, 0, 3);
}

void DrawShape::drawSquare()
{
}

DrawShape::~DrawShape()
{
	// 7. 释放资源
	delete mVAO;
	delete mProgram;
}
