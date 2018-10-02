#ifndef HOYMEFLOORS_H
#define HOYMEFLOORS_H

#include <QDialog>

namespace Ui {
class HoymeFloors;
}

class HoymeFloors : public QDialog
{
    Q_OBJECT

public:
    explicit HoymeFloors(QWidget *parent = 0);
    ~HoymeFloors();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::HoymeFloors *ui;
};

#endif // HOYMEFLOORS_H
