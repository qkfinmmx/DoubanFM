#ifndef QITITLELABLEWIDGET_H
#define QITITLELABLEWIDGET_H

#include <QWidget>

class QITitleLableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QITitleLableWidget(QWidget *parent = 0);

private:
    virtual void paintEvent(QPaintEvent * event);
};

#endif // QITITLELABLEWIDGET_H
