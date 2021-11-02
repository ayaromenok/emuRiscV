#ifndef YCENTRALWIDGET_H
#define YCENTRALWIDGET_H

#include <QWidget>
class YRegisterUi;
class QHBoxLayout;

class YCentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YCentralWidget(QWidget *parent = nullptr);

signals:
private:
    void createCentralWidget();
    YRegisterUi*    _uiRX;
    QHBoxLayout*    _loMain;
};

#endif // YCENTRALWIDGET_H
