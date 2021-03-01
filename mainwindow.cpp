#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    request=new PostRequest (this);
    connect(request,SIGNAL(done(QString&)),this,SLOT(slotDone(QString&)));
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotGo()
{
    request->sendJson(QUrl("http://192.168.31.104:8080/put_clock"));
}

void MainWindow::slotDone(QString &message)
{

    ui->label->setText(message);
}




