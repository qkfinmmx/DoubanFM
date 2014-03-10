#include "qilikewidget.h"
#include <QPainter>

QILikeWidget::QILikeWidget(QWidget *parent) :
    QWidget(parent),
    mshowType(showGray),
    btnpressed(false)
{
}

void QILikeWidget::setshowType(int type)
{
    mshowType = type;
}

int QILikeWidget::getshowType()
{
    return mshowType;
}

void QILikeWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);
    QPixmap tPixmap;
    switch(mshowType){
    case QILikeWidget::showGray:{
        tPixmap.load(":/DoubanMusic/img/img/like_32.png");
        paint.drawPixmap(0,0,tPixmap);
        break;
    }
    case QILikeWidget::showPink:{
        tPixmap.load(":/DoubanMusic/img/img/like_32_pink.png");
        paint.drawPixmap(0,0,tPixmap);
        break;
    }
    default:
        break;
    }

    // draw div
    if(btnpressed){
        QPainter tPaint(&tPixmap);
        tPaint.setRenderHint(QPainter::Antialiasing);
        QBrush tbrush;
        QColor tDivColor(255,255,255,128);
        tbrush.setColor(tDivColor);
        tbrush.setStyle(Qt::SolidPattern);
        tPaint.setPen(Qt::NoPen);
        tPaint.setBrush(tbrush);
        tPaint.drawRect(0,0,32,32);
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
    }
}

void QILikeWidget::mousePressEvent(QMouseEvent *event)
{
    btnpressed = true;
    update();
    QWidget::mousePressEvent(event);
}

void QILikeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    btnpressed = false;
    switch (mshowType) {
    case QILikeWidget::showGray:{
        this->setshowType(QILikeWidget::showPink);
        emit ChangeBtnType(QILikeWidget::showPink);
        break;
    }
    case QILikeWidget::showPink:{
        this->setshowType(QILikeWidget::showGray);
        emit ChangeBtnType(QILikeWidget::showGray);
        break;
    }
    default:
        break;
    }
    update();
    QWidget::mouseReleaseEvent(event);
}
