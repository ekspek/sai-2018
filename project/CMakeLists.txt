cmake_minimum_required(VERSION 2.8)

set(SOURCES *.c)
set(HEADERS *.h)

project(teste_opengl)
file(GLOB HEADERS *.h)
file(GLOB SOURCES *.c)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(SDL2)


INCLUDE(FindPkgConfig)
INCLUDE(FindOpenGL REQUIRED)
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

pkg_search_module(SDL2 REQUIRED sdl2)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} m pthread)


