#include "CreateWindow.hpp"

CreateWindow::CreateWindow() {
	// 1. 初始化GLFW，并配置选项
	//（1）指定OpenGL版本，便于GLFW创建合适的OpenGL上下文；
	//（2）指定使用的模式为核心模式；
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 2. 创建窗口对象GLFWWindow
	// 参数说明：
	//		   width  窗口的宽
	//		   height 窗口的高
	//         title  窗口的名称
	window = glfwCreateWindow(WINDWO_WIDTH, WINDOW_HEIGHT, "HelloOpenGL", NULL, NULL);
	if (window == NULL) {
		cout << "create GLFW window failed" << endl;
		glfwTerminate();
		return;
	}

	// 3. 将窗口的上下文设置为当前线程的主上下文
	glfwMakeContextCurrent(window);

	// 4. 通过回调的形式，设置OpenGL渲染视口的大小(<=窗口的大小)
	// 即当窗口大小变化时，同步更新渲染窗口的大小
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// 5. 初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "init glad failed" << endl;
		glfwTerminate();
		return;
	}
}

bool CreateWindow::isWindowShouldClose()
{
	// 判断是否关闭窗口
	return glfwWindowShouldClose(window);
}

void CreateWindow::checkCancelWindowEvent()
{
	// 检测ESC按键事件
	// 将关闭窗口标识设置为true
	processInput(window);
}

void CreateWindow::clearWindow()
{
	// 6. 清空窗口，便于下一次渲染
	glClearColor(0.3f, 0.6f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void CreateWindow::swapBuffers()
{
	// 7. 交换缓存
	glfwSwapBuffers(window);
	glfwPollEvents();
}

CreateWindow::~CreateWindow() {
	// 8. 结束渲染，释放GLFW资源
	glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// 设置OpenGL渲染视口大小
	// 参数说明：
	//    x,y  表示位置
	//    width,height 表示渲染窗口宽高
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	// 检测到esc按键，将循环标识置为true
	// 结束循环
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}