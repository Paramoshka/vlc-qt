#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QFrame>
#include "vlc/vlc.h"

class VideoWidget : public QFrame
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);
    void attachVlcPLayer(libvlc_media_player_t *vlcPlayer);

private:
    libvlc_media_player_t *vlcPlayerWidget;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void passMouseCoordinateToVlc(libvlc_media_player_t *vlcPlayer, int, int x, int y);
};

#endif // VIDEOWIDGET_H
