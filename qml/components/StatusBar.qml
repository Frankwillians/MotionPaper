import QtQuick

Rectangle {
    height: 54
    radius: 12
    color: "#202020"

    Text {
        anchors.centerIn: parent
        text: "CPU 1%    GPU 3%    FPS 60    Backend: " + BackendManager.currentBackend
        color: "#AAAAAA"
        font.pixelSize: 16
    }
}