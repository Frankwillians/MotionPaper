#include <QCoreApplication>
#include <QDebug>

#include "daemon/LivePaperDaemon.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    LivePaperDaemon daemon;

    if (!daemon.start()) {
        qCritical() << "Failed to start LivePaper daemon";
        return 1;
    }

    qInfo() << "LivePaper daemon running";

    return app.exec();
}