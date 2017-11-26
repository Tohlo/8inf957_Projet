#ifndef GROUPFORM_H
#define GROUPFORM_H

#include <QDialog>

#include "inc/windows/mainwindow.h"

namespace Ui {
class GroupForm;
}

class GroupForm : public QDialog
{
		Q_OBJECT

	public:
		explicit GroupForm(MainWindow *parent = 0);
		~GroupForm();

		void initializeItems();

		void changeColor();

	private slots:
		void on_saveButton_clicked();

		void on_lengthSpin_valueChanged(int arg1);

		void on_widthSpin_valueChanged(int arg1);

		void on_headerCheckBox_clicked();

		void on_hinderMoveCheckBox_clicked();

		void on_hinderViewLineCheckBox_clicked();

		void on_groupTableWidget_cellClicked(int row, int column);

		void on_quitButton_clicked();

	private:
		Ui::GroupForm *ui;
		QBrush color;
};

#endif // GROUPFORM_H
