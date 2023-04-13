#include "mainwindow.h"
#include "llse.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButtonInserirInicio_clicked()
{
    try {
       int valor;
       valor = ui->lineEditValor->text().toInt();
       if(!valor) throw QString("VALOR INVALIDO");
       lista.inserirInicio(valor);
       ui->lineEditValor->clear();
       ui->textEditDadosLista->setText(lista.obterDadosLista());
       int elementos;
       elementos = lista.getQuantidadeElementos();
       ui->lineEditQuantidadeElementos->setText(QString::number(elementos));
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}
void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try {
        int numero = lista.acessarInicio();
        QString valor = QString::number(numero);
        ui->lineEditValor->setText(valor);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}
void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try {
            lista.retirarInicio();
            ui->textEditDadosLista->setText(lista.obterDadosLista());
            int elementos;
            elementos = lista.getQuantidadeElementos();
            ui->lineEditQuantidadeElementos->setText(QString::number(elementos));
        } catch (QString &erro) {
            QMessageBox::information(this, "ERRO DO SISTEMA", erro);
        }
}


void MainWindow::on_pushButtonInserirFinal_clicked()
{
    try {
       int valor;
       valor = ui->lineEditValor->text().toInt();
       if(!valor) throw QString("VALOR INVALIDO");
       lista.inserirFim(valor);
       ui->lineEditValor->clear();
       ui->textEditDadosLista->setText(lista.obterDadosLista());
       int elementos;
       elementos = lista.getQuantidadeElementos();
       ui->lineEditQuantidadeElementos->setText(QString::number(elementos));
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonAcessarFinal_clicked()
{
    try {
        int numero = lista.acessarFim();
        QString valor = QString::number(numero);
        ui->lineEditValor->setText(valor);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonRetirarFinal_clicked()
{
    try {
            lista.retirarFim();
            ui->textEditDadosLista->setText(lista.obterDadosLista());
            int elementos;
            elementos = lista.getQuantidadeElementos();
            ui->lineEditQuantidadeElementos->setText(QString::number(elementos));
        } catch (QString &erro) {
            QMessageBox::information(this, "ERRO DO SISTEMA", erro);
        }
}


void MainWindow::on_pushButtonAcessarPOsicao_clicked()
{
    try {
        QString saida = ui->lineEditAcessarPosicao->text();
        bool teste;
        int posicao = saida.toInt(&teste);
        if(teste)
        {
            posicao = lista.acessarPosicao(posicao);
            ui->lineEditValor->setText(QString::number(posicao));
        }else{
        throw QString("POSICAO OU VALOR INVALIDO");
        }

    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonInserirPosicao_clicked()
{
    try {
        QString saida = ui->lineEditAcessarPosicao->text();
        bool teste;
        int posicao = saida.toInt(&teste);
        int valor = ui->lineEditValor->text().toInt();
        if(!valor) throw QString("VALOR INVALIDO");
        if(teste)
        {
            lista.inserirPosicao(valor, posicao);
            ui->lineEditValor->clear();
            ui->textEditDadosLista->setText(lista.obterDadosLista());
            ui->lineEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
            ui->lineEditValor->clear();
        }else{
        throw QString("POSICAO INVALIDA");
        }

    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonRetirarPosicao_clicked()
{
    try {
        QString saida = ui->lineEditAcessarPosicao->text();
        bool teste;
        int posicao = saida.toInt(&teste);
        if(teste)
        {
            QString a = QString::number(lista.retirarPosicao(posicao));
            ui->lineEditValor->setText(a);
            ui->textEditDadosLista->setText(lista.obterDadosLista());
            ui->lineEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
        }else{
            throw QString("POSICAO INVALIDA");
        }

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}
