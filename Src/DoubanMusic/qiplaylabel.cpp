#include "qiplaylabel.h"
#include <QPainter>

#define ecllipseSize 8
#define intervalSize 3
#define penWidth 1

QIPlaylabel::QIPlaylabel(QWidget *parent) :
    QWidget(parent),
    mshowellipseCount(0),
    mhAnimateTimeLine(3000,this)
{
    QSize widgetSize(ecllipseSize*5+intervalSize*4+2*penWidth,ecllipseSize+2*penWidth);
    this->setMinimumSize(widgetSize);
    this->setMaximumSize(widgetSize);

    mhAnimateTimeLine.setFrameRange(0,6);
    mhAnimateTimeLine.setLoopCount(0);
    QObject::connect(&mhAnimateTimeLine,SIGNAL(frameChanged(int)),
                     this,SLOT(receiveFramechange(int)));
}

void QIPlaylabel::receiveFramechange(int count)
{
    mshowellipseCount = count;
    this->update();
}

void QIPlaylabel::startAnimate()
{
    mhAnimateTimeLine.start();
}

void QIPlaylabel::pauseAnimate()
{
    mhAnimateTimeLine.setPaused(true);
}

void QIPlaylabel::continueAnimate()
{
    mhAnimateTimeLine.setPaused(false);
}

QRect QIPlaylabel::GetEllipseRect(int x, int y)
{
    QRect rectReturn;
    rectReturn.setX(x);
    rectReturn.setY(y);
    rectReturn.setWidth(ecllipseSize);
    rectReturn.setHeight(ecllipseSize);

    return rectReturn;
}

void QIPlaylabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen whitePen;
    QBrush whiteBrush;
    whitePen.setStyle(Qt::SolidLine);
    whitePen.setColor(QColor(255,255,255));
    whitePen.setWidth(penWidth);
    whiteBrush.setStyle(Qt::SolidPattern);
    whiteBrush.setColor(QColor(255,255,255));
    int tInterval = ecllipseSize + intervalSize;
    for( int i = 0;i < 5; ++i ){
        if( i < mshowellipseCount ){
            painter.setPen(whitePen);
            painter.setBrush(whiteBrush);
            painter.drawEllipse(GetEllipseRect(tInterval * i + penWidth,penWidth));
        }else{
            painter.setPen(whitePen);
            painter.setBrush(Qt::NoBrush);
            painter.drawEllipse(GetEllipseRect(tInterval * i + penWidth,penWidth));
        }
    }
}
