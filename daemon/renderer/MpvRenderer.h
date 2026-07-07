#pragma once

#include "Renderer.h"

class MpvRenderer : public Renderer {
public:
    MpvRenderer();
    ~MpvRenderer() override;

    bool initialize() override;
    bool play(const QString &videoPath) override;
    void pause() override;
    void stop() override;
};