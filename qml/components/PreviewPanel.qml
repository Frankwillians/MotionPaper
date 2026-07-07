import QtQuick
import QtMultimedia

Rectangle {
    id: root

    property string selectedTitle
    property string selectedCategory
    property string selectedVideoPath

    signal apply()
    signal importClicked()
    signal deleteWallpaper()

    radius: 18
    color: "#101010"
    border.color: "#333333"

    MediaPlayer {
        id: previewPlayer
        source: root.selectedVideoPath !== "" ? "file://" + root.selectedVideoPath : ""
        videoOutput: previewOutput
        audioOutput: AudioOutput {
            muted: SettingsManager.mutePreview
        }
        loops: MediaPlayer.Infinite
    }

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

            VideoOutput {
                id: previewOutput
                anchors.fill: parent
                fillMode: VideoOutput.PreserveAspectCrop
                visible: root.selectedVideoPath !== ""
            }

            Text {
                anchors.centerIn: parent
                text: root.selectedTitle
                color: "#666666"
                font.pixelSize: 24
                visible: root.selectedVideoPath === ""
            }
        }

        Text {
            text: root.selectedTitle
            color: "white"
            font.pixelSize: 24
            font.bold: true
            width: parent.width
            elide: Text.ElideRight
        }

        Text {
            text: root.selectedCategory
            color: "#AAAAAA"
            font.pixelSize: 16
        }

        PlayerControls {
            selectedVideoPath: root.selectedVideoPath
            previewPlayer: previewPlayer

            onApply: root.apply()
            onImportClicked: root.importClicked()
            onDeleteWallpaper: root.deleteWallpaper()
        }
    }

    onSelectedVideoPathChanged: {
        if (selectedVideoPath !== "" && SettingsManager.autoPlay)
            previewPlayer.play()
    }
}