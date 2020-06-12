cmake_minimum_required(VERSION "3.17.3")

project("synthetic")

add_library("${PROJECT_NAME}" SHARED 
	engine/synthetic.h
	engine/core.h
	engine/entryPoint.h
	engine/Application.h
	engine/Application.cpp
)
set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 17)
target_compile_definitions("${PROJECT_NAME}"
	PRIVATE SYN_PLATFORM_WINDOWS
	PRIVATE SYN_BUILD_DLL
)

add_executable(sandbox
	app/main.cpp
)
set_property(TARGET sandbox PROPERTY CXX_STANDARD 17)
target_compile_definitions(sandbox
	PRIVATE SYN_PLATFORM_WINDOWS
)
target_include_directories(sandbox
	PRIVATE engine
)
target_link_libraries(sandbox PUBLIC "${PROJECT_NAME}")