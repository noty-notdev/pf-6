
#
# Configuración para el compilador de C++.
#

# Evitar extensiones del compilador, solo estándar.
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Utilidades para el editor y el .so/.dll a generar.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

