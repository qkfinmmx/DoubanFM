#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playpausewidget.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mMediaPlayer(new DoMediaPlayer)
{
    ui->setupUi(this);

    // Up Title Widget
    ui->objTitleWidget->raise();

    // Add window style
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
                   Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    // Paint Attribte
    setAttribute(Qt::WA_TranslucentBackground);

    //singal
    QObject::connect(ui->objTitleWidget,SIGNAL(mousePressMove(int,int)),this,SLOT(MoveWindow(int,int)));
    QObject::connect(ui->WidgetControl,SIGNAL(btnNextClick()),this,SLOT(slot_BtnNextClick()));
    QObject::connect(ui->WidgetControl,SIGNAL(btnPlayPauseClick(int)),this,SLOT(slot_BtnPlayPauseClick(int)));
    QObject::connect(mMediaPlayer,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
                     this,SLOT(slot_mediaStatueChanged(QMediaPlayer::MediaStatus)));
    QObject::connect(mMediaPlayer,SIGNAL(positionChanged(qint64)),ui->WidgetControl,SLOT(slot_setTime(qint64)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QSize shadowsize(2,2);
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(shadowsize.width(), shadowsize.height(),
                 this->width()-2*shadowsize.width(), this->height()-2*shadowsize.height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::NoBrush));

    QColor color(128,128,128,50);
    for(int i=0; i<shadowsize.width(); i++){
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(shadowsize.width()-i, shadowsize.height()-i,
                     this->width()-(shadowsize.width()-i)*2, this->height()-(shadowsize.height()-i)*2);
        color.setAlpha(150 - qSqrt(i)*50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}

void MainWindow::MoveWindow(int gloableX, int gloableY)
{
    move(gloableX,gloableY);
}

void MainWindow::slot_BtnNextClick()
{
    if(mMediaPlayer->state() == QMediaPlayer::PlayingState){
        if(mMediaPlayer->mediaStatus() == QMediaPlayer::BufferedMedia){
             mMediaPlayer->PlayNextMusic();
        }
    }else{
        mMediaPlayer->PlayNextMusic();
    }
}

void MainWindow::slot_mediaStatueChanged(QMediaPlayer::MediaStatus status)
{
    switch(status){
    case QMediaPlayer::LoadingMedia:{
        ui->WidgetControl->setLabelArtist(mMediaPlayer->GetCurrentMusicArtist());
        ui->WidgetControl->setLabelTitle(mMediaPlayer->GetCurrentMusicTitle());
        break;
    }
    default:
        break;
    }
}

void MainWindow::slot_BtnPlayPauseClick(int statue)
{
    switch(statue){
    case PlayPauseWidget::ShowPlay:{
        mMediaPlayer->pause();
        break;
    }
    case PlayPauseWidget::ShowPause:{
        mMediaPlayer->play();
        break;
    }
    default:
        break;
    }
}
