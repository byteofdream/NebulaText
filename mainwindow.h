#pragma once

#include <QMainWindow>
#include <QTextEdit>
#include "about.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTextEdit *textEdit;
    void setupMenu();
};
