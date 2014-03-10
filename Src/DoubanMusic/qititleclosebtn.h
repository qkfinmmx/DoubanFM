#ifndef QITITLECLOSEBTN_H
#define QITITLECLOSEBTN_H

#include <QWidget>

class QITitleClosebtn : public QWidget
{
    Q_OBJECT
public:
    explicit QITitleClosebtn(QWidget *parent = 0);

private:
    bool hasPressdown;

private:
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void leaveEvent(QEvent * event);

signals:
    void leftbtnClick();
};

#endif // QITITLECLOSEBTN_H
