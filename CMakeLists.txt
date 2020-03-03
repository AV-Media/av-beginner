cmake_minimum_required(VERSION 3.14)
project(av-beginner)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(cmake_utils)

init_path()
init_definition()

link_sdl()
link_sdl_image()
link_sound_touch()



add_subdirectory(sdl_tutorial)
add_subdirectory(sound_touch_tutorial)


## 声明一个变量 SDL_DIR 为 SDL 安装路径
#set(SDL_DIR "/usr/local/Cellar/sdl2/2.0.10")
## 设置要包含的头文件的路径
#include_directories(${SDL_DIR}/include)
## 设置要关联的库的路径
#link_directories(${SDL_DIR}/lib)

add_executable(av-beginner main.cpp)

target_link_sdl(av-beginner)
