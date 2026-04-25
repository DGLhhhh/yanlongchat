#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QDialog w(this);
    w.exec();        // exec这个函数会阻塞其他界面响应事件。所以直到我们关闭这个对话框后，exec才返回
    */
    auto s = new QDialog(this);
    s->setWindowFlag(Qt::WindowStaysOnTopHint);
    s->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
