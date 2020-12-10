#include "DrawShape.hpp"

DrawShape::DrawShape() 
{
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

	// 1. 创建顶点着色器、片段着色器
	MyShader vertexShader(mVertexShaderStr, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr, ShaderType::TYPE_FRAGMENT_SHADER);

	// 2. 创建程序对象
    mProgram = MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	
	// 3. 创建顶点缓冲对象(VBO)和顶点数组对象(VAO)，并链接顶点属性
	// (1) 分别创建VAO、VBO对象
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	// (2) 绑定VAO对象
	glBindVertexArray(mVAO);
	// (3) 将新创建的缓冲绑定到顶点缓冲类型GL_ARRAY_BUFFER上
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	// (4) 将顶点数据复制到缓冲的显存供OpenGL使用
	// 并指定显卡管理数据模式为GL_STATIC_DRAW，即数据不会或几乎不会改变
	glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);
	// (5) 链接顶点属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// (6) 解绑VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void DrawShape::drawTriangle()
{	
	// 4. 使用程序
	glUseProgram(mProgram.getShaderProgramId());
	// 5. 绑定VAO
	glBindVertexArray(mVAO);
	// 6. 绘制
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DrawShape::drawSquare()
{
}

DrawShape::~DrawShape()
{
	// 7. 释放资源
	glDeleteVertexArrays(1, &mVAO);
	glDeleteBuffers(1,&mVBO);
}
