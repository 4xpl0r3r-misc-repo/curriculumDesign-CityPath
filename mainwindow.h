#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsEllipseItem>
#include <vector>
#include <data.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_minPath_pushButton_clicked();
    void on_minTree_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

};

#endif // MAINWINDOW_H
