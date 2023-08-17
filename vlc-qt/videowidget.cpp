#include "videowidget.h"

VideoWidget::VideoWidget(QWidget *parent)
    : QFrame(parent)
{

}

void VideoWidget::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "mouse press";
    QFrame::mousePressEvent(event);
}

void VideoWidget::mouseMoveEvent(QMouseEvent* event)
{

    int x = this->cursor().pos().x();
    int y = this->cursor().pos().y();
    qDebug() << x;
    qDebug() << y;


    if (vlcPlayerWidget != NULL) {
        passMouseCoordinateToVlc(vlcPlayerWidget, 0, x, y);
        qDebug() << "mouse move vlc";
    }
    qDebug() << "mouse move";
    QFrame::mousePressEvent(event);
}


void VideoWidget::passMouseCoordinateToVlc(libvlc_media_player_t *vlcPlayer, int num, int x, int y) {
    libvlc_video_get_cursor(vlcPlayer, num, &x, &y);
}

void VideoWidget::attachVlcPLayer(libvlc_media_player_t *vlcPlayer) {
    vlcPlayerWidget = vlcPlayer;
}

