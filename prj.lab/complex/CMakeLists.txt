# CMakeList.txt: проект CMake для Complex; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Complex")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Complexsad "Complex.cpp" "Complex.hpp")