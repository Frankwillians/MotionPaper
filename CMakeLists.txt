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
    Multimedia
    DBus
)

qt_add_executable(motionpaper
    app/main.cpp

    core/library/LibraryManager.h
    core/library/LibraryManager.cpp
    core/library/WallpaperModel.h
    core/library/WallpaperModel.cpp

    core/backend/BackendManager.h
    core/backend/BackendManager.cpp

    core/settings/SettingsManager.h
    core/settings/SettingsManager.cpp
)

qt_add_executable(livepaperd
    daemon/main.cpp

    daemon/daemon/LivePaperDaemon.h
    daemon/daemon/LivePaperDaemon.cpp

    daemon/renderer/Renderer.h
    daemon/renderer/MpvRenderer.h
    daemon/renderer/MpvRenderer.cpp

    daemon/ipc/DBusServer.h
    daemon/ipc/DBusServer.cpp

    daemon/wayland/WaylandLayer.h
    daemon/wayland/WaylandLayer.cpp
)

target_include_directories(motionpaper
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(livepaperd
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/daemon
)

target_link_libraries(motionpaper
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::Qml
        Qt6::Multimedia
)

target_link_libraries(livepaperd
    PRIVATE
        Qt6::Core
        Qt6::DBus
)