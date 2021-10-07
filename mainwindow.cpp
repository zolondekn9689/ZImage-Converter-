#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ImageFactory/tifimage.h"
#include "ImageFactory/pngimage.h"
#include "ImageFactory/jpgimage.h"
#include "ImageFactory/Threads/jpgdirectorythread.h"
#include "ImageFactory/Threads/pngdirectorythread.h"
#include "ImageFactory/Threads/tifdirectorybuilder.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}




MainWindow::~MainWindow()
{
    for (int i = threads.length(); i >= 0; i--)
    {
        QThread* thread = threads.at(i);
        delete thread;
    }


    delete ui;
}




/**
 * @brief MainWindow::on_FileBtn_clicked
 */
void MainWindow::on_FileBtn_clicked()
{
   // Step 1: Extract the file path from user.
   QString filepath = QFileDialog::getOpenFileName(this, tr("Files"), "", "Images (*.tiff *.tif *.png *.jpg)");

   ui->textEdit_imagePath->setText(filepath);

   directory = QFileInfo(filepath).absolutePath();

   ui->textEdit_directory->setText(directory);

   ResetRadioButtons();

}



/**
 * @brief MainWindow::on_directoryBtn_clicked
 *
 */
void MainWindow::on_directoryBtn_clicked()
{

    // Check to see which folders should be done.
    if(ui->radioButton_JPG->isChecked())
    {
        JpgDirectoryThread* thread = new JpgDirectoryThread(ui->textEdit_directory->toPlainText());
        threads.append(thread);

        thread->start();


    }
    if (ui->radioButton_PNG->isChecked())
    {
        //std::unique_ptr<PngDirectoryThread> thread(new PngDirectoryThread(ui->textEdit_directory->toPlainText()));
        PngDirectoryThread* thread = new PngDirectoryThread(ui->textEdit_directory->toPlainText());
        threads.append(thread);

        thread->start();

    }
    if (ui->radioButton_TIF->isChecked())
    {
        TIFDirectoryBuilder* thread = new TIFDirectoryBuilder(ui->textEdit_directory->toPlainText());
        threads.append(thread);
        thread->start();
    }


}


void MainWindow::on_ConvertBtn_clicked()
{
    Convert(ui->textEdit_imagePath->toPlainText());
}


void MainWindow::Convert(QString oldFileName)
{



    // Check to see which folders should be done.
    if(ui->radioButton_JPG->isChecked())
    {
        JpgImage img;
        img.Build(oldFileName);
    }
    if (ui->radioButton_PNG->isChecked())
    {
        PngImage img;
        img.Build(oldFileName);

    }
    if (ui->radioButton_TIF->isChecked())
    {
        TifImage img;
        img.Build(oldFileName);
    }


    QMessageBox b;
    b.setText("Convertion completed!");
    b.exec();

}

void MainWindow::ResetRadioButtons()
{
    QFileInfo file(ui->textEdit_imagePath->toPlainText());
    ui->radioButton_JPG->setEnabled(true);
    ui->radioButton_PNG->setEnabled(true);
    ui->radioButton_TIF->setEnabled(true);

    QString suffix = file.suffix().toLower();
    if (suffix == "jpg" || suffix == "jpeg") {
        ui->radioButton_JPG->setEnabled(false);
    }

    if (suffix == "png") {
        ui->radioButton_PNG->setEnabled(false);
    }

    if (suffix == "tif" || suffix == "tiff") {
        ui->radioButton_TIF->setEnabled(false);
    }
}


void MainWindow::on_actionPreferences_triggered()
{
    PrefDialog d;

    QMessageBox b;
    int state = d.exec();

    // User pressed Okay - save changes.
    if (state == 1)
    {

    }


}

