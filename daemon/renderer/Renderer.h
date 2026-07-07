#pragma once

#include <QString>

class Renderer {
public:
    virtual ~Renderer() = default;

    virtual bool initialize() = 0;
    virtual bool play(const QString &videoPath) = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};