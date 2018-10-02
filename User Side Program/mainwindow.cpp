#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hoymefloors.h"
#include <QDesktopServices>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QUrl>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{
    HoymeFloors hFl;
    hFl.setModal(true);
    hFl.exec();
}

void MainWindow::on_pushButton_clicked()
{
    QString link = "http://www.cs.stolaf.edu/wiki/index.php/LaundryB";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_pushButton_2_clicked()
{
    QString link = "http://www.cs.stolaf.edu/wiki/images/2/2e/LaundryWebServiceUseM.pdf";
    QDesktopServices::openUrl(QUrl(link));
}
