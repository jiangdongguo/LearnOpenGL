#include "DrawTexture.hpp"

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

float mVertices[] = {
	// ��������           // ��ɫ             // ��������
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
};
unsigned int indices[] = {
	0, 1, 3, // ��һ��������
	1, 2, 3  // �ڶ���������
};

DrawTexture::DrawTexture()
{

	MyShader vertexShader(mVertexShaderStr, ShaderType::TYPE_VERTEX_SHADER);
	MyShader fragmentShader(mFragmentShaderStr, ShaderType::TYPE_FRAGMENT_SHADER);
	mProgram = new MyProgram(vertexShader.getShaderId(), fragmentShader.getShaderId());
	mVAO = new MyVAO();
	mVAO->addVertext3D(mVertices, sizeof(mVertices), 0, indices, sizeof(indices));
	
	// 1. ���������������
	mTexture = new MyTexture();

	// 2. ����ͼƬ����������
	int imageWidth, imageHeight, imageChannelCount;
	unsigned char* data = stbi_load("girl.jpg", &imageWidth, &imageHeight, &imageChannelCount, 0);
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
	// 4. ���������
	mTexture->bindTexture();
	// 5. ��VAO����
	mVAO->BindVAO();
	// 6. ��������ͼԪ
	mProgram->drawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

DrawTexture::~DrawTexture()
{
	delete mTexture;
	delete mVAO;
	delete mProgram;
}