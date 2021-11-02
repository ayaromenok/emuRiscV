#include "mainwindow.h"
#include "ycentralwidget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    setGeometry(0,0,1024,600);
    createCentralWidget();
}
void
MainWindow::createCentralWidget(){
    _centralWidget = new YCentralWidget();
    setCentralWidget(_centralWidget);
}

MainWindow::~MainWindow(){
}

