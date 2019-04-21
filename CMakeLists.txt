# general

cmake_minimum_required(VERSION 3.12)

project(NPuzzle)

set(CMAKE_CXX_STANDARD 17)

# npuzzle library

set(NPuzzleDir ${CMAKE_CURRENT_SOURCE_DIR}/Sources)
file(GLOB NPuzzleSources	${NPuzzleDir}/Move.hpp
							${NPuzzleDir}/Matrix.cpp
							${NPuzzleDir}/Matrix.hpp
							${NPuzzleDir}/Parser.cpp
							${NPuzzleDir}/Parser.hpp
							${NPuzzleDir}/ResultChecker.cpp
							${NPuzzleDir}/ResultChecker.hpp
							${NPuzzleDir}/Solver.cpp
							${NPuzzleDir}/Solver.hpp
							${NPuzzleDir}/State.cpp
							${NPuzzleDir}/State.hpp
							${NPuzzleDir}/StateContainer.cpp
							${NPuzzleDir}/StateContainer.hpp)
add_library(NPuzzle STATIC ${NPuzzleSources})

# testing executable

set(TestsDir ${CMAKE_CURRENT_SOURCE_DIR}/Tests)
file(GLOB TestsSources  ${TestsDir}/main.cpp
						${TestsDir}/TestsUtils.hpp
						${TestsDir}/catch.hpp
						${TestsDir}/Parser.cpp)

add_executable(Tests ${TestsSources})

target_link_libraries(Tests NPuzzle)

target_include_directories(Tests PUBLIC ${NPuzzleDir})

# definitions

add_definitions(-DPATH_TO_TESTS_DIR="${TestsDir}")
