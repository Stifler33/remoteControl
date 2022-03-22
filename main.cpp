#include <QApplication>
#include <QPushButton>
#include "./ui_mainwindow.h"
#include "adRemoteControl.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //QMainWindow RemoteControl(nullptr);
    RemoteControl remoteControl(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&remoteControl);
    remoteControl.lcdNumber = caller.lcdNumber;
    remoteControl.show();
    QObject::connect(remoteControl.timerExp, &QTimer::timeout, &remoteControl, &RemoteControl::stopTimer);
    return QApplication::exec();
}
