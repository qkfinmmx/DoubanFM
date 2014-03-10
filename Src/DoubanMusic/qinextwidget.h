#ifndef QINEXTWIDGET_H
#define QINEXTWIDGET_H

#include <QWidget>

class QINextWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QINextWidget(QWidget *parent = 0);

private:
    bool hasPressdown;

private:
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);

signals:
    void customclick();
};

#endif // QINEXTWIDGET_H
