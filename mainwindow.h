#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "llse.h"
#include <QMainWindow>
#include <QMessageBox>
#include <no.h>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonInserirFinal_clicked();

    void on_pushButtonAcessarFinal_clicked();

    void on_pushButtonRetirarFinal_clicked();

    void on_pushButtonAcessarPOsicao_clicked();

    void on_pushButtonInserirPosicao_clicked();

    void on_pushButtonRetirarPosicao_clicked();

private:
    ped::LLSE lista;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
