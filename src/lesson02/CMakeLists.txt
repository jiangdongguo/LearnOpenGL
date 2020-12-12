
# 查找当前目录下所有源码
# 存储到变量SRC_DRAW_TRIANGLE
aux_source_directory(. SRC_DRAW_SHAPE)

# 生成静态库Lsn02
add_library(Lsn02 ${SRC_DRAW_SHAPE})

