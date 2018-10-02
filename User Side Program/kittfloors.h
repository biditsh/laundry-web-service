#ifndef KITTFLOORS_H
#define KITTFLOORS_H

#include <QDialog>

namespace Ui {
class KittFloors;
}

class KittFloors : public QDialog
{
    Q_OBJECT

public:
    explicit KittFloors(QWidget *parent = 0);
    ~KittFloors();

private:
    Ui::KittFloors *ui;
};

#endif // KITTFLOORS_H
