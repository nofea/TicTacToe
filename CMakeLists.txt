# cmake lists file

cmake_minimum_required(VERSION 3.10)

# set the project name
project(TicTacToe VERSION 0.4.6)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# list all the source and header files
file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
file (GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.hpp")

# Find all the include directories
set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES INCLUDE_DIRS)

# ignore the build folder
file(GLOB_RECURSE REMOVE_CMAKE "build/*")
list(REMOVE_ITEM SOURCES ${REMOVE_CMAKE})

# add the executable
add_executable(TicTacToe ${SOURCES})
target_include_directories(TicTacToe PUBLIC ${INCLUDE_DIRS})
