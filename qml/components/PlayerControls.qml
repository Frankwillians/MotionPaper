import QtQuick
import QtMultimedia

Row {
    id: root

    property string selectedVideoPath: ""
    property MediaPlayer previewPlayer

    signal apply()
    signal importClicked()
    signal deleteWallpaper()

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
            onClicked: root.apply()
        }
    }

    Rectangle {
        width: 120
        height: 44
        radius: 10
        color: "#2563EB"

        Text {
            anchors.centerIn: parent
            text: root.previewPlayer && root.previewPlayer.playbackState === MediaPlayer.PlayingState ? "Pause" : "Play"
            color: "white"
            font.bold: true
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                if (root.selectedVideoPath === "" || !root.previewPlayer)
                    return

                if (root.previewPlayer.playbackState === MediaPlayer.PlayingState)
                    root.previewPlayer.pause()
                else
                    root.previewPlayer.play()
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
            onClicked: root.importClicked()
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
            onClicked: {
                if (root.previewPlayer)
                    root.previewPlayer.stop()
            }
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
            onClicked: root.deleteWallpaper()
        }
    }
}