#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;

public slots:
    void getJPG();
    void fakeStream();

signals:


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
