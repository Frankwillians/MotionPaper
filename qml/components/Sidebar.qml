import QtQuick

Rectangle {
    id: root

    property string activePage: "library"
    signal pageSelected(string page)

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

        Text {
            text: "Library"
            color: root.activePage === "library" ? "#3B82F6" : "#AAAAAA"
            font.pixelSize: 20

            MouseArea {
                anchors.fill: parent
                onClicked: root.pageSelected("library")
            }
        }

        Text {
            text: "Favorites"
            color: root.activePage === "favorites" ? "#3B82F6" : "#AAAAAA"
            font.pixelSize: 20

            MouseArea {
                anchors.fill: parent
                onClicked: root.pageSelected("favorites")
            }
        }

        Text {
            text: "Workshop"
            color: root.activePage === "workshop" ? "#3B82F6" : "#AAAAAA"
            font.pixelSize: 20

            MouseArea {
                anchors.fill: parent
                onClicked: root.pageSelected("workshop")
            }
        }

        Text {
            text: "Settings"
            color: root.activePage === "settings" ? "#3B82F6" : "#AAAAAA"
            font.pixelSize: 20

            MouseArea {
                anchors.fill: parent
                onClicked: root.pageSelected("settings")
            }
        }
    }
}