import QtQuick
import QtQuick.Dialogs
import "components"

Rectangle {
    id: root

    width: 1400
    height: 900
    color: "#151515"

    property string currentPage: "library"

    property string selectedTitle: "Select a wallpaper"
    property string selectedCategory: "Video"
    property string selectedThumb: ""
    property string selectedVideoPath: ""

    FileDialog {
        id: fileDialog
        title: "Import video"
        nameFilters: ["Video files (*.mp4 *.webm *.mkv *.mov *.avi)"]
        onAccepted: LibraryManager.importVideo(String(selectedFile))
    }

    Row {
        anchors.fill: parent

        Sidebar {
            height: parent.height
            activePage: root.currentPage
            onPageSelected: root.currentPage = page
        }

        Rectangle {
            width: parent.width - 240
            height: parent.height
            color: "#181818"

            Column {
                anchors.fill: parent
                anchors.margins: 28
                spacing: 24

                SearchBar {
    width: parent.width
    visible: root.currentPage === "library"

    onSearchChanged: function(text) {
        LibraryManager.searchQuery = text
    }
}

                Row {
                    width: parent.width
                    height: 560
                    spacing: 24
                    visible: root.currentPage === "library"

                    WallpaperGrid {
                        width: parent.width * 0.58
                        height: parent.height
                        selectedVideoPath: root.selectedVideoPath

                        onWallpaperSelected: function(title, thumb, file) {
                            root.selectedTitle = title
                            root.selectedCategory = "Video"
                            root.selectedThumb = thumb
                            root.selectedVideoPath = file
                        }
                    }

                    PreviewPanel {
                        width: parent.width * 0.40
                        height: parent.height

                        selectedTitle: root.selectedTitle
                        selectedCategory: root.selectedCategory
                        selectedVideoPath: root.selectedVideoPath

                        onApply: {
                            if (root.selectedVideoPath !== "")
                                BackendManager.applyWallpaper(root.selectedVideoPath)
                        }

                        onImportClicked: fileDialog.open()

                        onDeleteWallpaper: {
                            if (root.selectedVideoPath === "")
                                return

                            LibraryManager.deleteWallpaper(root.selectedVideoPath)

                            root.selectedTitle = "Select a wallpaper"
                            root.selectedCategory = "Video"
                            root.selectedThumb = ""
                            root.selectedVideoPath = ""
                        }
                    }
                }

                SettingsPage {
                    width: parent.width
                    height: 560
                    visible: root.currentPage === "settings"
                }

                Rectangle {
                    width: parent.width
                    height: 560
                    color: "transparent"
                    visible: root.currentPage === "favorites"

                    Text {
                        anchors.centerIn: parent
                        text: "Favorites coming soon"
                        color: "#AAAAAA"
                        font.pixelSize: 28
                    }
                }

                Rectangle {
                    width: parent.width
                    height: 560
                    color: "transparent"
                    visible: root.currentPage === "workshop"

                    Text {
                        anchors.centerIn: parent
                        text: "Workshop coming soon"
                        color: "#AAAAAA"
                        font.pixelSize: 28
                    }
                }

                StatusBar {
                    width: parent.width
                }
            }
        }
    }
}