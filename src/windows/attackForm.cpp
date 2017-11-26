#include <QFileDialog>
#include <QJsonDocument>

#include "inc/windows/attackForm.h"
#include "inc/data/data.h"
#include "ui_attackForm.h"

AttackForm::AttackForm(MainWindow *parent, Attack *attack) :
	QDialog(parent),
	ui(new Ui::AttackForm)
{
	ui->setupUi(this);

	if (attack != nullptr) {
		ui->attackNameLineEdit->setText(attack->getName());
		ui->paCostSpin->setValue(attack->getPA());
		ui->pmCostSpin->setValue(attack->getPM());
		ui->pcCostSpin->setValue(attack->getPC());
		ui->poAttackSpinMin->setValue(attack->getPOMin());
		ui->poAttackSpinMax->setValue(attack->getPOMax());
		ui->viewLineCheckBox->setChecked(attack->getViewLine());
		ui->typeAreaFormComboBox->setCurrentIndex(static_cast<int>(attack->getTypeArea()->getForm()));
		ui->typeAreaSizeSpin->setValue(attack->getTypeArea()->getSize());
		ui->typeLaunchComboBox->setCurrentIndex(static_cast<int>(attack->getTypeLaunch()));
		ui->elementComboBox->setCurrentIndex(static_cast<int>(attack->getElement()));
		ui->damagesSpinMin->setValue(attack->getDamageMin());
		ui->damagesSpinMax->setValue(attack->getDamageMax());
		ui->healSpinMin->setValue(attack->getHealMin());
		ui->healSpinMax->setValue(attack->getHealMax());
	}

	for (Element::Enum element : Element::getElements()) {
		ui->elementComboBox->addItem(Element::toQString(element));
	}

	for (Form::Enum form : Form::getForms()) {
		ui->typeAreaFormComboBox->addItem(Form::toQString(form));
	}

	for (TypeLaunch::Enum typeLaunch : TypeLaunch::getTypesLaunches()) {
		ui->typeLaunchComboBox->addItem(TypeLaunch::toQString(typeLaunch));
	}
}

AttackForm::~AttackForm()
{
	delete ui;
}

void AttackForm::on_cancelButton_clicked()
{
	MainWindow *mainWindow = (MainWindow *) this->parent();
	mainWindow->loadAttackLists();

	this->close();
}

void AttackForm::on_saveButton_clicked()
{
	MainWindow *mainWindow = (MainWindow *) this->parent();
	QFile file(QFileDialog::getSaveFileName(this, "Sauvegarder l'attaque", mainWindow->getDataPath() + "/attacks/" + ui->attackNameLineEdit->text(), "Fichier JSON (*.json)"));

	if (!file.fileName().isEmpty()) {
		/** Création attaque **/
		Attack *attack = new Attack();
		attack->setName(ui->attackNameLineEdit->text());
		attack->setPA(ui->paCostSpin->value());
		attack->setPM(ui->pmCostSpin->value());
		attack->setPC(ui->pcCostSpin->value());
		attack->setPOMin(ui->poAttackSpinMin->value());
		attack->setPOMax(ui->poAttackSpinMax->value());
		attack->setViewLine(ui->viewLineCheckBox->isChecked());
		attack->setTypeArea(
					new TypeArea(
						static_cast<Form::Enum>(ui->typeAreaFormComboBox->currentIndex()),
						ui->typeAreaSizeSpin->value()
						)
					);
		attack->setTypeLaunch(static_cast<TypeLaunch::Enum>(ui->typeLaunchComboBox->currentIndex()));
		attack->setElement(static_cast<Element::Enum>(ui->elementComboBox->currentIndex()));
		attack->setDamageMin(ui->damagesSpinMin->value());
		attack->setDamageMax(ui->damagesSpinMax->value());
		attack->setHealMin(ui->healSpinMin->value());
		attack->setHealMax(ui->healSpinMax->value());
		// Todo : ajouter buffs
		/** Fin création attaque **/

		/** Sérialisation **/
		file.open(QIODevice::WriteOnly | QIODevice::Truncate);

		QJsonObject attackObject;
		attack->write(attackObject);

		QJsonDocument saveDoc(attackObject);
		file.write(saveDoc.toJson());

		file.close();
		/** Fin sérialisation **/

		delete attack;

		mainWindow->loadAttackLists();

		this->close();
		/** Fin sérialisation **/
	}
}

void AttackForm::on_poAttackSpinMin_valueChanged(int arg1)
{
	ui->poAttackSpinMax->setValue(std::max(arg1, ui->poAttackSpinMax->value()));
}

void AttackForm::on_poAttackSpinMax_valueChanged(int arg1)
{
	ui->poAttackSpinMin->setValue(std::min(arg1, ui->poAttackSpinMin->value()));
}

void AttackForm::on_damagesSpinMin_valueChanged(int arg1)
{
	ui->damagesSpinMax->setValue(std::max(arg1, ui->damagesSpinMax->value()));
}

void AttackForm::on_damagesSpinMax_valueChanged(int arg1)
{
	ui->damagesSpinMin->setValue(std::min(arg1, ui->damagesSpinMin->value()));
}

void AttackForm::on_healSpinMin_valueChanged(int arg1)
{
	ui->healSpinMax->setValue(std::max(arg1, ui->healSpinMax->value()));
}

void AttackForm::on_healSpinMax_valueChanged(int arg1)
{
	ui->healSpinMin->setValue(std::min(arg1, ui->healSpinMin->value()));
}
