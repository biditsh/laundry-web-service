#ifndef HOYMEMACHINES2_H
#define HOYMEMACHINES2_H

#include <QDialog>

namespace Ui {
class HoymeMachines2;
}

class HoymeMachines2 : public QDialog
{
    Q_OBJECT

public:
    explicit HoymeMachines2(QWidget *parent = 0);
    ~HoymeMachines2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::HoymeMachines2 *ui;
};

#endif // HOYMEMACHINES2_H
