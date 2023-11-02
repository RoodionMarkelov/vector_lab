# CMakeList.txt: проект CMake для vector_lab; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (vector_lab "vector_lab.cpp" "vector_lab.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET vector_lab PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
