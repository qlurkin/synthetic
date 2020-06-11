cmake_minimum_required(VERSION "3.17.3")

project("synthetic")

add_library("${PROJECT_NAME}" SHARED 
	engine/engine.h
	engine/engine.cpp
)
set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

add_executable(sandbox
	app/main.cpp
)
set_property(TARGET sandbox PROPERTY CXX_STANDARD 17)
target_link_libraries(sandbox PUBLIC "${PROJECT_NAME}")