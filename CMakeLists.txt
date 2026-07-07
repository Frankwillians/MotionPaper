cmake_minimum_required(VERSION 3.22)

project(MotionPaper VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Quick
    Qml
)

qt_add_executable(motionpaper
    app/main.cpp

    core/library/LibraryManager.h
    core/library/LibraryManager.cpp

    core/library/WallpaperModel.h
    core/library/WallpaperModel.cpp

    core/backend/BackendManager.h
    core/backend/BackendManager.cpp
)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Quick
    Qml
    Multimedia
)

target_include_directories(motionpaper
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(motionpaper
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::Qml
        Qt6::Qml
        Qt6::Multimedia
)