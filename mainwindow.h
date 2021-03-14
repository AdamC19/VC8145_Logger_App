#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vc8145.h"

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
    void on_comportComboBox_activated(const QString &arg1);

    void on_comportComboBox_highlighted(const QString &arg1);

    void on_comportComboBox_currentTextChanged(const QString &arg1);

    void on_connectButton_clicked();

private:
    Ui::MainWindow *ui;
    VC8145 *meter;
    QTimer *updateMeterTimer;
};
#endif // MAINWINDOW_H
