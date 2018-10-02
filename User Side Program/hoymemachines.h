#ifndef HOYMEMACHINES_H
#define HOYMEMACHINES_H

#include <QDialog>

namespace Ui {
class HoymeMachines;
}

class HoymeMachines : public QDialog
{
    Q_OBJECT

public:
    explicit HoymeMachines(QWidget *parent = 0);
    ~HoymeMachines();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::HoymeMachines *ui;
};

#endif // HOYMEMACHINES_H
