add_executable(Executable main.c)
target_link_libraries(Executable PUBLIC pytaniaLib wylosujLib linuxLib)

target_include_directories(Executable PUBLIC
        ${CMAKE_SOURCE_DIR}/src/pytania8
        ${CMAKE_SOURCE_DIR}/src/wylosujPytanie
        ${CMAKE_SOURCE_DIR}/src/linux
)