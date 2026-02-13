#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    setWindowTitle("NebulaText");
    resize(800, 600);

    setupMenu();
}

MainWindow::~MainWindow() {}

void MainWindow::setupMenu() {
    QMenu *fileMenu = menuBar()->addMenu("&File");

    QAction *openAction = new QAction("&Open", this);
    QAction *saveAction = new QAction("&Save", this);
    QAction *aboutAction = new QAction("&About", this);
    QAction *exitAction = new QAction("&Exit", this);

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
        
    fileMenu->addSeparator();
    fileMenu->addAction(aboutAction);
    connect(aboutAction, &QAction::triggered, this, [=]() {
            AboutDialog about(this);
            about.exec();
    });

    connect(openAction, &QAction::triggered, this, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "Open File");
        if (!path.isEmpty()) {
            QFile file(path);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                textEdit->setText(file.readAll());
            }
        }
    });

    connect(saveAction, &QAction::triggered, this, [=]() {
        QString path = QFileDialog::getSaveFileName(this, "Save File");
        if (!path.isEmpty()) {
            QFile file(path);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << textEdit->toPlainText();
            }
        }
    });

    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);
}
