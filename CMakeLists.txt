
cmake_minimum_required(VERSION 3.25)

project(notPacker
	VERSION 1.0
	LANGUAGES CXX
)

# Configuraciones de CMake.
include(cmake/Compiler.cmake)
include(cmake/Testing.cmake)

# Añadir subdirectorios para la compilación del proyecto.
add_subdirectory(src)
#add_subdirectory(tests)

