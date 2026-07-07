#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QUrl>
#include <QDir>

#include "core/library/LibraryManager.h"
#include "core/backend/BackendManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    LibraryManager library;
    BackendManager backend;

    QQuickView view;
    view.setTitle("LivePaper");
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.resize(1400, 900);

    view.rootContext()->setContextProperty("LibraryManager", &library);
    view.rootContext()->setContextProperty("BackendManager", &backend);

    view.setSource(QUrl::fromLocalFile(QDir::currentPath() + "/../qml/Main.qml"));

    view.show();

    return app.exec();
}