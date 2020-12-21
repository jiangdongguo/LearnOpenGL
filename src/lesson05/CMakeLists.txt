
# 查找当前目录下所有源码
# 存储到变量SRC_DRAW_TEXTURE
aux_source_directory(. SRC_SIMPLE_FILTER)

# 生成静态库Lsn05
add_library(Lsn05 ${SRC_SIMPLE_FILTER})

