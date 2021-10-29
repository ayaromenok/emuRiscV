#ifndef YREGISTERUI_H
#define YREGISTERUI_H

#include <QObject>
#include <QWidget>
class QHBoxLayout;
class YRegisterUi : public QWidget
{
    Q_OBJECT

public:
    explicit YRegisterUi(QWidget *parent = nullptr);
    void setRegisterX(int num, int value);

signals:

private:
    void addRegistersXb();
    QHBoxLayout*     loRegs;
};

#endif // YREGISTERUI_H
