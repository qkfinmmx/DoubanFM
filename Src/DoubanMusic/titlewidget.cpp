#include "titlewidget.h"
#include "ui_titlewidget.h"
#include <QMouseEvent>
#include <QDebug>

TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleWidget),
    mbhasPressDown(false),
    miCurrnentPressX(0),
    miCurrnentPressY(0)
{
    ui->setupUi(this);
    ui->objPlayLabel->startAnimate();
}

TitleWidget::~TitleWidget()
{
    delete ui;
}

void TitleWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        mbhasPressDown = true;
        miCurrnentPressX = event->pos().x();
        miCurrnentPressY = event->pos().y();
    }
}

void TitleWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(mbhasPressDown){
        emit mousePressMove(event->globalX()-miCurrnentPressX,
                            event->globalY()-miCurrnentPressY);
    }
}

void TitleWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
         mbhasPressDown = false;
    }
}

void TitleWidget::leaveEvent(QEvent *event)
{
    mbhasPressDown = false;
}
