#include "hoymefloors.h"
#include "ui_hoymefloors.h"
#include "hoymemachines.h"
#include "hoymemachines2.h"

HoymeFloors::HoymeFloors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HoymeFloors)
{
    ui->setupUi(this);
}

HoymeFloors::~HoymeFloors()
{
    delete ui;
}

void HoymeFloors::on_pushButton_clicked()
{
    HoymeMachines hMch;
    hMch.setModal(true);
    hMch.exec();
}

void HoymeFloors::on_pushButton_2_clicked()
{
    HoymeMachines2 hMch2;
    hMch2.setModal(true);
    hMch2.exec();
}
