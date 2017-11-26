#ifndef ATTACKFORM_H
#define ATTACKFORM_H

#include <QDialog>

#include "inc/mobs/attack.h"
#include "mainwindow.h"

namespace Ui {
class AttackForm;
}

class AttackForm : public QDialog
{
		Q_OBJECT

	public:
		explicit AttackForm(MainWindow *parent = 0, Attack *attack = nullptr);
		~AttackForm();

	private slots:
		void on_cancelButton_clicked();

		void on_saveButton_clicked();

		void on_poAttackSpinMin_valueChanged(int arg1);

		void on_poAttackSpinMax_valueChanged(int arg1);

		void on_damagesSpinMin_valueChanged(int arg1);

		void on_damagesSpinMax_valueChanged(int arg1);

		void on_healSpinMin_valueChanged(int arg1);

		void on_healSpinMax_valueChanged(int arg1);

	private:
		Ui::AttackForm *ui;
};

#endif // ATTACKFORM_H
