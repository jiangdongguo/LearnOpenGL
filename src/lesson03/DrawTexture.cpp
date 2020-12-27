#include "DrawTexture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// ������ɫ��Դ��
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

// Ƭ����ɫ��Դ��
const char* mFragmentShaderStr3 = "#version 330 core\n"
"out vec4 rgbColor;\n"
"in vec3 ourColor;\n"
"in vec2 ourTextureCoord;\n"
"uniform sampler2D ourTexture;\n"
"void main()\n"
"{\n"
"//   rgbColor = texture(ourTexture, ourTextureCoord);\n"   
"   rgbColor = texture(ourTexture, ourTextureCoord) * vec4(ourColor, 1.0);\n" // ������ɫ��������ɫ���
"}\n\0";

float mVertices3[] = {
	// ��������           // ��ɫ             // ��������
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f, // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.1f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f  // top left 
};

float mVertices3_reverse[] = {
	// ��������           // ��ɫ             // ��������
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
};

unsigned int indices3[] = {
	0, 1, 3, // ��һ��������
	1, 2, 3  // �ڶ���������
};

DrawTexture::DrawTexture()
{

	// 0-1 
	// ������ɫ������������VAO�Ȼ������
	MyShader vertexShader(mVertexShaderStr3, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr3, ShaderType::TYPE_FRAGMENT_SHADER);
	mProgram = new MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	mVAO = new MyVAO();
	mVAO->addVertext3D(mVertices3, sizeof(mVertices3), indices3, sizeof(indices3));
	// 0-2 
	// ���Ӷ�������
	// 0��ʾλ�����꣬1��ʾ��ɫ��2��ʾ��������
	mVAO->setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	mVAO->setVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	mVAO->setVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	mVAO->unBindVAO();
	
	// 1. ���������������
	mTexture = new MyTexture();

	// 2. ����ͼƬ����������
	int imageWidth, imageHeight, imageChannelCount;
	unsigned char* data = stbi_load("D:/Developer/VSProject/LearnOpenGL/src/lesson03/zhanlang.jpg", &imageWidth, &imageHeight, &imageChannelCount, 0);
	if (!data) {
		std::cout << "load image failed" << std::endl;
		return;
	}
	mTexture->loadImageData(data, imageWidth, imageHeight);
	
	// 3. ��ȡ������ͷ�ͼƬ��Դ
	stbi_image_free(data);
}

int  DrawTexture::drawTexture()
{
	// 4. ʹ�ó��򣬰��������
	mProgram->UseProgram();
	mTexture->bindTexture();
	// 5. ��VAO����
	mVAO->bindVAO();
	// 6. ��������ͼԪ
	mProgram->drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	return 0;
}

DrawTexture::~DrawTexture()
{
	delete mTexture;
	delete mVAO;
	delete mProgram;
}