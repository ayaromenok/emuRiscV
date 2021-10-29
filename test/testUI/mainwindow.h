#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class YRegisterUi;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void createRegistersUI();
    YRegisterUi*    _uiRX;
};
#endif // MAINWINDOW_H
