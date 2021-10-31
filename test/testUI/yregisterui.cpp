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

    addRegistersXName();
    addRegistersXDescr();

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

void
YRegisterUi::addRegistersXName(){
    QVBoxLayout *_loRegsXName = new QVBoxLayout();
    QLabel *_lbRegXNameName = new QLabel("X:name");
    _lbRegXNameName->setObjectName("_lbRegXNameName");
    _loRegsXName->addWidget(_lbRegXNameName);

    for (int i=0; i<32; i++){
        QString _lbXValue = QString("x"+QString::number(i));
        switch(i){
            case (0):_lbXValue.append("/Zero");
                break;
            case (1):_lbXValue.append("/ra");
                break;
            case (2):_lbXValue.append("/sp");
                break;
            case (3):_lbXValue.append("/gp");
                break;
            case (4):_lbXValue.append("/tp");
                break;
            case (5):_lbXValue.append("/t0");
                break;
            case (6):_lbXValue.append("/t1");
                break;
            case (7):_lbXValue.append("/t2");
                break;
            case (8):_lbXValue.append("/s0/fp");
                break;
            case (9):_lbXValue.append("/s1");
                break;
            case (10):
            case (11):
            case (12):
            case (13):
            case (14):
            case (15):
            case (16):
            case (17):
                    _lbXValue.append("/a"+QString::number(i-10));
                break;
            case (28):
            case (29):
            case (30):
            case (31):
                _lbXValue.append("/t"+QString::number(i-25));
            break;
            default:
            _lbXValue.append("/s"+QString::number(i-16));
        }
        QLabel *_lbXName = new QLabel(_lbXValue);
        _lbXName->setObjectName("lbXName_"+QString::number(i));
        _loRegsXName->addWidget(_lbXName);
    }//for

    if(loRegs){
        loRegs->addLayout(_loRegsXName);
    }
}//addRegistersXName

void
YRegisterUi::addRegistersXDescr(){
    QVBoxLayout *_loRegsXDescr = new QVBoxLayout();
    QLabel *_lbRegXDescrName = new QLabel("X:Decription");
    _lbRegXDescrName->setObjectName("_lbRegXDescrName");
    _loRegsXDescr->addWidget(_lbRegXDescrName);
    if(loRegs){
        loRegs->addLayout(_loRegsXDescr);
    }
}//addRegistersXDescription
