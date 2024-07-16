cmake_minimum_required(VERSION 3.10)

# Название проекта
project(WorkspaceProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Установка компилятора (по желанию, можно пропустить)
set(CMAKE_CXX_COMPILER "g++")

# Добавление исполняемого файла
add_executable(main main.cpp)

# Подключение заголовочных файлов
include_directories(single_include)

# Добавление нужных библиотек (если такие имеются)
# target_link_libraries(main some_library)
