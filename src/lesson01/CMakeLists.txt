
# 查找当前目录下所有的源文件
# 并将其保持到变量SRC_CREATE_WINDOW
aux_source_directory(. SRC_CREATE_WINDOW)

# 生成链接库Lsn01
add_library(Lsn01 ${SRC_CREATE_WINDOW})