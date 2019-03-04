# cmake_minimum_required(VERSION 3.5)
 project(data_structure_c)

# configure a header file to pass some of the CMake settings
# to the source code
# configure_file(
#     "${PROJECT_SOURCE_DIR}/data_structure.h.in"
#     "${PROJECT_SOURCE_DIR}/data_structure.h"
# )

# add the binary tree to search path for include files;
# so that we will find data_structure.h
# include_directories("${PROJECT_BINARY_DIR}")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)
file(GLOB source_files "*.c")
file(GLOB header_files "include/*.h")
# 生成链接库
#add_library (Data_structure_src ${DIR_LIB_SRCS})
add_library(${PROJECT_NAME} SHARED ${source_files})
add_library(${PROJECT_NAME}_static STATIC ${source_files})
include_directories("./include")
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${header_files}")
set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} Data_structure_test)

# 指定 Data_structure 库的安装路径
# install (TARGETS Data_structure DESTINATION lib)
# install (FILES qsort.h DESTINATION include)






