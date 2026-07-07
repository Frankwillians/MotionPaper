#include "SettingsManager.h"

SettingsManager::SettingsManager(QObject *parent)
    : QObject(parent), m_settings("LivePaper", "LivePaper")
{
}

bool SettingsManager::autoPlay() const {
    return m_settings.value("autoPlay", true).toBool();
}

bool SettingsManager::mutePreview() const {
    return m_settings.value("mutePreview", true).toBool();
}

bool SettingsManager::startWithSystem() const {
    return m_settings.value("startWithSystem", false).toBool();
}

void SettingsManager::setAutoPlay(bool value) {
    if (autoPlay() == value) return;
    m_settings.setValue("autoPlay", value);
    emit autoPlayChanged();
}

void SettingsManager::setMutePreview(bool value) {
    if (mutePreview() == value) return;
    m_settings.setValue("mutePreview", value);
    emit mutePreviewChanged();
}

void SettingsManager::setStartWithSystem(bool value) {
    if (startWithSystem() == value) return;
    m_settings.setValue("startWithSystem", value);
    emit startWithSystemChanged();
}