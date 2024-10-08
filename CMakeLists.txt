cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
set(PROJECT_NAME CPP)
project(${PROJECT_NAME})
 
add_executable(${PROJECT_NAME} 
	src/main.cpp 
	src/Renderer/ShaderProgram.cpp 
	src/Renderer/ShaderProgram.h
	src/Resources/ResourcesManager.cpp
	src/Resources/ResourcesManager.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORSE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORSE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORSE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)