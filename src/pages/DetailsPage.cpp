#include "DetailsPage.h"

#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>

DetailsPage::DetailsPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(18);

    auto *title = new QLabel("Details", this);
    title->setStyleSheet("font-size: 34px; font-weight: 700; color: #24163e;");

    auto *panel = new QGroupBox("Application Details", this);
    panel->setStyleSheet(
        "QGroupBox { background: white; border-radius: 18px; border: 1px solid #e8e0f5; "
        "margin-top: 18px; padding: 16px; color: #24163e; font-weight: 600; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 18px; padding: 0 6px; }");

    auto *panelLayout = new QVBoxLayout(panel);
    panelLayout->setSpacing(12);

    auto *lineOne = new QLabel("Qt Widgets gives you a native desktop look and feel.", panel);
    auto *lineTwo = new QLabel("QStackedWidget keeps the content switching logic simple.", panel);
    auto *lineThree = new QLabel("CMake and CPack make builds and packages portable across platforms.", panel);

    for (QLabel *label : {lineOne, lineTwo, lineThree}) {
        label->setWordWrap(true);
        label->setStyleSheet("font-size: 16px; color: #4a3d69;");
        panelLayout->addWidget(label);
    }

    layout->addWidget(title);
    layout->addWidget(panel);
    layout->addStretch(1);
}