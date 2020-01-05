#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zoo.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Zoo *zoo = Zoo::getInstance("ZooTycoon");
    ui->lbl_zooName->setText(zoo->getName());
    setEditMode(false);
    ui->Messagebox->hide();
    ui->lineEdit_zooName->move(ui->lbl_zooName->pos());
    ui->btn_validateZooName->move(ui->btn_updateZooName->pos());
    zoo->testMe();
    updateBudgetDisplay();
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_updateZooName_clicked()
{
    setEditMode(true);
}

void MainWindow::on_lineEdit_zooName_returnPressed()
{
    setEditMode(false);
}

void MainWindow::setEditMode(bool editMode)
{
    QLineEdit *zooName = ui->lineEdit_zooName;

    ui->lbl_zooName->hide();
    zooName->hide();
    ui->btn_updateZooName->hide();
    ui->btn_validateZooName->hide();
    // https://useaxentix.com
    if(editMode){
        zooName->show();
        ui->btn_validateZooName->show();
        zooName->setFocus();
        zooName->setText(ui->lbl_zooName->text());
    } else {
        ui->lbl_zooName->show();
        ui->btn_updateZooName->show();

        if(zooName->text() != ""){
            Zoo::getInstance()->setName(zooName->text());
            ui->lbl_zooName->setText(Zoo::getInstance()->getName());
        }
    }

    qDebug() << Q_FUNC_INFO << Zoo::getInstance()->getName();
}

void MainWindow::upadteDisplay()
{
    updateMessagesDisplay();
    updateBudgetDisplay();
}

void MainWindow::updateBudgetDisplay()
{
    ui->lbl_budget->setText(QString::number(Zoo::getInstance()->getMoney()));
}

void MainWindow::updateMessagesDisplay()
{

}

void MainWindow::on_btn_validateZooName_clicked()
{
    setEditMode(false);
}

void MainWindow::on_btn_earn_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->addMoney(50);
    updateBudgetDisplay();
}

void MainWindow::on_btn_spend_clicked()
{
    Zoo *zoo = Zoo::getInstance();
    zoo->removeMoney(30);
    updateBudgetDisplay();
}


