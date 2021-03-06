#include "qideletewidget.h"
#include <QPainter>

QIDeleteWidget::QIDeleteWidget(QWidget *parent) :
    QWidget(parent),
    hasPressdown(false)
{
}

void QIDeleteWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);
    QPixmap tDrawPix(":/DoubanMusic/img/img/recycle_32.png");
    if(hasPressdown){
        QPainter tPaint(&tDrawPix);
        tPaint.setRenderHint(QPainter::Antialiasing);
        QBrush tbrush;
        QColor tDivColor(255,255,255,128);
        tbrush.setColor(tDivColor);
        tbrush.setStyle(Qt::SolidPattern);
        tPaint.setPen(Qt::NoPen);
        tPaint.setBrush(tbrush);
        tPaint.drawRect(0,0,32,32);
        QImage tImg = tDrawPix.toImage();
        QRgb tRgb = tImg.pixel(0,0);
        for(int i = 0;i<tDrawPix.width();i++){
            for(int j=0;j<tDrawPix.height();j++){
                if(tImg.pixel(i,j) == tRgb){
                    tImg.setPixel(i,j,QColor(0,0,0,0).rgba());
                }
            }
        }
        paint.drawImage(QPoint(0,0),tImg);
    }else{
        paint.drawPixmap(0,0,tDrawPix);
    }
}

void QIDeleteWidget::mousePressEvent(QMouseEvent *event)
{
    hasPressdown = true;
    update();
}

void QIDeleteWidget::mouseReleaseEvent(QMouseEvent *event)
{
    hasPressdown = false;
    update();
}
