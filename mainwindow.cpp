#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString baseKey = QString("abcdefghijklmnopqrstuvwxyz");
const QString cryptoKey = QString("introuvableszyxwqpmkjhgfdc");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::exploreFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exploreFile()
{
    QList<QString> s_a_secretWords = {};

    filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                            "/",
                                            tr("Images (*.txt)"));

    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        QString s_currentLine;
        QString s_tmpWord = "";

        while (!stream.atEnd()){
            s_currentLine = stream.readLine();

            if(s_currentLine.length() == 0)
            {
                s_a_secretWords.append(s_tmpWord);
                s_tmpWord = "";
            }
            else
            {
                s_tmpWord.append(s_currentLine.at(0).toLower());
            }
        }
        if(s_tmpWord.length() > 0) s_tmpWord.append(s_currentLine.at(0).toLower());
    }
    file.close();

    foreach(const QString s_secretWord, s_a_secretWords)
    {
        ui->textBrowser->append(findWord(s_secretWord));
    }
}

QString MainWindow::findWord(const QString &s_secretWord)
{
    QString s_finalWord = "";

    for(short i = 0; i < s_secretWord.length(); i++)
    {
        for(char c = 0; c < cryptoKey.length(); c++)
        {
            if(s_secretWord.at(i) == cryptoKey.at(c))
            {
                s_finalWord.append(baseKey.at(c));
                break;
            }
        }
    }

    return s_finalWord;
}
