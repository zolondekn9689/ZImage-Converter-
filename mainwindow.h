#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QPixelFormat>
#include <QDirIterator>
#include <QImageReader>
#include "prefdialog.h"
#include <QRadioButton>
#include <QThread>
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
    void on_FileBtn_clicked();

    void on_directoryBtn_clicked();

    void on_ConvertBtn_clicked();

    void on_actionPreferences_triggered();

private:
    Ui::MainWindow *ui;
    void Convert(QString oldFileName);
    void ResetRadioButtons();



    QString directory;

    // To be set up in a later date.
    QString outputDirectory;
    QList<QThread*> threads;

};
#endif // MAINWINDOW_H
