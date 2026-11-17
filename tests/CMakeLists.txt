
# Test para cadenas simples.
setup_test(stringTest stringTest.cpp)

# Test para leer y encriptar el contenido de un archivo.
setup_test(fileTest fileTest.cpp)

# Test para leer de <stdin>.
add_executable(inTest inTest.cpp)

set_target_properties(inTest PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_link_libraries(inTest PRIVATE ${PROJECT_NAME} test_config)

