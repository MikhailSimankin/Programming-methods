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

void task::slot_task_generator(QString str)
{
    qDebug() << "Str in task" << str;
    QList <QString> task = str.split('&');
    QString variant = task[1];
    QString generator = task[2];
    ui -> label_task -> setText(generator);
    ui -> label_task ->setWordWrap(true);
    if (variant == "1")
        ui -> label_variant -> setText(variant + ": по М1  проверить функцию на самодвойственность");

    this -> show();
}


void task::on_pushButton_send_clicked()
{
    QString Answer = ui ->  lineEdit_answer -> text();
    QString Task = ui -> label_task -> text();
    QString Variant = ui -> label_variant -> text();
    QString check = "check_answer&" + Task + "&" + Answer + "&" + Variant ;
    SingletonClient::getInstance()->send_msg_to_server(check);
    ui -> lineEdit_answer -> clear();
}


void task::on_pushButton_exit_clicked()
{
    this -> close();
}


//void task::on_pushButton_back_clicked()
//{
//    qDebug() << "Back";
//    emit signal_mainwindow();
//}

//QString task::generator_task(QString task)
//{
//    QList <QString> new_str = task.split('&');
//    return task[2];
//}

