import QtQuick

Rectangle {
    id: root

    property string wallpaperTitle
    property string wallpaperThumb
    property string wallpaperFile

    signal clicked(string title, string thumb, string file)

    width: 220
    height: 165
    radius: 16

    color: "#2B2B2B"

    Rectangle {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 110
        radius: 16

        color: "#333333"
        clip: true

        Image {
            anchors.fill: parent
            source: wallpaperThumb
            fillMode: Image.PreserveAspectCrop
            visible: wallpaperThumb !== ""
        }

        Text {
            anchors.centerIn: parent
            text: "No Preview"
            color: "#888888"
            visible: wallpaperThumb === ""
        }
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 12

        anchors.right: parent.right
        anchors.rightMargin: 12

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30

        text: wallpaperTitle
        color: "white"

        font.pixelSize: 15
        font.bold: true

        elide: Text.ElideRight
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 12

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        text: "Video"
        color: "#999999"
        font.pixelSize: 13
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            root.clicked(
                wallpaperTitle,
                wallpaperThumb,
                wallpaperFile
            )
        }
    }
}