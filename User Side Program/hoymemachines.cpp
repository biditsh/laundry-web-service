/* CLIENT contructor, first input is the computer ip, second is the socet number and third is the folder that you are requesting
    Sever must be running for the connection to happen, if the socet is not oppen an error message will appear
    setText is used to set the text based on the received information from the server*/

#include "hoymemachines.h"
#include "ui_hoymemachines.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <CLIENT.h>

using namespace std;

HoymeMachines::HoymeMachines(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HoymeMachines)
{
    ui->setupUi(this);
}

HoymeMachines::~HoymeMachines()
{
    delete ui;
}



void HoymeMachines::on_pushButton_clicked()
{
    CLIENT client1 ("130.71.214.164",25279, "hmh-02-123-l" );                       //make sure that the ip address is right and that there is a server running with this socket number
    ui->washer_1_status->setText(QString(client1.returnMachineStatus().c_str()));
    ui->washer_1_timer->setText(QString(client1.returnMachineTimer().c_str()));
}

void HoymeMachines::on_pushButton_2_clicked()
{
    CLIENT client2 ("rns202-13.cs.stolaf.edu",25274, "hmh-01-124-l" );
    ui->label_2->setText(QString(client2.returnMachineStatus().c_str()));
    ui->label_5->setText(QString(client2.returnMachineTimer().c_str()));
}


void HoymeMachines::on_pushButton_3_clicked()
{
    ui->label_3->setText("Open");
    ui->label_6->setText("0 minutes");
}
