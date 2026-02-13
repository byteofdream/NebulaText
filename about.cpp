#include "about.h"

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("About NebulaText");
    setFixedSize(300, 200);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(15);

    auto *label = new QLabel("NebulaText\nVersion 1.0\n\nCreated by You", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    auto *buttonLayout = new QHBoxLayout();  // для выравнивания по центру
    QPushButton *okButton = new QPushButton("OK", this);
    okButton->setFixedSize(80, 30);
    okButton->setCursor(Qt::PointingHandCursor);
    
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);

    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addStretch();

    layout->addLayout(buttonLayout);
}
