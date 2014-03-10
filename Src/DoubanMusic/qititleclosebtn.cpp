#include "qititleclosebtn.h"
#include <QPainter>
#include <QBitmap>
#include <QDebug>
#include <QMouseEvent>

QITitleClosebtn::QITitleClosebtn(QWidget *parent) :
    QWidget(parent),
    hasPressdown(false)
{
    QSize widgetSize(24,24);
    setMinimumSize(widgetSize);
    setMaximumSize(widgetSize);
}

void QITitleClosebtn::paintEvent(QPaintEvent *event)
{
    QPixmap tPixmap;
    tPixmap.load(":/DoubanMusic/img/img/CloseRed_24.png");
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);
    if(hasPressdown){
        QPainter tPaint(&tPixmap);
        tPaint.setRenderHint(QPainter::Antialiasing);
        QBrush tbrush;
        QColor tDivColor(0,0,0,128);
        tbrush.setColor(tDivColor);
        tbrush.setStyle(Qt::SolidPattern);
        tPaint.setPen(Qt::NoPen);
        tPaint.setBrush(tbrush);
        tPaint.drawRect(0,0,24,24);
        QImage tImg = tPixmap.toImage();
        QRgb tRgb = tImg.pixel(0,0);
        for(int i = 0;i<tPixmap.width();i++){
            for(int j=0;j<tPixmap.height();j++){
                if(tImg.pixel(i,j) == tRgb){
                    tImg.setPixel(i,j,QColor(0,0,0,0).rgba());
                }
            }
        }
        paint.drawImage(QPoint(0,0),tImg);
    }else{
        paint.drawPixmap(0,0,tPixmap);
    }
}

void QITitleClosebtn::mousePressEvent(QMouseEvent *event)
{
    hasPressdown = true;
    update();
}

void QITitleClosebtn::mouseReleaseEvent(QMouseEvent *event)
{
    hasPressdown = false;
    update();
    if(event->button() == Qt::LeftButton){
        //TODO:Send Click Signal

    }
}

void QITitleClosebtn::leaveEvent(QEvent *event)
{
    hasPressdown = false;
    update();
}


