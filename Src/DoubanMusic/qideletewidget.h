#ifndef QIDELETEWIDGET_H
#define QIDELETEWIDGET_H

#include <QWidget>

class QIDeleteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QIDeleteWidget(QWidget *parent = 0);

private:
    bool hasPressdown;

private:
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
};

#endif // QIDELETEWIDGET_H
