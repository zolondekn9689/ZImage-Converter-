#include "prefdialog.h"
#include "ui_prefdialog.h"

PrefDialog::PrefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrefDialog)
{
    ui->setupUi(this);
}

PrefDialog::~PrefDialog()
{
    delete ui;
}
