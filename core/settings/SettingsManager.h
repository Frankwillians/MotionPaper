#pragma once
#include <QObject>
#include <QSettings>

class SettingsManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool autoPlay READ autoPlay WRITE setAutoPlay NOTIFY autoPlayChanged)
    Q_PROPERTY(bool mutePreview READ mutePreview WRITE setMutePreview NOTIFY mutePreviewChanged)
    Q_PROPERTY(bool startWithSystem READ startWithSystem WRITE setStartWithSystem NOTIFY startWithSystemChanged)

public:
    explicit SettingsManager(QObject *parent = nullptr);

    bool autoPlay() const;
    bool mutePreview() const;
    bool startWithSystem() const;

    void setAutoPlay(bool value);
    void setMutePreview(bool value);
    void setStartWithSystem(bool value);

signals:
    void autoPlayChanged();
    void mutePreviewChanged();
    void startWithSystemChanged();

private:
    QSettings m_settings;
};