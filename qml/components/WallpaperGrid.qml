import QtQuick

GridView {
    id: root

    property string selectedVideoPath: ""

    signal wallpaperSelected(string title, string thumb, string file)

    cellWidth: 240
    cellHeight: 190
    model: LibraryManager.model
    clip: true

    delegate: WallpaperCard {
        wallpaperTitle: title
        wallpaperThumb: thumbPath
        wallpaperFile: filePath

        border.color: root.selectedVideoPath === filePath ? "#3B82F6" : "transparent"
        border.width: 2

        onClicked: {
            root.wallpaperSelected(wallpaperTitle, wallpaperThumb, wallpaperFile)
        }
    }
}