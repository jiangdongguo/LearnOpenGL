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
float mVertices1[] = {
   -0.5f, -0.5f, 0.0f,		// left
   0.5f, -0.5f, 0.0f,		// right
   0.0f, 0.5f, 0.0f		// top
};
// 顶点数组
float mVertices2[] = {
	0.5f, 0.5f, 0.0f,   // 右上角
	0.5f, -0.5f, 0.0f,  // 右下角
	-0.5f, -0.5f, 0.0f, // 左下角
	-0.5f, 0.5f, 0.0f   // 左上角
};

// 索引数组
unsigned int indices[] = { // 注意索引从0开始! 
	0, 1, 3, // 第一个三角形
	1, 2, 3  // 第二个三角形
};

DrawShape::DrawShape() 
{
	// 1. 创建顶点着色器、片段着色器
	MyShader vertexShader(mVertexShaderStr, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr, ShaderType::TYPE_FRAGMENT_SHADER);

	// 2. 创建程序对象
	mProgram = new MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	// 3. 创建VBO、VAO、EBO，链接顶点属性
	// 3.1 创建VBO、VAO、EBO对象
	mVAO = new MyVAO();
	mVAO->addVertext3D(mVertices2,sizeof(mVertices2), indices, sizeof(indices));
	// 注意：如果调用的是drawTriangle,即绘制三角形
	// 这里应该这么调用
	// mVAO->addVertext3D(mVertices1,sizeof(mVertices1), 0, NULL, 0);

	// 3.2 链接顶点属性(位置属性)，解绑VAO
	mVAO->setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	mVAO->unBindVAO();
}

void DrawShape::drawTriangle()
{	
	// 4. 使用程序
	mProgram->UseProgram();
	// 5. 绑定VAO
	mVAO->bindVAO();
	// 6. 绘制三角形
	mProgram->drawArrays(GL_TRIANGLES, 0, 3);
}

void DrawShape::drawSquare()
{
	// 4. 使用程序
	mProgram->UseProgram();
	// 5. 绑定EBO
	mVAO->bindVAO();
	// 6. 绘制正方形
	mProgram->drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

DrawShape::~DrawShape()
{
	// 7. 释放资源
	delete mVAO;
	delete mProgram;
}
