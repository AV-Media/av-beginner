message(${CMAKE_CURRENT_SOURCE_DIR})

macro(init_path)
    message("init library path")
    set(sdl_dir "/usr/local/Cellar/sdl2/2.0.10")
    set(sdl_image_dir "/usr/local/Cellar/sdl2_image/2.0.5")
    set(sound_touch_dir "/usr/local/Cellar/sound-touch/2.1.2")
endmacro()

# ----------------  link library  ----------------
macro(link_sdl)
    message("link sdl library and path is ${sdl_dir} ")
    include_directories(${sdl_dir}/include/SDL2)
    link_directories(${sdl_dir}/lib)
endmacro()

macro(link_sdl_image)
    message("link sdl image library and path is ${sdl_image_dir}")
    include_directories(${sdl_image_dir}/include/SDL2)
    link_directories(${sdl_image_dir}/lib)
endmacro()

macro(link_sound_touch)
    message("link sound touch library and path is ${sound_touch_dir}")
    include_directories(${sound_touch_dir}/include/soundtouch)
    link_libraries(${sound_touch_dir}/lib)
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

macro(target_link_sound_touch name)
    message("${name} link sound touch")
    target_link_libraries(${name} SoundTouch)
endmacro()

# ----------------  init definition  ----------------

macro(init_definition)
    add_definitions(-DPROJECT_DIR_PATH="${CMAKE_SOURCE_DIR}")
endmacro()