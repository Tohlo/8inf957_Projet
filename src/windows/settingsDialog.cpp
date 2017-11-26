#include "inc/windows/settingsDialog.h"
#include "ui_settingsDialog.h"

#include <QFileDialog>

SettingsDialog::SettingsDialog(MainWindow *parent) :
	QDialog(parent),
	ui(new Ui::SettingsDialog)
{
	ui->setupUi(this);

	ui->dataLineEdit->setText(parent->getDataPath());
}

SettingsDialog::~SettingsDialog()
{
	delete ui;
}

void SettingsDialog::on_buttonBox_accepted()
{
	MainWindow *mainWindow = (MainWindow *) parent();

	mainWindow->setDataPath(ui->dataLineEdit->text());
	mainWindow->createMissingDir();
}

void SettingsDialog::on_dataButton_clicked()
{
	MainWindow *mainWindow = (MainWindow *) parent();

	QString dir = QFileDialog::getExistingDirectory(this, "Choisir le répertoire des données",
		mainWindow->getDataPath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	if (!dir.isEmpty()) {
		ui->dataLineEdit->setText(dir);
	}
}
