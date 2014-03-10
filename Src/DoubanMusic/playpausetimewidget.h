#ifndef PLAYPAUSETIMEWIDGET_H
#define PLAYPAUSETIMEWIDGET_H

#include <QWidget>

namespace Ui {
class PlayPauseTimeWidget;
}

class PlayPauseTimeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayPauseTimeWidget(QWidget *parent = 0);
    ~PlayPauseTimeWidget();

private:
    Ui::PlayPauseTimeWidget *ui;
    bool entered;
    bool presseddown;

private:
    virtual void enterEvent(QEvent * event);
    virtual void leaveEvent(QEvent * event);
    virtual void paintEvent(QPaintEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);

signals:
    void playpauseChanged(int statue);

public slots:
    void SetTimeLabel(QString Str_time);
};

#endif // PLAYPAUSETIMEWIDGET_H
