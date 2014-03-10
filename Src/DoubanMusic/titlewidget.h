#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

namespace Ui {
class TitleWidget;
}

class TitleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TitleWidget(QWidget *parent = 0);
    ~TitleWidget();

private:
    Ui::TitleWidget *ui;
    bool mbhasPressDown;
    int miCurrnentPressX;
    int miCurrnentPressY;

private:
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void leaveEvent(QEvent * event);

signals:
    void mousePressMove(int gloableX,int gloableY);
};

#endif // TITLEWIDGET_H
