#pragma once

#include <QMainWindow>

class QListWidget;
class QStackedWidget;

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupNavigation();
    void setupPages();
    void applyStyleSheet();

    QListWidget *navigationList_ = nullptr;
    QStackedWidget *contentStack_ = nullptr;
};