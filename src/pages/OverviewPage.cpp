#include "OverviewPage.h"

#include <QLabel>
#include <QVBoxLayout>

OverviewPage::OverviewPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(18);

    auto *title = new QLabel("Overview", this);
    title->setObjectName("pageTitle");
    title->setStyleSheet("font-size: 34px; font-weight: 700; color: #24163e;");

    auto *description = new QLabel(
        "This Qt Widgets shell demonstrates a left navigation menu that switches between stacked views.",
        this);
    description->setWordWrap(true);
    description->setStyleSheet("font-size: 18px; color: #564874; line-height: 1.5;");

    auto *card = new QLabel(
        "Use the navigation items on the left to move between the overview, details, and settings pages.",
        this);
    card->setWordWrap(true);
    card->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    card->setStyleSheet(
        "background: white; border-radius: 18px; padding: 22px; color: #3a3154; "
        "font-size: 16px; border: 1px solid #e8e0f5;");

    layout->addWidget(title);
    layout->addWidget(description);
    layout->addWidget(card);
    layout->addStretch(1);
}