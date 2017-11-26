#include <QTableWidgetItem>
#include <QFileDialog>
#include <QJsonDocument>

#include "inc/windows/groupForm.h"
#include "ui_groupForm.h"
#include "inc/map/group.h"

GroupForm::GroupForm(MainWindow *parent) :
	QDialog(parent),
	ui(new Ui::GroupForm), color(QBrush())
{
	ui->setupUi(this);

	ui->groupTableWidget->setColumnCount(ui->lengthSpin->minimum());
	ui->groupTableWidget->setRowCount(ui->widthSpin->minimum());
	ui->groupTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->groupTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui->groupTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	initializeItems();
}

GroupForm::~GroupForm()
{
	delete ui;
}

void GroupForm::initializeItems()
{
	ui->groupTableWidget->clear();

	for (int i = 0; i <  ui->groupTableWidget->rowCount(); ++i) {
		for (int j = 0; j < ui->groupTableWidget->columnCount(); ++j) {
			if (ui->groupTableWidget->item(i, j) == nullptr) {
				ui->groupTableWidget->setItem(i, j, new QTableWidgetItem);
			}
		}
	}
}

void GroupForm::on_saveButton_clicked()
{
	MainWindow *mainWindow = (MainWindow *) this->parent();
	QFile file(QFileDialog::getSaveFileName(this, "Sauvegarder le groupe", mainWindow->getDataPath() + "/groups/Nouveau groupe", "Fichier JSON (*.json)"));

	if (!file.fileName().isEmpty()) {
		Group *group = new Group();

		std::vector<Cell *> cells;
		for (int i = 0; i <  ui->groupTableWidget->rowCount(); ++i) {
			for (int j = 0; j < ui->groupTableWidget->columnCount(); ++j) {
				if (ui->groupTableWidget->item(i, j)->background() == Qt::black) {
					Cell *cell = new Cell(i, j);
					cell->setColor(Qt::black);
					cell->setBlockViewLine(true);
					cell->setIsWalkable(false);

					cells.push_back(cell);
				}
				else if (ui->groupTableWidget->item(i, j)->background() == Qt::blue) {
					Cell *cell = new Cell(i, j);
					cell->setColor(Qt::blue);
					cell->setBlockViewLine(false);
					cell->setIsWalkable(false);

					cells.push_back(cell);
				}
			}
		}
		group->setCellVector(cells);

		group->toOrigin();

		/** Sérialisation **/
		file.open(QIODevice::WriteOnly | QIODevice::Truncate);

		QJsonObject groupObject;
		group->write(groupObject);

		QJsonDocument saveDoc(groupObject);
		file.write(saveDoc.toJson());

		file.close();
		/** Fin sérialisation **/

		delete group;

		this->close();
		/** Fin sérialisation **/
	}
}

void GroupForm::on_lengthSpin_valueChanged(int arg1)
{
	ui->groupTableWidget->setColumnCount(arg1);
	initializeItems();
}

void GroupForm::on_widthSpin_valueChanged(int arg1)
{
	ui->groupTableWidget->setRowCount(arg1);
	initializeItems();
}

void GroupForm::on_headerCheckBox_clicked()
{
	ui->groupTableWidget->horizontalHeader()->setVisible(ui->headerCheckBox->isChecked());
	ui->groupTableWidget->verticalHeader()->setVisible(ui->headerCheckBox->isChecked());
}

void GroupForm::changeColor() {
	if (ui->hinderViewLineCheckBox->isChecked()) {
		color = Qt::black;
	}
	else if (ui->hinderMoveCheckBox->isChecked()) {
		color = Qt::blue;
	}
	else {
		color = QBrush();
	}
}

void GroupForm::on_hinderMoveCheckBox_clicked()
{
	if (!ui->hinderMoveCheckBox->isChecked() && ui->hinderViewLineCheckBox->isChecked()) {
		ui->hinderViewLineCheckBox->setChecked(false);
	}

	changeColor();
}

void GroupForm::on_hinderViewLineCheckBox_clicked()
{
	if (ui->hinderViewLineCheckBox->isChecked() && !ui->hinderMoveCheckBox->isChecked()) {
		ui->hinderMoveCheckBox->setChecked(true);
	}

	changeColor();
}

void GroupForm::on_groupTableWidget_cellClicked(int row, int column)
{
	if (ui->groupTableWidget->item(row, column)->background() == QBrush() || ui->groupTableWidget->item(row, column)->background() != color) {
		ui->groupTableWidget->item(row, column)->setBackground(color);
	}
	else {
		ui->groupTableWidget->item(row, column)->setBackground(QBrush());
	}
}
