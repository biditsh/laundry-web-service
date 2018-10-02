#include "hoymemachines2.h"
#include "ui_hoymemachines2.h"

HoymeMachines2::HoymeMachines2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HoymeMachines2)
{
    ui->setupUi(this);
}

HoymeMachines2::~HoymeMachines2()
{
    delete ui;
}


void HoymeMachines2::on_pushButton_clicked()
{
    ui->washer_1_status->setText("In use");
    ui->washer_1_timer->setText("19 minutes");
}

void HoymeMachines2::on_pushButton_2_clicked()
{
    ui->label_3->setText("Open");
    ui->label_4->setText("0 minutes");
}

void HoymeMachines2::on_pushButton_3_clicked()
{
    ui->label_5->setText("In use");
    ui->label_6->setText("33 minutes");
}
