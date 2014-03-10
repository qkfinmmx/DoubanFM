#ifndef PLAYPAUSEWIDGET_H
#define PLAYPAUSEWIDGET_H

#include <QWidget>

class PlayPauseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlayPauseWidget(QWidget *parent = 0);

enum {
    ShowPlay,
    ShowPause
};

enum {
    GreenStatue,
    WhiteStatue
};

private:
    int mBtnStatue;
    int mColorStatue;

private:
    virtual void paintEvent(QPaintEvent * event);

public:
    void changeBtnAllStatue(int showstatue,int colorstatue);
    void changeBtnColorStatue(int colorstatue);
    void changeBtnShowStatue(int showstatue);
    int GetBtnstatue();
};

#endif // PLAYPAUSEWIDGET_H
