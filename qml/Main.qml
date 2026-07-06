
import QtQuick.Dialogs
import QtQuick

Rectangle {
    width: 1400
    height: 900
    color: "#151515"

    property string selectedTitle: "Cyberpunk City"
    property string selectedCategory: "Video Wallpaper"

    ListModel {
        id: wallpapers
        ListElement { title: "Cyberpunk City"; category: "Video" }
        ListElement { title: "Forest Rain"; category: "Nature" }
        ListElement { title: "Space Nebula"; category: "Space" }
        ListElement { title: "Anime Room"; category: "Anime" }
        ListElement { title: "Neon Street"; category: "Cyberpunk" }
        ListElement { title: "Ocean Waves"; category: "Nature" }
    }

    Row {
        anchors.fill: parent

        Rectangle {
            width: 240
            height: parent.height
            color: "#202020"

            Column {
                anchors.fill: parent
                anchors.margins: 24
                spacing: 22

                Text {
                    text: "MotionPaper"
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

        Rectangle {
            width: parent.width - 240
            height: parent.height
            color: "#181818"
            FileDialog {
    id: fileDialog
    title: "Import video"
    nameFilters: ["Video files (*.mp4 *.webm *.mkv *.mov *.avi)"]
    onAccepted: {
        LibraryManager.importVideo(String(selectedFile))
    }
}

            Column {
                anchors.fill: parent
                anchors.margins: 28
                spacing: 24

                Rectangle {
                    width: parent.width
                    height: 52
                    radius: 12
                    color: "#252525"

                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 18
                        text: "Search wallpapers..."
                        color: "#777777"
                        font.pixelSize: 18
                    }
                }

                Row {
                    width: parent.width
                    height: 560
                    spacing: 24

                    GridView {
                        width: parent.width * 0.58
                        height: parent.height
                        cellWidth: 220
                        cellHeight: 180
                        model: LibraryManager.wallpapers

                        delegate: Rectangle {
                            width: 200
                            height: 155
                            radius: 16
                            color: "#2B2B2B"

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    selectedTitle = title
                                    selectedCategory = "Video"
                                }
                            }

                            Rectangle {
                                anchors.top: parent.top
                                anchors.left: parent.left
                                anchors.right: parent.right
                                height: 100
                                radius: 16
                                color: "#333333"

                                Text {
                                    anchors.centerIn: parent
                                    text: "Preview"
                                    color: "#888888"
                                    font.pixelSize: 18
                                }
                            }

                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 12
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 28
                                text: modelData
                                color: "white"
                                font.pixelSize: 16
                                font.bold: true
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
                        }
                    }

                    Rectangle {
                        width: parent.width * 0.40
                        height: parent.height
                        radius: 18
                        color: "#101010"
                        border.color: "#333333"

                        Column {
                            anchors.fill: parent
                            anchors.margins: 24
                            spacing: 18

                            Text {
                                text: "Preview"
                                color: "white"
                                font.pixelSize: 26
                                font.bold: true
                            }

                            Rectangle {
                                width: parent.width
                                height: 320
                                radius: 16
                                color: "black"

                                Text {
                                    anchors.centerIn: parent
                                    text: selectedTitle
                                    color: "#666666"
                                    font.pixelSize: 24
                                }
                            }

                            Text {
                                text: selectedTitle
                                color: "white"
                                font.pixelSize: 24
                                font.bold: true
                            }

                            Text {
                                text: selectedCategory
                                color: "#AAAAAA"
                                font.pixelSize: 16
                            }

                            Row {
                                spacing: 12

                                Rectangle {
                                    width: 130
                                    height: 44
                                    radius: 10
                                    color: "#3B82F6"

                                    Text {
                                        anchors.centerIn: parent
                                        text: "Apply"
                                        color: "white"
                                        font.bold: true
                                    }
                                }

                                Rectangle {
    width: 130
    height: 44
    radius: 10
    color: "#2B2B2B"

    Text {
        anchors.centerIn: parent
        text: "Import"
        color: "white"
        font.bold: true
    }

    MouseArea {
        anchors.fill: parent
        onClicked: fileDialog.open()
    }
}
                                }
                            }
                        }
                    }
                }

                Rectangle {
                    width: parent.width
                    height: 54
                    radius: 12
                    color: "#202020"

                    Text {
                        anchors.centerIn: parent
                        text: "CPU 1%    GPU 3%    FPS 60    Backend: Not selected"
                        color: "#AAAAAA"
                        font.pixelSize: 16
                    }
                }
            }
        }
    }
