#include "mainwindow.hpp"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent_) : QMainWindow(parent_)
{
	auto vl = new QVBoxLayout;



	auto* w = new QWidget;
	w->setLayout(vl);
	setCentralWidget(w);
}
