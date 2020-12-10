
# 查找当前目录下所有源码
# 存储到变量SRC_COMMON
aux_source_directory(. SRC_COMMON)

# 生成静态库
add_library(common ${SRC_COMMON})
