#include "playcontrol.h"
#include "ui_playcontrol.h"
#include <QPainter>
#include <QDebug>

playControl::playControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playControl)
{
    ui->setupUi(this);

    QFont tFont;
    tFont.setFamily(QStringLiteral("微软雅黑"));
    tFont.setPointSize(12);
    tFont.setWeight(QFont::Normal);

    ui->labelTitle->setFont(tFont);
    ui->labelArtist->setFont(tFont);

    // connect
    QObject::connect(ui->widgetNext,SIGNAL(customclick()),this,SLOT(slot_btnNextClick()));
    QObject::connect(ui->widgetPlay,SIGNAL(playpauseChanged(int)),this,SLOT(slot_btnPlayPauseClick(int)));
}

playControl::~playControl()
{
    delete ui;
}

void playControl::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    QColor backgroundColor(231,237,233);
    QBrush tBrush;
    tBrush.setStyle(Qt::SolidPattern);
    tBrush.setColor(backgroundColor);
    paint.setBrush(tBrush);
    paint.setPen(Qt::NoPen);
    paint.drawRect(0,0,width(),height());
}

void playControl::slot_btnNextClick()
{
    emit btnNextClick();
}

void playControl::slot_btnPlayPauseClick(int statue)
{
    emit btnPlayPauseClick(statue);
}

void playControl::slot_setTime(qint64 pos)
{
    int tMin = (pos/1000)/60;
    int tSec = (pos/1000)%60;
    QString tStrMin,tStrSec;
    tStrMin = tStrMin.sprintf("%d",tMin);
    tStrSec = tStrSec.sprintf("%d",tSec);
    if(tStrSec.length()<2){
        tStrSec = "0"+tStrSec;
    }
    ui->widgetPlay->SetTimeLabel(tStrMin+":"+tStrSec);
}

void playControl::setLabelTitle(QString Title)
{
    ui->labelTitle->setText(Title);
}

void playControl::setLabelArtist(QString Artist)
{
    ui->labelArtist->setText(Artist);
}

void playControl::setTimeStr(QString TimeStr)
{
    ui->widgetPlay->SetTimeLabel(TimeStr);
}
