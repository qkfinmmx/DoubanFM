#ifndef QILIKEWIDGET_H
#define QILIKEWIDGET_H

#include <QWidget>

class QILikeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QILikeWidget(QWidget *parent = 0);

    enum{
        showGray,
        showPink
    };

private:
    int mshowType;
    bool btnpressed;

public:
    void setshowType(int type);
    int getshowType();

private:
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);

signals:
    void ChangeBtnType(int type);
};

#endif // QILIKEWIDGET_H
