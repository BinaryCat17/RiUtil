project('RiUtil', 'cpp',
    version : '1.0',
    default_options : ['cpp_std=c++17', 'warning_level=3'])

# project -----------------------------------------------------------------------------------------

includes = include_directories('src')

lib = static_library('RiUtil',
    'src/RiUtil/types.cpp',
    install : true,
    include_directories : includes)

RiWindow_dep = declare_dependency(link_with : lib, include_directories : includes)