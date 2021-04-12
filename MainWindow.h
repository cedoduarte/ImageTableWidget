#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum ColumnName
{
    Nombre,
    Ancho,
    Alto,
    Fecha,
    Imagen
};

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_add_pushButton_clicked();
    void on_remove_pushButton_clicked();
private:
    void addImage(const QString &filename);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
