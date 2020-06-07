project('RiUtil', 'cpp',
    version : '1.0',
    default_options : ['cpp_std=c++17', 'warning_level=3'])

lib = library('RiUtil',
        'src/types.cpp',
     include_directories : include_directories('./include/RiUtil'),
     install : true)

RiUtil_dep = declare_dependency(
    link_with : lib,
    include_directories : include_directories('./include'))