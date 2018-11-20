cmake_minimum_required(VERSION 3.0)
project(Demo LANGUAGES VERSION 1.1.0 C CXX)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -mtune=native -mavx2 -mfma")

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
#add_subdirectory(math)

include_directories(third-party)
add_subdirectory(third-party/abseil-cpp)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
#target_link_libraries(Demo MathFunctions)
target_link_libraries(Demo absl::strings absl::base absl::optional absl::bad_any_cast)
