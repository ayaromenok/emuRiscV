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
    void addRegistersXd();
    void addRegistersXh();
    void addRegistersXName();
    void addRegistersXDescr();

    QHBoxLayout*     loRegs;
};

#endif // YREGISTERUI_H
