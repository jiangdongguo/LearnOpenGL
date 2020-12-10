
# 查找当前目录下所有源码
# 存储到变量SRC_DRAW_TRIANGLE
aux_source_directory(. SRC_DRAW_SHAPE)

# 导入common库头文件
# 便于当前库查找到Common.h
#include_directories(../src/common)

# 生成静态库Lsn02
add_library(Lsn02 ${SRC_DRAW_SHAPE})

# 链接common库到库Lsn02
#target_link_libraries(Lsn02 common)
