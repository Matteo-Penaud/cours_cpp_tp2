#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void exploreFile(void);

private:
    const QString s_baseKey = QString("abcdefghijklmnopqrstuvwxyz");
    const QString s_cryptoKey = QString("introuvableszyxwqpmkjhgfdc");

    Ui::MainWindow *ui;

    QString s_filePath;

    QString findWord(const QString &s_secretWord);
};
#endif // MAINWINDOW_H
