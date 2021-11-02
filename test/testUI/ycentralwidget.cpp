#include "ycentralwidget.h"
#include "yregisterui.h"
#include <QHBoxLayout>

YCentralWidget::YCentralWidget(QWidget *parent)
    : QWidget{parent}{
    createCentralWidget();
}//YCentralWidget

void
YCentralWidget::createCentralWidget(){
    _loMain = new QHBoxLayout();
    _uiRX = new YRegisterUi();
    _loMain->addWidget(_uiRX);
    this->setLayout(_loMain);
}//createCentralWidget()
