message(${CMAKE_CURRENT_SOURCE_DIR})

macro(init_path)
    message("init library path")
    set(sdl_dir "/usr/local/Cellar/sdl2/2.0.10")
    set(sdl_image_dir "/usr/local/Cellar/sdl2_image/2.0.5")
endmacro()

# ----------------  link library  ----------------
macro(link_sdl)
    message("link sdl library")
    include_directories(${sdl_dir}/include/SDL2)
    link_directories(${sdl_dir}/lib)
endmacro()

macro(link_sdl_image)
    message("link sdl image library")
    include_directories(${sdl_image_dir}/include/SDL2)
    link_directories(${sdl_image_dir}/lib)
endmacro()

# ----------------  target link library  ----------------
macro(target_link_sdl name)
    message("${name} link sdl library")
    target_link_libraries(${name}
            SDL2
            SDL2_test
            SDL2main)
endmacro()

macro(target_link_sdl_image name)
    message("${name} link sdl image")
    target_link_libraries(${name}
            SDL2_image
            )
endmacro()

# ----------------  init definition  ----------------

macro(init_definition)
    add_definitions(-DPROJECT_DIR_PATH="${CMAKE_SOURCE_DIR}")
endmacro()