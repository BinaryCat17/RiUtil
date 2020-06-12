project('RiUtil', 'cpp',
    version : '1.0',
    default_options : ['cpp_std=c++2a', 'warning_level=3'])

cmake = import('cmake')

# deps --------------------------------------------------------------------------------------------

magic_enum = dependency('magic_enum', required : false)
if not magic_enum.found()
    magic_enum = cmake.subproject('magic_enum').dependency('magic_enum')
endif

# project -----------------------------------------------------------------------------------------

deps = [magic_enum]

inc = include_directories('src')

lib = static_library('RiUtil',
    'src/RiUtil/types.cpp',
    'src/RiUtil/enums.cpp',
    install : true,
    dependencies : deps,
    include_directories : inc)

RiUtil_dep = declare_dependency(link_with : lib, include_directories : inc, dependencies : deps)