#include "CreateWindow.hpp"

CreateWindow::CreateWindow() {
	// 1. ��ʼ��GLFW��������ѡ��
	//��1��ָ��OpenGL�汾������GLFW�������ʵ�OpenGL�����ģ�
	//��2��ָ��ʹ�õ�ģʽΪ����ģʽ��
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 2. �������ڶ���GLFWWindow
	// ����˵����
	//		   width  ���ڵĿ�
	//		   height ���ڵĸ�
	//         title  ���ڵ�����
	window = glfwCreateWindow(WINDWO_WIDTH, WINDOW_HEIGHT, "HelloOpenGL", NULL, NULL);
	if (window == NULL) {
		cout << "create GLFW window failed" << endl;
		glfwTerminate();
		return;
	}

	// 3. �����ڵ�����������Ϊ��ǰ�̵߳���������
	glfwMakeContextCurrent(window);

	// 4. ͨ���ص�����ʽ������OpenGL��Ⱦ�ӿڵĴ�С(<=���ڵĴ�С)
	// �������ڴ�С�仯ʱ��ͬ��������Ⱦ���ڵĴ�С
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// 5. ��ʼ��GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "init glad failed" << endl;
		glfwTerminate();
		return;
	}
}

bool CreateWindow::isWindowShouldClose()
{
	// �ж��Ƿ�رմ���
	return glfwWindowShouldClose(window);
}

void CreateWindow::checkCancelWindowEvent()
{
	// ���ESC�����¼�
	// ���رմ��ڱ�ʶ����Ϊtrue
	processInput(window);
}

void CreateWindow::clearWindow()
{
	// 6. ��մ��ڣ�������һ����Ⱦ
	glClearColor(0.3f, 0.6f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void CreateWindow::swapBuffers()
{
	// 7. ��������
	glfwSwapBuffers(window);
	glfwPollEvents();
}

CreateWindow::~CreateWindow() {
	// 8. ������Ⱦ���ͷ�GLFW��Դ
	glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// ����OpenGL��Ⱦ�ӿڴ�С
	// ����˵����
	//    x,y  ��ʾλ��
	//    width,height ��ʾ��Ⱦ���ڿ��
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	// ��⵽esc��������ѭ����ʶ��Ϊtrue
	// ����ѭ��
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}