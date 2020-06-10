#include "stdpfx.h"
#include "mainwindow.h"
#include "myFunc.h"
#include "data.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->scene = new QGraphicsScene;
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    ui->graphicsView->setScene(this->scene); //视图关联场景
    Data myData = Data();
    drawGV(this->scene, myData);
    ui->graphicsView->show(); //显示视图
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_minPath_pushButton_clicked()
{ //最短路径算法操作
    QLabel *resLabel = ui->minPathRes;
    QGraphicsView *GV = ui->graphicsView;
    Data myData = Data();
    QString res = QString::number(minPathMain(this->scene, myData, string2enum(ui->minPathOrigin->currentText()), string2enum(ui->minPathDestination->currentText())));
    GV->show(); //显示视图
    resLabel->setText(res + "分钟");
}

void MainWindow::on_minTree_pushButton_clicked()
{ //最小生成树算法操作
    QLabel *resLabel = ui->minTreeRes;
    QGraphicsView *GV = ui->graphicsView;
    Data myData = Data();
    bool selectedCitys[citySum];
    std::memset(selectedCitys, 0, sizeof(selectedCitys));
    geneSelectedCitys(this->ui, selectedCitys);
    int resNum = minTreeMain(this->scene, myData, selectedCitys);
    QString res;
    if (resNum == -1)
    {
        res = "无法生成";
    }
    else
    {
        res = QString::number(resNum) + "分钟";
    }
    GV->show(); //显示视图
    resLabel->setText(res);
}
