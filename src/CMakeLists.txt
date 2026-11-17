
# Generand o libreria con el código.
add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	HuffmanTree.cpp
	notPacker.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

