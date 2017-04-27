#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _translate.insert(std::make_pair("Phone Number", "PHONE_NUMBER"));
    _translate.insert(std::make_pair("Email Address", "EMAIL_ADDRESS"));
    _translate.insert(std::make_pair("IP Address", "IP_ADDRESS"));
    ui->setupUi(this);
    setUpView();
}

void    MainWindow::setUpView()
{
    QStringList listObject;

    listObject << "Phone Number" << "Email Address" << "IP Address";
    ui->listWidget->addItems(listObject);
    ui->fileSelector->setIcon(QIcon("/home/wurmel/cpp_plazza/open.png"));
    ui->fileSelector->setIconSize(QSize(32, 32));
    ui->fileSelector->setText("");
    ui->fileSelector->setGeometry(ui->fileSelector->geometry().x(), ui->fileSelector->geometry().y(), 40, 40);
    connect(ui->fileSelector, SIGNAL(pressed()), this, SLOT(openFilePath()));
    connect(ui->runButton, SIGNAL(pressed()), this, SLOT(runCommand()));
}

void    MainWindow::openFilePath()
{
    _fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/");
}

void    MainWindow::runCommand()
{
    if ((_fileNames.count() == 0 || ui->listWidget->currentItem() == NULL) &&
         ui->plainTextEdit->toPlainText().size() == 0)
    {
        QMessageBox msgBox;

        msgBox.setText("You need to select one type and a file or give your command in the dedicated area.");
        msgBox.setWindowTitle("Error.");
        msgBox.exec();
    }
    else if (_fileNames.count())
    {
        QStringList::iterator   it;

        it = _fileNames.begin();
        while (it != _fileNames.end())
        {
            std::cout << (*it).toStdString() << " ";
            ++it;
        }
        std::string type = ui->listWidget->currentItem()->text().toStdString();
        if (_translate.find(type) != _translate.end())
        {
            std::cout << _translate[type] << std::endl;
        }
    }
    else
    {
        std::cout << ui->plainTextEdit->toPlainText().toStdString() << std::endl;
    }
    ui->plainTextEdit->clear();
    _fileNames.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}
