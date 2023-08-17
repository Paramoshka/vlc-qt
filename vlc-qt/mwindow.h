/******************************
 * Qt player using libVLC     *
 * By protonux                *
 *                            *
 * Under WTFPL                *
 ******************************/

#ifndef PLAYER
#define PLAYER

#include <QtGui>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QWidget>
#include <vlc/vlc.h>
#include "videowidget.h"

class Mwindow : public QMainWindow {

    Q_OBJECT

public:
    Mwindow();
    virtual ~Mwindow();

private slots:
    void openFile();
    void play();
    void stop();
    void mute();
    void about();
    void fullscreen();
    void playUrl();
    int changeVolume(int);
    void changePosition(int);
    void updateInterface();

protected:
    virtual void closeEvent(QCloseEvent*);
    void keyPressEvent(QKeyEvent* event) override;


private:
    QPushButton *playBut;
    QSlider *volumeSlider;
    QSlider *slider;
    VideoWidget *videoWidget;

    libvlc_instance_t *vlcInstance;
    libvlc_media_player_t *vlcPlayer;

    void initUI();
};


#endif
