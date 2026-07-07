#include "MpvRenderer.h"

#include <QDebug>

MpvRenderer::MpvRenderer()
{
}

MpvRenderer::~MpvRenderer()
{
    stop();
}

bool MpvRenderer::initialize()
{
    qInfo() << "MpvRenderer initialized placeholder";
    return true;
}

bool MpvRenderer::play(const QString &videoPath)
{
    qInfo() << "MpvRenderer play placeholder:" << videoPath;
    return true;
}

void MpvRenderer::pause()
{
    qInfo() << "MpvRenderer pause placeholder";
}

void MpvRenderer::stop()
{
    qInfo() << "MpvRenderer stop placeholder";
}