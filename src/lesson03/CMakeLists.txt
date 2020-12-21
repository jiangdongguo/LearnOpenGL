
# 查找当前目录下所有源码
# 存储到变量SRC_DRAW_TEXTURE
aux_source_directory(. SRC_DRAW_TEXTURE)

# 生成静态库Lsn03
add_library(Lsn03 ${SRC_DRAW_TEXTURE})

