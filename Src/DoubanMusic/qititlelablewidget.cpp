#include "qititlelablewidget.h"
#include <QPainter>

QITitleLableWidget::QITitleLableWidget(QWidget *parent) :
    QWidget(parent)
{
    setMinimumWidth(80);
    setMinimumHeight(24);
}

void QITitleLableWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);
    QFont font;
    font.setFamily(QStringLiteral("微软雅黑"));
    font.setPointSize(10);
    QPen tPen;
    tPen.setColor(QColor(255,255,255));
    tPen.setStyle(Qt::SolidLine);
    paint.setPen(tPen);
    paint.setFont(font);
    paint.drawText(0,-2,75,24,Qt::AlignCenter,QStringLiteral("豆瓣音乐 FM"));
}
