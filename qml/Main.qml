import QtQuick
import QtQuick.Dialogs
import QtMultimedia

Rectangle {
    width: 1400
    height: 900
    color: "#151515"

    property string selectedTitle: "Select a wallpaper"
    property string selectedCategory: "Video"
    property string selectedThumb: ""
    property string selectedVideoPath: ""

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
                            border.color: selectedVideoPath === filePath ? "#3B82F6" : "transparent"
                            border.width: 2

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    selectedTitle = title
                                    selectedCategory = "Video"
                                    selectedThumb = thumbPath
                                    selectedVideoPath = filePath
                                    previewPlayer.play()
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

                                MediaPlayer {
                                    id: previewPlayer
                                    source: selectedVideoPath !== "" ? "file://" + selectedVideoPath : ""
                                    videoOutput: previewOutput
                                    audioOutput: AudioOutput {
                                        muted: true
                                    }
                                    loops: MediaPlayer.Infinite
                                }

                                VideoOutput {
                                    id: previewOutput
                                    anchors.fill: parent
                                    fillMode: VideoOutput.PreserveAspectCrop
                                    visible: selectedVideoPath !== ""
                                }

                                Text {
                                    anchors.centerIn: parent
                                    text: selectedTitle
                                    color: "#666666"
                                    font.pixelSize: 24
                                    visible: selectedVideoPath === ""
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
                                    width: 120
                                    height: 44
                                    radius: 10
                                    color: "#3B82F6"

                                    Text {
                                        anchors.centerIn: parent
                                        text: "Apply"
                                        color: "white"
                                        font.bold: true
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            if (selectedVideoPath === "")
                                                return

                                            BackendManager.applyWallpaper(selectedVideoPath)
                                        }
                                    }
                                }

                                Rectangle {
                                    width: 120
                                    height: 44
                                    radius: 10
                                    color: "#2563EB"

                                    Text {
                                        anchors.centerIn: parent
                                        text: previewPlayer.playbackState === MediaPlayer.PlayingState ? "Pause" : "Play"
                                        color: "white"
                                        font.bold: true
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            if (selectedVideoPath === "")
                                                return

                                            if (previewPlayer.playbackState === MediaPlayer.PlayingState) {
                                                previewPlayer.pause()
                                            } else {
                                                previewPlayer.play()
                                            }
                                        }
                                    }
                                }

                                Rectangle {
                                    width: 120
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

                                Rectangle {
                                    width: 120
                                    height: 44
                                    radius: 10
                                    color: "#2B2B2B"

                                    Text {
                                        anchors.centerIn: parent
                                        text: "Stop"
                                        color: "white"
                                        font.bold: true
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: previewPlayer.stop()
                                    }
                                }

                                Rectangle {
                                    width: 120
                                    height: 44
                                    radius: 10
                                    color: "#7F1D1D"

                                    Text {
                                        anchors.centerIn: parent
                                        text: "Delete"
                                        color: "white"
                                        font.bold: true
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            if (selectedVideoPath === "")
                                                return

                                            previewPlayer.stop()
                                            LibraryManager.deleteWallpaper(selectedVideoPath)

                                            selectedTitle = "Select a wallpaper"
                                            selectedCategory = "Video"
                                            selectedThumb = ""
                                            selectedVideoPath = ""
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
                        text: "CPU 1%    GPU 3%    FPS 60    Backend: " + BackendManager.currentBackend
                        color: "#AAAAAA"
                        font.pixelSize: 16
                    }
                }
            }
        }
    }
}