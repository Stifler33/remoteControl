//
// Created by bagi3 on 20.03.2022.
//

#ifndef REMOTECONTROL_ADREMOTECONTROL_H
#define REMOTECONTROL_ADREMOTECONTROL_H
#include <QMainWindow>
#include <iostream>
#include <string>
#include <QtWidgets/QLCDNumber>
#include <QString>
#include <thread>
#include <QTimer>
class RemoteControl: public QMainWindow
{
    Q_OBJECT
#define CURRENT_CHANNEL lcdNumber->intValue()
    QString manualNumberChannel;
    void pressButton(char number){
        if ((manualNumberChannel + number).toInt() > 999 || (manualNumberChannel + number).toInt() < 0){
            std::cout << "error\n";
        }else {
            manualNumberChannel += number;
            lcdNumber->display(manualNumberChannel);
        }
    }
public:
    QLCDNumber *lcdNumber = nullptr;
    QTimer *timerExp = new QTimer(this);
    RemoteControl(QWidget *widget = nullptr): QMainWindow(widget){}
    ~RemoteControl() override{
        delete timerExp;
    }
public slots:
    void stopTimer(){
        manualNumberChannel.clear();
        timerExp->stop();
    };
    void timer(){
        if (!timerExp->isActive()) {
            lcdNumber->display(manualNumberChannel);
            timerExp->start(2000);
        }
    }
    void ButtonZero(){
        pressButton('0');
    }
    void ButtonOne(){
        pressButton('1');
    }
    void ButtonTwo(){
        pressButton('2');
    }
    void ButtonThree(){
        pressButton('3');
    }
    void ButtonFour(){
        pressButton('4');
    }
    void ButtonFive(){
        pressButton('5');
    }
    void ButtonSix(){
        pressButton('6');
    }
    void ButtonSeven(){
        pressButton('7');
    }
    void ButtonEight(){
        pressButton('8');
    }
    void ButtonNine(){
        pressButton('9');
    }
    void ButtonCahnelPlus(){
        if (CURRENT_CHANNEL >= 999){
            return;
        }
        lcdNumber->display(CURRENT_CHANNEL+1);
    }
    void ButtonChanelMinus(){
        if (CURRENT_CHANNEL <= 0){
            return;
        }
        lcdNumber->display(CURRENT_CHANNEL-1);
    }
    void ButtonVolumePlus(){}
    void ButtonVolumeMinus(){}
    /*

     */
};
#endif //REMOTECONTROL_ADREMOTECONTROL_H
