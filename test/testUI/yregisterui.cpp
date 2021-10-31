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
    addRegistersXh();
    addRegistersXd();
    this->setLayout(loRegs);
    //qDebug() <<this->children();

    setRegisterX(0,1);
    setRegisterX(1,12);
    setRegisterX(2,123);
    setRegisterX(3,1234);
    setRegisterX(4,12345);
    setRegisterX(5,123456);
    setRegisterX(6,1234567);
    setRegisterX(7,123456789);
    setRegisterX(8,1234567890);
}//YRegisterUi()

void YRegisterUi::setRegisterX(int num, int value){    
    //binary mode
    if(this->findChild<QLabel *>("lbXb_"+QString::number(num))){
        QString _value(QString::number(value,2));
        QString _sValue("00000000000000000000000000000000");
        this->findChild<QLabel *>("lbXb_"+QString::number(num))->setText(_sValue.chopped(_value.length())+_value);
    } else {
        qWarning() << "Register:binary " << num << "not found";
    }//if
    //hexademicalmode
    if(this->findChild<QLabel *>("lbXh_"+QString::number(num))){
        QString _value(QString::number(value,16));
        QString _sValue("00000000");
        this->findChild<QLabel *>("lbXh_"+QString::number(num))->setText(_sValue.chopped(_value.length())+_value.toUpper());
    } else {
        qWarning() << "Register:hexademical " << num << "not found";
    }//if
    //decemical
    if(this->findChild<QLabel *>("lbXd_"+QString::number(num))){
        QString _value(QString::number(value,10));
        QString _sValue("0000000000");
        this->findChild<QLabel *>("lbXd_"+QString::number(num))->setText(_sValue.chopped(_value.length())+_value.toUpper());
    } else {
        qWarning() << "Register:hexademical " << num << "not found";
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

void
YRegisterUi::addRegistersXh(){
    QVBoxLayout *_loRegsXh = new QVBoxLayout();
    QLabel *_lbRegXhName = new QLabel("X:hex");
    _lbRegXhName->setObjectName("_lbRegXbName");
    _loRegsXh->addWidget(_lbRegXhName);
    for (int i=0; i<32; i++){
        QLabel *_lbXh = new QLabel("00000000");
        _lbXh->setMinimumWidth(240);
        _lbXh->setObjectName("lbXh_"+QString::number(i));
        _loRegsXh->addWidget(_lbXh);
    }//for
    if(loRegs){
        loRegs->addLayout(_loRegsXh);
    }
}//addRegistersXb()

void
YRegisterUi::addRegistersXd(){
    QVBoxLayout *_loRegsXd = new QVBoxLayout();
    QLabel *_lbRegXdName = new QLabel("X:dec");
    _lbRegXdName->setObjectName("_lbRegXdName");
    _loRegsXd->addWidget(_lbRegXdName);
    for (int i=0; i<32; i++){
        QLabel *_lbXd = new QLabel("0000000000");
        _lbXd->setMinimumWidth(240);
        _lbXd->setObjectName("lbXd_"+QString::number(i));
        _loRegsXd->addWidget(_lbXd);
    }//for
    if(loRegs){
        loRegs->addLayout(_loRegsXd);
    }
}//addRegistersXb()
