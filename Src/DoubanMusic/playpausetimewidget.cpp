#include "playpausetimewidget.h"
#include "ui_playpausetimewidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

PlayPauseTimeWidget::PlayPauseTimeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayPauseTimeWidget),
    entered(false),
    presseddown(false)
{
    ui->setupUi(this);
}

PlayPauseTimeWidget::~PlayPauseTimeWidget()
{
    delete ui;
}

void PlayPauseTimeWidget::enterEvent(QEvent *event)
{
    entered = true;
    ui->BtnWidget->changeBtnColorStatue(PlayPauseWidget::WhiteStatue);
    ui->TimeLabel->setStyleSheet("color: rgb(255, 255, 255);");
    update();
}

void PlayPauseTimeWidget::leaveEvent(QEvent *event)
{
    entered = false;
    ui->BtnWidget->changeBtnColorStatue(PlayPauseWidget::GreenStatue);
    ui->TimeLabel->setStyleSheet("color: rgb(77, 151, 132);");
    update();
}

void PlayPauseTimeWidget::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);

    if(entered){
        QColor tBackColor;
        if(presseddown){
            tBackColor.setRgb(77,151,132);
        }else{
            tBackColor.setRgb(77,151,132,100);
        }
        QBrush tBrush;
        tBrush.setStyle(Qt::SolidPattern);
        tBrush.setColor(tBackColor);
        paint.setBrush(tBrush);
        paint.setPen(Qt::NoPen);
        paint.drawRoundedRect(this->rect(),2,2);
    } else{
        QColor tBackColor;
        tBackColor.setRgb(255,255,255,0);
        QBrush tBrush;
        tBrush.setStyle(Qt::SolidPattern);
        tBrush.setColor(tBackColor);
        paint.setBrush(tBrush);
        paint.setPen(Qt::NoPen);
        paint.drawRect(this->rect());
    }
}

void PlayPauseTimeWidget::mousePressEvent(QMouseEvent *event)
{
    presseddown = true;
    update();
    QWidget::mousePressEvent(event);
}

void PlayPauseTimeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    presseddown = false;
    switch(ui->BtnWidget->GetBtnstatue()){
    case PlayPauseWidget::ShowPlay:{
        ui->BtnWidget->changeBtnShowStatue(PlayPauseWidget::ShowPause);
        emit playpauseChanged(PlayPauseWidget::ShowPause);
        break;
    }
    case PlayPauseWidget::ShowPause:{
        ui->BtnWidget->changeBtnShowStatue(PlayPauseWidget::ShowPlay);
        emit playpauseChanged(PlayPauseWidget::ShowPlay);
        break;
    }
    default:
        break;
    }
    update();
    QWidget::mouseReleaseEvent(event);
}

void PlayPauseTimeWidget::SetTimeLabel(QString Str_time)
{
    ui->TimeLabel->setText(Str_time);
}
