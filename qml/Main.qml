import QtQuick
import QtQuick.Dialogs

Rectangle {
    width: 1400
    height: 900
    color: "#151515"

    property string selectedTitle: "Select a wallpaper"
    property string selectedCategory: "Video"
    property string selectedThumb: ""

    FileDialog {
        id: fileDialog
        title: "Import video"
        nameFilters: ["Video files (*.mp4 *.webm *.mkv *.mov *.avi)"]

        onAccepted: {
            LibraryManager.importVideo(String(selectedFile))
        }
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

        Rectangle {
            width: parent.width - 240
            height: parent.height
            color: "#181818"

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
                        cellWidth: 240
                        cellHeight: 190
                        model: LibraryManager.model
                        clip: true

                        delegate: Rectangle {
                            width: 220
                            height: 165
                            radius: 16
                            color: "#2B2B2B"
                            border.color: selectedTitle === title ? "#3B82F6" : "transparent"
                            border.width: 2

                            MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true

                                onClicked: {
                                    selectedTitle = title
                                    selectedCategory = "Video"
                                    selectedThumb = thumbPath
                                }
                            }

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
                                    source: thumbPath
                                    fillMode: Image.PreserveAspectCrop
                                    visible: thumbPath !== ""
                                }

                                Text {
                                    anchors.centerIn: parent
                                    text: "No Preview"
                                    color: "#888888"
                                    font.pixelSize: 16
                                    visible: thumbPath === ""
                                }
                            }

                            Text {
                                anchors.left: parent.left
                                anchors.leftMargin: 12
                                anchors.right: parent.right
                                anchors.rightMargin: 12
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 30
                                text: title
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
                                clip: true

                                Image {
                                    anchors.fill: parent
                                    source: selectedThumb
                                    fillMode: Image.PreserveAspectCrop
                                    visible: selectedThumb !== ""
                                }

                                Text {
                                    anchors.centerIn: parent
                                    text: selectedTitle
                                    color: "#666666"
                                    font.pixelSize: 24
                                    visible: selectedThumb === ""
                                }
                            }

                            Text {
                                text: selectedTitle
                                color: "white"
                                font.pixelSize: 24
                                font.bold: true
                                elide: Text.ElideRight
                                width: parent.width
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
}