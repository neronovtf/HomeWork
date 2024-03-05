cmake_minimum_required(VERSION 3.22.0)
project(project_exe)
add_executable(project_exe main.cpp )
add_library(project_dll SHARED 
	"project_api.h"
	"error.cpp"
	"error.h"
	"transport.cpp"
	"transport.h"
	"landTransport.cpp"
	"landTransport.h"
	"airTransport.cpp"
	"airTransport.h"
	"track.cpp"
	"track.h"
	"boots.cpp"
	"boots.h"
	"broom.cpp"
	"broom.h"
	"camel.cpp"
	"camel.h"
	"centaur.cpp"
	"centaur.h"
	"eagle.cpp"
	"eagle.h"
	"camelSpeed.h"
	"camelSpeed.cpp"
	"carpet.cpp" 
	"carpet.h"
)
target_link_libraries(project_exe project_dll)