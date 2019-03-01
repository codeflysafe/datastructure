cmake_minimum_required(VERSION 3.5)

# 项目信息
project(data_structure)

# 添加 src 子目录
add_subdirectory(src)
add_subdirectory(test)

# aux_source_directory(. DIR_SRCS)

# add_executable(Demo ${DIR_SRCS})

# target_link_libraries(Demo ${EXTRA_LIBS})

# 指定安装路径
# install (TARGETS Demo DESTINATION bin)
# install (FILES "${PROJECT_BINARY_DIR}/config.h"
#          DESTINATION include)
