#include "DrawTexture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// 顶点着色器源码
const char* mVertexShaderStr3 = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec2 aTextureCoord;\n"
"out vec3 ourColor;\n"
"out vec2 ourTextureCoord;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"	ourColor = aColor;\n"
"	ourTextureCoord = aTextureCoord;\n"
"}\0";

// 片段着色器源码
const char* mFragmentShaderStr3 = "#version 330 core\n"
"out vec4 rgbColor;\n"
"in vec3 ourColor;\n"
"in vec2 ourTextureCoord;\n"
"uniform sampler2D ourTexture;\n"
"void main()\n"
"{\n"
"//   rgbColor = texture(ourTexture, ourTextureCoord);\n"   
"   rgbColor = texture(ourTexture, ourTextureCoord) * vec4(ourColor, 1.0);\n" // 顶点颜色和纹理颜色混合
"}\n\0";

float mVertices3[] = {
	// 顶点坐标           // 颜色             // 纹理坐标
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f, // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.1f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f  // top left 
};

float mVertices3_reverse[] = {
	// 顶点坐标           // 颜色             // 纹理坐标
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
};

unsigned int indices3[] = {
	0, 1, 3, // 第一个三角形
	1, 2, 3  // 第二个三角形
};

DrawTexture::DrawTexture()
{

	// 0-1 
	// 创建着色器，程序对象和VAO等缓存对象
	MyShader vertexShader(mVertexShaderStr3, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr3, ShaderType::TYPE_FRAGMENT_SHADER);
	mProgram = new MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	mVAO = new MyVAO();
	mVAO->addVertext3D(mVertices3, sizeof(mVertices3), indices3, sizeof(indices3));
	// 0-2 
	// 链接顶点属性
	// 0表示位置坐标，1表示颜色，2表示纹理坐标
	mVAO->setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	mVAO->setVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	mVAO->setVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	mVAO->unBindVAO();
	
	// 1. 创建并绑定纹理对象
	mTexture = new MyTexture();

	// 2. 加载图片并生成纹理
	int imageWidth, imageHeight, imageChannelCount;
	unsigned char* data = stbi_load("D:/Developer/VSProject/LearnOpenGL/src/lesson03/zhanlang.jpg", &imageWidth, &imageHeight, &imageChannelCount, 0);
	if (!data) {
		std::cout << "load image failed" << std::endl;
		return;
	}
	mTexture->loadImageData(data, imageWidth, imageHeight);
	
	// 3. 获取纹理后，释放图片资源
	stbi_image_free(data);
}

int  DrawTexture::drawTexture()
{
	// 4. 使用程序，绑定纹理对象
	mProgram->UseProgram();
	mTexture->bindTexture();
	// 5. 绑定VAO对象
	mVAO->bindVAO();
	// 6. 绘制纹理到图元
	mProgram->drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	return 0;
}

DrawTexture::~DrawTexture()
{
	delete mTexture;
	delete mVAO;
	delete mProgram;
}