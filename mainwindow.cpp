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
        int posicao = ui->lineEditAcessarPosicao->text().toInt();
        int saida;
        if(posicao == 0)
        {
            saida = lista.acessarInicio();
            ui->lineEditValor->setText(QString::number(saida));
        }else{
        if(!posicao) throw QString("POSICAO INVALIDA");
            posicao = lista.acessarPosicao(posicao);
            ui->lineEditValor->setText(QString::number(posicao));
        }
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }

}


void MainWindow::on_pushButtonInserirPosicao_clicked()
{
    try {
        int posicao = ui->lineEditAcessarPosicao->text().toInt();
        int valor = ui->lineEditValor->text().toInt();
        if(posicao == 0)
        {
            lista.inserirPosicao(valor, 0);
            ui->lineEditValor->clear();
            ui->textEditDadosLista->setText(lista.obterDadosLista());
            ui->lineEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
            ui->lineEditValor->clear();
        }else{
        if(!valor || !posicao) throw QString("POSICAO OU VALOR INVALIDO");
            lista.inserirPosicao(valor, posicao);
            ui->lineEditValor->clear();
            ui->textEditDadosLista->setText(lista.obterDadosLista());
            ui->lineEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
            ui->lineEditValor->clear();
        }

    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonRetirarPosicao_clicked()
{

    try {
        int posicao = ui->lineEditAcessarPosicao->text().toInt();
        if(lista.estaVazia()) throw QString("A lista já esta vazia!");
        if(posicao == 0)
        {
            QString saida = QString::number(lista.retirarPosicao(0));
            ui->lineEditValor->setText(saida);
            ui->textEditDadosLista->setText(lista.obterDadosLista());
            ui->lineEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
        }else{
        if(!posicao) throw QString("VALOR INVALIDO");
        QString saida = QString::number(lista.retirarPosicao(posicao));
        ui->lineEditValor->setText(saida);
        ui->textEditDadosLista->setText(lista.obterDadosLista());
        ui->lineEditQuantidadeElementos->setText(QString::number(lista.getQuantidadeElementos()));
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}

