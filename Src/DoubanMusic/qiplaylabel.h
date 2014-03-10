#ifndef QIPLAYLABEL_H
#define QIPLAYLABEL_H

#include <QWidget>
#include <QTimeLine>

class QIPlaylabel : public QWidget
{
    Q_OBJECT
public:
    explicit QIPlaylabel(QWidget *parent = 0);

private:
    int mshowellipseCount;
    QTimeLine mhAnimateTimeLine;

private:
    QRect GetEllipseRect(int x,int y);
    virtual void paintEvent(QPaintEvent * event);

private slots:
    void receiveFramechange(int count);

public slots:
    void startAnimate();
    void pauseAnimate();
    void continueAnimate();
};

#endif // QIPLAYLABEL_H
