#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFileInfo>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    parser.addHelpOption();

    QCommandLineOption videoOption(
        QStringList() << "v" << "video",
        "Video file path.",
        "video"
    );

    parser.addOption(videoOption);
    parser.process(app);

    const QString videoPath = parser.value(videoOption);

    if (videoPath.isEmpty()) {
        qDebug() << "No video provided.";
        return 1;
    }

    QFileInfo info(videoPath);

    if (!info.exists()) {
        qDebug() << "Video not found:" << videoPath;
        return 2;
    }


    QStringList args;
    args << "--title=livepaper-mpv-wallpaper";
    args << "--loop";
    args << "--no-audio";
    args << "--fullscreen";
    args << "--no-border";
    args << "--force-window=yes";
    args << "--ontop=no";
    args << "--geometry=100%x100%";
    args << "--profile=low-latency";
    args << "--hwdec=auto-safe";
    args << videoPath;

    QProcess mpv;
mpv.setProgram("mpv");
mpv.setArguments(args);
mpv.setProcessChannelMode(QProcess::ForwardedChannels);
mpv.start();

if (!mpv.waitForStarted()) {
    qDebug() << "Failed to start mpv";
    return 3;
}

qDebug() << "mpv started. Waiting...";
mpv.waitForFinished(-1);

qDebug() << "mpv exited with code:" << mpv.exitCode();

return mpv.exitCode();
}