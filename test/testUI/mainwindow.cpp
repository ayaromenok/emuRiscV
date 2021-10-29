#include "mainwindow.h"
#include "yregisterui.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    setGeometry(0,0,1024,600);
    createRegistersUI();

}
void
MainWindow::createRegistersUI(){
    _uiRX = new YRegisterUi();
    setCentralWidget(_uiRX);
}

MainWindow::~MainWindow(){
}

