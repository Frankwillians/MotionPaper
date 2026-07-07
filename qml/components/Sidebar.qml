import QtQuick

Rectangle {
    width: 240
    color: "#202020"

    Column {
        anchors.fill: parent
        anchors.margins: 24
        spacing: 22

        Text {
            text: "LivePaper"
            color: "white"
            font.pixelSize: 28
            font.bold: true
        }

        Text { text: "Library"; color: "#3B82F6"; font.pixelSize: 20 }
        Text { text: "Favorites"; color: "#AAAAAA"; font.pixelSize: 20 }
        Text { text: "Workshop"; color: "#AAAAAA"; font.pixelSize: 20 }
        Text { text: "Settings"; color: "#AAAAAA"; font.pixelSize: 20 }
    }
}