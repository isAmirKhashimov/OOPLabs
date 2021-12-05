cmake_minimum_required(VERSION 3.5)

project (oop_exercise_02)

set(SOURCES
    bitString.cpp
    main.cpp
)

add_executable(oop_exercise_02 ${SOURCES})

target_include_directories(oop_exercise_02
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)
