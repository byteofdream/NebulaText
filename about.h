#pragma once

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class AboutDialog : public QDialog {
    Q_OBJECT

public:
    AboutDialog(QWidget *parent = nullptr);
};
