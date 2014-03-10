#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "domediaplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    DoMediaPlayer* mMediaPlayer;

private:
    virtual void paintEvent(QPaintEvent * event);

private slots:
    void MoveWindow(int gloableX,int gloableY);
    void slot_BtnNextClick();
    void slot_mediaStatueChanged(QMediaPlayer::MediaStatus status);
    void slot_BtnPlayPauseClick(int statue);
};

#endif // MAINWINDOW_H
