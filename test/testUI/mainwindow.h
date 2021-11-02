#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class YCentralWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void createCentralWidget();
    YCentralWidget*     _centralWidget;
};
#endif // MAINWINDOW_H
