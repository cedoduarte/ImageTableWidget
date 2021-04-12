#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList filenames {
        ":/Chrysanthemum.jpg",
        ":/Desert.jpg",
        ":/Hydrangeas.jpg",
        ":/Jellyfish.jpg",
        ":/Koala.jpg",
        ":/Lighthouse.jpg",
        ":/Tulips.jpg"
    };

    std::for_each(filenames.begin(), filenames.end(), [&](const QString &filename)
    {
        addImage(filename);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Abrir", "/", "Any file (*.*)");
    if (filename.isEmpty())
    {
        return;
    }
    addImage(filename);
}

void MainWindow::on_remove_pushButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void MainWindow::addImage(const QString &filename)
{
    QFileInfo finfo(filename);
    QPixmap pixmap(filename);
    QString nombre = finfo.fileName();
    const int ancho = pixmap.width();
    const int alto = pixmap.height();
    QDateTime fecha = finfo.birthTime();

    const int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, Nombre, new QTableWidgetItem(nombre));
    ui->tableWidget->setItem(row, Ancho, new QTableWidgetItem(QString::number(ancho)));
    ui->tableWidget->setItem(row, Alto, new QTableWidgetItem(QString::number(alto)));
    ui->tableWidget->setItem(row, Fecha, new QTableWidgetItem(fecha.toString("hh:mm:ss, dd/MM/yyyy")));

    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap);
    ui->tableWidget->setCellWidget(row, Imagen, label);
}
