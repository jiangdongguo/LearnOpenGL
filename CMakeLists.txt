# Cmake最低版本
cmake_minimum_required (VERSION 3.8)

# Project名称
project ("LearnOpenGL")

# 指定头文件路径
include_directories(${PROJECT_SOURCE_DIR}/3rdPart/glad/include/)
include_directories(${PROJECT_SOURCE_DIR}/3rdPart/glad/include/)
include_directories(${PROJECT_SOURCE_DIR}/3rdPart/glfw/include/)

# 指定库位置
set(GLFW_LINK ${PROJECT_SOURCE_DIR}/3rdPart/glfw/lib)
link_directories(${GLFW_LINK})

# 添加子目录
add_subdirectory(src/lesson01)

# 编译源码生成目标
add_executable (LearnOpenGL         # 要生成的可执行文件
				"LearnOpenGL.cpp" "LearnOpenGL.h"  # 自定义源文件
				${PROJECT_SOURCE_DIR}/3rdPart/glad/src/glad.c # 第三方库源文件
				)

# 将第三方库链接到可执行文件
target_link_libraries(LearnOpenGL 
						glfw3  # 链接第三方库
						Lsn01  # 链接自定义库
						)


