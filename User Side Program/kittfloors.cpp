#include "kittfloors.h"
#include "ui_kittfloors.h"

KittFloors::KittFloors(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KittFloors)
{
    ui->setupUi(this);
}

KittFloors::~KittFloors()
{
    delete ui;
}
