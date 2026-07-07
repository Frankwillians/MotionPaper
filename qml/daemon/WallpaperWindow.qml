import QtQuick
import QtMultimedia

Rectangle {
    color: "black"

    MediaPlayer {
        id: player
        source: "file://" + VideoPath
        videoOutput: output
        audioOutput: AudioOutput {
            muted: true
        }
        loops: MediaPlayer.Infinite
    }

    VideoOutput {
        id: output
        anchors.fill: parent
        fillMode: VideoOutput.PreserveAspectCrop
    }

    Component.onCompleted: {
        player.play()
    }
}