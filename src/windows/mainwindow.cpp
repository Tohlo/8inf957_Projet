#include "inc/windows/mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/map/map.h"

#include <QSettings>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	srand(time(0));
	this->setAttribute(Qt::WA_QuitOnClose);

	ui->setupUi(this);
	ui->stackedWidget->setCurrentWidget(ui->homepage);

	ui->mapTableWidget->setMouseTracking(true);
	ui->mapTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->mapTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	loadAttackLists();

	readSettings();
	createMissingDir();

	loadTypeMob();
}

MainWindow::~MainWindow()
{
	delete ui;
	delete mob;
}

/** Settings **/
void MainWindow::readSettings()
{
	QSettings settings("../Projet_POO/settings.ini", QSettings::IniFormat);

	settings.beginGroup("data");
	dataPath = settings.value("dataPath", "D:/Projets/data").toString();
	settings.endGroup();
}

void MainWindow::writeSettings()
{
	QSettings settings("../Projet_POO/settings.ini", QSettings::IniFormat);

	settings.beginGroup("data");
	settings.setValue("dataPath", dataPath);
	settings.endGroup();
}
/** Fin settings **/

/** Répertoires **/
void MainWindow::createMissingDir()
{
	QDir dir(dataPath);
	if (!dir.exists()) {
		dir.mkdir(".");
	}

	dir = QDir(dataPath + "/attacks");
	if (!dir.exists()) {
		dir.mkdir(".");
	}

	dir = QDir(dataPath + "/mobs");
	if (!dir.exists()) {
		dir.mkdir(".");
	}

	dir = QDir(dataPath + "/groups");
	if (!dir.exists()) {
		dir.mkdir(".");
	}

	dir = QDir(dataPath + "/battles");
	if (!dir.exists()) {
		dir.mkdir(".");
	}
}

void MainWindow::createMissingMobDir(QString type)
{
	QDir dir(dataPath + "/mobs/" + type);
	if (!dir.exists()) {
		dir.mkdir(".");
	}
}
/** Fin répertoires **/

/** Accesseurs **/
QString MainWindow::getDataPath() const
{
	return dataPath;
}

void MainWindow::setDataPath(const QString &value)
{
	dataPath = value;
}
/** Fin accesseurs **/

void MainWindow::on_lengthSpin_valueChanged(int arg1)
{
	ui->mapTableWidget->setColumnCount(arg1);
}

void MainWindow::on_widthSpin_valueChanged(int arg1)
{
	ui->mapTableWidget->setRowCount(arg1);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	writeSettings();
	event->accept();
}
