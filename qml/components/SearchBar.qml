import QtQuick

Rectangle {
    id: root

    signal searchChanged(string text)

    height: 52
    radius: 12
    color: "#252525"

    TextInput {
        id: input

        anchors.fill: parent
        anchors.leftMargin: 18
        anchors.rightMargin: 18

        verticalAlignment: TextInput.AlignVCenter

        color: "white"
        font.pixelSize: 18

        clip: true

        onTextChanged: {
            root.searchChanged(text)
        }
    }

    Text {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 18

        text: "Search wallpapers..."
        color: "#777777"
        font.pixelSize: 18

        visible: input.text.length === 0
    }
}