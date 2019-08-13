#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QtWebKitWidgets/QWebView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Do bit Ao Byte - TTGO T-Camera");

    ui->spinBox->setSingleStep(5);

    this->timer = new QTimer();

    ui->webView->setFixedHeight(280);
    ui->webView->setFixedWidth(380);
    ui->webView->setEnabled(false);

    connect(ui->pushButton_start, SIGNAL(clicked(bool)),this,SLOT(getJPG()));
    connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(fakeStream()));
    connect(this->timer,SIGNAL(timeout()),this,SLOT(getJPG()));


}

void MainWindow::fakeStream()
{
    if (!ui->checkBox->isChecked()){
        qDebug() << "Timer disabled.";
        this->timer->stop();
        return;
    }

    if (ui->spinBox->value() > 0){
        qDebug() << "Starting timer...";
        this->timer->setInterval(ui->spinBox->value()*1000);
        qDebug() << ui->spinBox->value();
        this->timer->start();
        qDebug() << "Done";
    }
}

void MainWindow::getJPG()
{
    ui->webView->setEnabled(true);
    qDebug() << "getting sample...";
    ui->webView->load(QUrl("http://192.168.1.104/jpg"));
    ui->webView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
