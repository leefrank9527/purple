#include "MainWindow.h"

#include "pages/DetailsPage.h"
#include "pages/OverviewPage.h"
#include "pages/SettingsPage.h"

#include <QDockWidget>
#include <QFrame>
#include <QHBoxLayout>
#include <QListWidget>
#include <QStackedWidget>
#include <QStatusBar>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("PurpleNavigator");
    resize(1200, 760);

    auto *centralFrame = new QFrame(this);
    centralFrame->setObjectName("centralFrame");
    auto *rootLayout = new QHBoxLayout(centralFrame);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    auto *navigationFrame = new QFrame(centralFrame);
    navigationFrame->setObjectName("navigationFrame");
    navigationFrame->setFixedWidth(240);
    auto *navigationLayout = new QVBoxLayout(navigationFrame);
    navigationLayout->setContentsMargins(16, 16, 16, 16);
    navigationLayout->setSpacing(12);

    navigationList_ = new QListWidget(navigationFrame);
    navigationList_->setObjectName("navigationList");
    navigationList_->setSpacing(6);
    navigationList_->setFocusPolicy(Qt::NoFocus);
    navigationList_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    navigationList_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    navigationList_->addItem("Overview");
    navigationList_->addItem("Details");
    navigationList_->addItem("Settings");

    navigationLayout->addWidget(navigationList_);
    navigationLayout->addStretch(1);

    contentStack_ = new QStackedWidget(centralFrame);
    contentStack_->setObjectName("contentStack");
    contentStack_->addWidget(new OverviewPage(contentStack_));
    contentStack_->addWidget(new DetailsPage(contentStack_));
    contentStack_->addWidget(new SettingsPage(contentStack_));

    rootLayout->addWidget(navigationFrame);
    rootLayout->addWidget(contentStack_, 1);

    setCentralWidget(centralFrame);
    statusBar()->showMessage("Ready");

    setupNavigation();
    setupPages();
    applyStyleSheet();

    navigationList_->setCurrentRow(0);
    contentStack_->setCurrentIndex(0);
}

void MainWindow::setupNavigation()
{
    connect(navigationList_, &QListWidget::currentRowChanged, contentStack_, &QStackedWidget::setCurrentIndex);
    connect(navigationList_, &QListWidget::currentRowChanged, this, [this](int row) {
        static const char *titles[] = {"Overview", "Details", "Settings"};
        if (row >= 0 && row < 3) {
            statusBar()->showMessage(QString("Viewing %1").arg(titles[row]));
        }
    });
}

void MainWindow::setupPages()
{
    contentStack_->setCurrentIndex(0);
}

void MainWindow::applyStyleSheet()
{
    setStyleSheet(R"(
        QMainWindow {
            background: #f4f1fb;
        }

        QFrame#navigationFrame {
            background: #1f1533;
        }

        QListWidget#navigationList {
            background: transparent;
            color: #f4eefc;
            border: none;
            outline: none;
            font-size: 16px;
            font-weight: 600;
        }

        QListWidget#navigationList::item {
            padding: 14px 16px;
            border-radius: 10px;
        }

        QListWidget#navigationList::item:hover {
            background: rgba(255, 255, 255, 0.08);
        }

        QListWidget#navigationList::item:selected {
            background: #7f5af0;
            color: white;
        }

        QStackedWidget#contentStack {
            background: transparent;
        }
    )");
}