
enable_testing()

# Intefaz para configurar los tests.
add_library(test_config INTERFACE)

if(MSVC)
	target_compile_options(test_config INTERFACE /W4)
else()
	target_compile_options(test_config INTERFACE -Wall -Wextra -Wpedantic)
endif()

# Función para configurar los tests.
function(setupTest, TEST_NAME CXX_SOURCE)
	add_executable(${TEST_NAME} ${CXX_SOURCE})
	
	target_link_libraries(${TEST_NAME} PRIVATE ${PROJECT_NAME} test_config)

	add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
	set_tests_properties(${TEST_NAME} PROPERTIES TIMEOUT 5)
endfunction()

