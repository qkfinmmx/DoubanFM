#ifndef PLAYCONTROL_H
#define PLAYCONTROL_H

#include <QWidget>
#include "requestchannelsobject.h"

namespace Ui {
class playControl;
}

class playControl : public QWidget
{
    Q_OBJECT

public:
    explicit playControl(QWidget *parent = 0);
    ~playControl();

private:
    Ui::playControl *ui;

private:
    virtual void paintEvent(QPaintEvent * event);

signals:
    void btnNextClick();
    void btnPlayPauseClick(int statue);

private slots:
    void slot_btnNextClick();
    void slot_btnPlayPauseClick(int statue);
    void slot_setTime(qint64 pos);

public:
    void setLabelTitle(QString Title);
    void setLabelArtist(QString Artist);
    void setTimeStr(QString TimeStr);
};

#endif // PLAYCONTROL_H
