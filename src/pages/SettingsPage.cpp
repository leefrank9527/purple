#include "SettingsPage.h"

#include <QCheckBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>

SettingsPage::SettingsPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(18);

    auto *title = new QLabel("Settings", this);
    title->setStyleSheet("font-size: 34px; font-weight: 700; color: #24163e;");

    auto *panel = new QGroupBox("Preferences", this);
    panel->setStyleSheet(
        "QGroupBox { background: white; border-radius: 18px; border: 1px solid #e8e0f5; "
        "margin-top: 18px; padding: 16px; color: #24163e; font-weight: 600; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 18px; padding: 0 6px; }");

    auto *form = new QFormLayout(panel);
    form->setSpacing(14);

    auto *optionOne = new QCheckBox("Enable compact sidebar spacing", panel);
    auto *optionTwo = new QCheckBox("Use animated view transitions", panel);
    auto *optionThree = new QCheckBox("Show status updates when switching pages", panel);

    form->addRow(optionOne);
    form->addRow(optionTwo);
    form->addRow(optionThree);

    layout->addWidget(title);
    layout->addWidget(panel);
    layout->addStretch(1);
}