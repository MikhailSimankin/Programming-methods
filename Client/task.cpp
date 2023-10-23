#include "task.h"
#include "ui_task.h"
#include "SingletonClient.h"

task::task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task)
{
    ui->setupUi(this);

}

task::~task()
{
    delete ui;
}


