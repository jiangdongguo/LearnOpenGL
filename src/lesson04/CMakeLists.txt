
# 查找当前目录下所有源码
# 存储到变量SRC_DRAW_TEXTURE
aux_source_directory(. SRC_DRAW_3D)

# 生成静态库Lsn04
add_library(Lsn04 ${SRC_DRAW_3D})

