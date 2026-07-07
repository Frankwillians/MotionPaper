import QtQuick
import QtQuick.Controls

Rectangle {
    color: "#181818"

    Column {
        anchors.fill: parent
        spacing: 24

        Text {
            text: "Settings"
            color: "white"
            font.pixelSize: 32
            font.bold: true
        }

        Rectangle {
            width: parent.width
            height: 80
            radius: 14
            color: "#202020"

            Row {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20

                Text {
                    text: "Auto Play Preview"
                    color: "white"
                    font.pixelSize: 18
                    anchors.verticalCenter: parent.verticalCenter
                }

                Switch {
                    checked: SettingsManager.autoPlay
                    anchors.verticalCenter: parent.verticalCenter
                    onToggled: SettingsManager.autoPlay = checked
                }
            }
        }

        Rectangle {
            width: parent.width
            height: 80
            radius: 14
            color: "#202020"

            Row {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20

                Text {
                    text: "Mute Preview"
                    color: "white"
                    font.pixelSize: 18
                    anchors.verticalCenter: parent.verticalCenter
                }

                Switch {
                    checked: SettingsManager.mutePreview
                    anchors.verticalCenter: parent.verticalCenter
                    onToggled: SettingsManager.mutePreview = checked
                }
            }
        }

        Rectangle {
            width: parent.width
            height: 80
            radius: 14
            color: "#202020"

            Row {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20

                Text {
                    text: "Start with Linux"
                    color: "white"
                    font.pixelSize: 18
                    anchors.verticalCenter: parent.verticalCenter
                }

                Switch {
                    checked: SettingsManager.startWithSystem
                    anchors.verticalCenter: parent.verticalCenter
                    onToggled: SettingsManager.startWithSystem = checked
                }
            }
        }
    }
}