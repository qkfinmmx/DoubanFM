#include "playpausewidget.h"
#include <QPainter>

PlayPauseWidget::PlayPauseWidget(QWidget *parent) :
    QWidget(parent),
    mBtnStatue(ShowPause),
    mColorStatue(GreenStatue)
{
}

void PlayPauseWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);
    QColor tFrontColor;
    switch(mColorStatue){
    case GreenStatue:{
        tFrontColor.setRgb(77,151,132);
        break;
    }
    case WhiteStatue:{
        tFrontColor.setRgb(255,255,255);
        break;
    }
    default:
        break;
    }
    switch(mBtnStatue){
    case ShowPlay:{
        QBrush tBrush;
        tBrush.setStyle(Qt::SolidPattern);
        tBrush.setColor(tFrontColor);
        paint.setPen(Qt::NoPen);
        paint.setBrush(tBrush);
        QPointF tPoints[3] = {
            QPointF(1,4),
            QPointF(18,12),
            QPointF(1,20),
        };
        paint.drawConvexPolygon(tPoints,3);
        break;
    }
    case ShowPause:{
        QBrush tBrush;
        tBrush.setStyle(Qt::SolidPattern);
        tBrush.setColor(tFrontColor);
        paint.setPen(Qt::NoPen);
        paint.setBrush(tBrush);
        paint.drawRect(3,3,5,18);
        paint.drawRect(12,3,5,18);
        break;
    }
    default:
        break;
    }
}

void PlayPauseWidget::changeBtnAllStatue(int showstatue, int colorstatue)
{
    mBtnStatue = showstatue;
    mColorStatue = colorstatue;
    update();
}

void PlayPauseWidget::changeBtnColorStatue(int colorstatue)
{
    mColorStatue = colorstatue;
    update();
}

void PlayPauseWidget::changeBtnShowStatue(int showstatue)
{
    mBtnStatue = showstatue;
    update();
}

int PlayPauseWidget::GetBtnstatue()
{
    return mBtnStatue;
}
