#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent_ = 0);
	virtual ~MainWindow() = default;

signals:

public slots:
};
