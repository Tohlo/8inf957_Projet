#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "inc/windows/mainwindow.h"

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit SettingsDialog(MainWindow *parent = 0);
		~SettingsDialog();

	private slots:
		void on_buttonBox_accepted();

		void on_dataButton_clicked();

	private:
		Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
