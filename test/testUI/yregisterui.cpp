#include "yregisterui.h"
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

YRegisterUi::YRegisterUi(QWidget *parent)
    : QWidget{parent}
{
    loRegs = new QHBoxLayout();
    addRegistersXb();
    //addRegistersXd();
    this->setLayout(loRegs);
    //qDebug() <<this->children();

    setRegisterX(0,27);
    setRegisterX(2,27);
}//YRegisterUi()

void YRegisterUi::setRegisterX(int num, int value){    
    if(this->findChild<QLabel *>("lbXb_"+QString::number(num))){
        QString _value(QString::number(value,2));
        QString _sValue("00000000000000000000000000000000");
        this->findChild<QLabel *>("lbXb_"+QString::number(num))->setText(_sValue.chopped(_value.length())+_value);
    } else {
        qWarning() << "Register " << num << "not found";
    }//if
}//setRegisterX()

void
YRegisterUi::addRegistersXb(){
    QVBoxLayout *_loRegsXb = new QVBoxLayout();
    QLabel *_lbRegXbName = new QLabel("XRegisters:binary");
    _lbRegXbName->setObjectName("_lbRegXbName");
    _loRegsXb->addWidget(_lbRegXbName);
    for (int i=0; i<32; i++){
        //"0000 0000 0000 0000  0000 0000 0000 0000"
        QLabel *_lbXb = new QLabel("00000000000000000000000000000000");
        _lbXb->setMinimumWidth(240);
        //_lbXb->setAlignment(Qt::AlignRight);
        _lbXb->setObjectName("lbXb_"+QString::number(i));
        _loRegsXb->addWidget(_lbXb);
    }//for
    if(loRegs){
        loRegs->addLayout(_loRegsXb);
    }

}//addRegistersXb()
