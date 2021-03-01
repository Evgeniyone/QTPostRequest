#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <postrequest.h>

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
    void slotGo();
    void slotDone(QString &);

private:
    Ui::MainWindow *ui;
    PostRequest *request;
};
#endif // MAINWINDOW_H
