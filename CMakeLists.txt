cmake_minimum_required(VERSION 3.12.0)

project(qt-material-design CXX)

# Find includes in the following directories:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Tell CMake to run moc automatically when needed:
set(CMAKE_AUTOMOC ON)

# Tell CMake to run uic automatically when needed:
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

set(qt-material-design-src main.cpp button.cpp)

add_executable(main ${qt-material-design-src})

target_link_libraries(main Qt5::Widgets)
