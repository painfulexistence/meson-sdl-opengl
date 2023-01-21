project('meson-sdl-opengl', 'cpp', 
    default_options: 'default_library=static')

sdl2 = dependency('sdl2')
gl = dependency('opengl')

executable('main', 'main.cpp', dependencies: [sdl2, gl])
