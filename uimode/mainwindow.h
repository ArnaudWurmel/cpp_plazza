#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <string>
#include <utility>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void    setUpView();

private slots:
  void  openFilePath();
  void  runCommand();

private:
  QStringList   _fileNames;
  std::map<std::string, std::string>    _translate;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
