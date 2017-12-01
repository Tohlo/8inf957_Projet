#include "inc/windows/mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/windows/settingsDialog.h"
#include "inc/windows/attackForm.h"
#include "inc/windows/groupForm.h"
#include "xlsxdocument.h"

#include <QMessageBox>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QJsonDocument>

/** Reset **/
void MainWindow::reset()
{
	resetMobForm();
	resetMapEditor();
}

void MainWindow::resetMobForm() {
	delete mob;
	mob = nullptr;

	foreach (QLineEdit *widget, this->findChildren<QLineEdit *>()) {
		widget->clear();
	}

	foreach (QSpinBox *widget, this->findChildren<QSpinBox *>()) {
		widget->setValue(0);
	}

	loadAttackLists();
	loadTypeMob();
}

void MainWindow::resetMapEditor() {
	ui->mapTableWidget->clear();

	ui->mapTableWidget->setColumnCount(ui->lengthSpin->minimum());
	ui->mapTableWidget->setRowCount(ui->widthSpin->minimum());

	ui->widthSpin->setValue(ui->widthSpin->minimum());
	ui->lengthSpin->setValue(ui->lengthSpin->minimum());

	ui->exportButton->setEnabled(false);
}
/** Fin reset **/

/** Affichage **/
void MainWindow::displayAttackInformation(QString attackName)
{
	QFile file(dataPath + "/attacks/" + attackName + ".json");

	if (!file.fileName().isEmpty()) {
		file.open(QIODevice::ReadOnly);
		QByteArray savedAttack = file.readAll();
		QJsonDocument loadDoc(QJsonDocument::fromJson(savedAttack));

		Attack *attack = new Attack();
		attack->read(loadDoc.object());
		file.close();

		ui->attackNameValue->setText(attack->getName());
		ui->paCostValue->setText(QString::number(attack->getPA()));
		ui->pmCostValue->setText(QString::number(attack->getPM()));
		ui->pcCostValue->setText(QString::number(attack->getPC()));
		ui->poAttackValueMin->setText(QString::number(attack->getPOMin()));
		ui->poAttackValueMax->setText(QString::number(attack->getPOMax()));
		ui->viewLineValue->setChecked(attack->getViewLine());
		ui->typeAreaFormValue->setText(Form::toQString(attack->getTypeArea()->getForm()));
		ui->typeAreaSizeValue->setText(QString::number(attack->getTypeArea()->getSize()));
		ui->typeLaunchValue->setText(TypeLaunch::toQString(attack->getTypeLaunch()));
		ui->elementValue->setText(Element::toQString(attack->getElement()));
		ui->damagesValueMin->setText(QString::number(attack->getDamageMin()));
		ui->damagesValueMax->setText(QString::number(attack->getDamageMax()));
		ui->healValueMin->setText(QString::number(attack->getHealMin()));
		ui->healValueMax->setText(QString::number(attack->getHealMax()));

		delete attack;
	}
}
/** Fin affichage **/

/** Chargements informations **/
void MainWindow::loadAttackLists()
{
	ui->attacksLeftListWidget->clear();
	ui->attacksOwnedListWidget->clear();

	QDir attackDir(dataPath + "/attacks");
	QStringList attackFiles(attackDir.entryList(QDir::Files));

	for (int i = 0; i < attackFiles.size(); ++i) {
		attackFiles.replace(i, attackFiles[i].replace(".json", QString()));
	}

	ui->attacksLeftListWidget->addItems(attackFiles);

	if (mob != nullptr) {
		foreach (Attack *attack, mob->getAttacks()) {
			if (!attack->getName().isEmpty()) {
				auto items = ui->attacksLeftListWidget->findItems(attack->getName(), Qt::MatchFixedString);

				if (!items.empty()) {
					ui->attacksLeftListWidget->takeItem(ui->attacksLeftListWidget->row(items[0]));
				}

				ui->attacksOwnedListWidget->addItem(attack->getName());
			}
		}
	}
}

void MainWindow::loadTypeMob()
{
	ui->typeComboBox->clear();
	ui->monsterTypeBox->clear();

	QDir mobsDir(dataPath + "/mobs");
	QStringList typeDirs(mobsDir.entryList(QDir::NoDotAndDotDot | QDir::Dirs));

	ui->typeComboBox->addItems(typeDirs);
	ui->typeComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

	ui->monsterTypeBox->addItems(typeDirs);
	ui->monsterTypeBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
}
/** Fin chargements informations **/

/** Récupérateurs d'objets **/
std::vector<Group *> MainWindow::deserializeGroups(int length, int width)
{
	QDir groupDir(dataPath + "/groups");
	QStringList groupFiles(groupDir.entryList(QDir::Files));
	std::vector<Group *> groups;

	for(int i = 0; i < groupFiles.size(); ++i) {
		QFile file(dataPath + "/groups/" + groupFiles[i]);

		if (!file.fileName().isEmpty()) {
			file.open(QIODevice::ReadOnly);
			QByteArray savedGroup = file.readAll();
			QJsonDocument loadDoc(QJsonDocument::fromJson(savedGroup));

			Group *group = new Group();
			group->read(loadDoc.object());
			file.close();

			if (group->getLength() < length && group->getWidth() < width) {
				groups.push_back(group);
			}
		}
	}

	return groups;
}

std::vector<Mob *> MainWindow::deserializeMobs(QString type, int level)
{
	QDir mobDir(dataPath + "/mobs/" + type);
	QStringList mobsFiles(mobDir.entryList(QDir::Files));
	std::vector<Mob *> mobs;

	for(int i = 0; i < mobsFiles.size(); ++i) {
		QFile file(dataPath + "/mobs/"+ type +"/" + mobsFiles[i]);

		if (!file.fileName().isEmpty()) {
			file.open(QIODevice::ReadOnly);
			QByteArray savedMob = file.readAll();
			QJsonDocument loadDoc(QJsonDocument::fromJson(savedMob));

			Mob *mob = new Mob();
			mob->read(loadDoc.object());
			file.close();

			for (int i = mob->getMinSkills()->getLevel(); i <= mob->getMaxSkills()->getLevel(); ++i) {
				if (std::abs(level - i) <= 2) {
					mobs.push_back(mob);
					break;
				}
			}
		}
	}

	return mobs;
}
/** Fin récupérateurs d'objets **/

/** Confirmations de changements **/
void MainWindow::confirmHomepage() {
	ui->stackedWidget->setCurrentWidget(ui->homepage);

	reset();
}

void MainWindow::confirmCloseApplication() {
	close();
}
/** Fin confirmations de changements **/

/** Gestion des boutons **/
/** Changement de page **/
void MainWindow::on_bestiaryButton_clicked()
{
	reset();
	ui->stackedWidget->setCurrentWidget(ui->editpage);
	ui->bestiaryTabWidget->setCurrentWidget(ui->monsterTab);
}

void MainWindow::on_actionBestiary_triggered()
{
	reset();
	ui->stackedWidget->setCurrentWidget(ui->editpage);
	ui->bestiaryTabWidget->setCurrentWidget(ui->monsterTab);
}

void MainWindow::on_homepageButton_clicked()
{
	confirmHomepage();
}

void MainWindow::on_homepageButton_2_clicked()
{
	confirmHomepage();
}

void MainWindow::on_quitButton_clicked()
{
	confirmCloseApplication();
}

void MainWindow::on_actionQuit_triggered()
{
	confirmCloseApplication();
}

void MainWindow::on_createBattleButton_clicked()
{
	reset();
	ui->stackedWidget->setCurrentWidget(ui->createBattlepage);
}

void MainWindow::on_actionCreateBattle_triggered()
{
	reset();
	ui->stackedWidget->setCurrentWidget(ui->createBattlepage);
}

void MainWindow::on_actionSettings_triggered()
{
	SettingsDialog *window = new SettingsDialog(this);

	window->move(QPoint((QApplication::desktop()->width() - window->width())/2, (QApplication::desktop()->height() - window->height())/2));
	window->show();
}

void GroupForm::on_quitButton_clicked()
{
	this->close();
}
/** Fin changement de page **/

/** Formulaires et génération **/
void MainWindow::on_createAttackButton_clicked()
{
	AttackForm *window = new AttackForm(this);

	window->move(QPoint((QApplication::desktop()->width() - window->width())/2, (QApplication::desktop()->height() - window->height())/2));
	window->show();
}

void MainWindow::on_changeAttackButton_clicked()
{
	Attack *attack = new Attack();
	attack->setName(ui->attackNameValue->text());
	attack->setPA(ui->paCostValue->text().toInt());
	attack->setPM(ui->pmCostValue->text().toInt());
	attack->setPC(ui->pcCostValue->text().toInt());
	attack->setPOMin(ui->poAttackValueMin->text().toInt());
	attack->setPOMax(ui->poAttackValueMax->text().toInt());
	attack->setViewLine(ui->viewLineValue->isChecked());
	attack->setTypeArea(new TypeArea(Form::toEnum(ui->typeAreaFormValue->text()),
									 ui->typeAreaSizeValue->text().toInt()));
	attack->setTypeLaunch(TypeLaunch::toEnum(ui->typeLaunchValue->text()));
	attack->setElement(Element::toEnum(ui->elementValue->text()));
	attack->setDamageMin(ui->damagesValueMin->text().toInt());
	attack->setDamageMax(ui->damagesValueMax->text().toInt());
	attack->setHealMin(ui->healValueMin->text().toInt());
	attack->setHealMax(ui->healValueMax->text().toInt());

	AttackForm *window = new AttackForm(this, attack);

	window->move(QPoint((QApplication::desktop()->width() - window->width())/2, (QApplication::desktop()->height() - window->height())/2));
	window->show();

	delete attack;
}

void MainWindow::on_generateButton_clicked()
{
	ui->mapTableWidget->clear();

	Map *map = new Map(deserializeGroups(ui->widthSpin->value(), ui->lengthSpin->value()), ui->widthSpin->value(), ui->lengthSpin->value(), ui->groupBox->value());

	for (std::vector<Cell *> row : map->getGrid()) {
		for (Cell *cell : row) {
			ui->mapTableWidget->setItem(cell->getX(),cell->getY(), new QTableWidgetItem);
			ui->mapTableWidget->item(cell->getX(),cell->getY())->setBackground(cell->getColor());
		}
	}
	delete map;

	std::vector<Mob *> mobs = deserializeMobs(ui->monsterTypeBox->currentText(),ui->battleLevelSpin->value());

	if (!mobs.empty()) {
		for (int i=0; i < ui->monsterNumberSpin->value(); ++i) {
			Mob *mob = new Mob(*mobs[rand() % mobs.size()]);
			int level = std::max(mob->getMinSkills()->getLevel(), std::min(mob->getMaxSkills()->getLevel(), ui->battleLevelSpin->value() - 2 + rand()%5));
			mob->setCurrentSkills(mob->calculateSkills(level));

			int row;
			int column;

			do {
				row = rand() % ui->mapTableWidget->rowCount();
				column = rand() % ui->mapTableWidget->columnCount();
			} while(ui->mapTableWidget->item(row,column)->background() != QBrush());

			ui->mapTableWidget->item(row, column)->setBackground(Qt::yellow);
			ui->mapTableWidget->item(row, column)->setText(mob->displayMainInfo());
			ui->mapTableWidget->item(row, column)->setToolTip(mob->display());
		}

		ui->exportButton->setEnabled(true);
	}
}

void MainWindow::on_exportButton_clicked()
{
	QString file(QFileDialog::getSaveFileName(this, "Sauvegarder le combat", dataPath + "/battles/Nouveau combat", "Fichier Excel (*.xlsx)"));

	if (!file.isEmpty()) {
		QXlsx::Document excel;

		int nbMonstre = 0;
		int excelColumn = 1;
		for (int row  = 0; row < ui->mapTableWidget->rowCount(); ++row) {
			for (int column = 0; column < ui->mapTableWidget->columnCount(); ++column) {
				if (!ui->mapTableWidget->item(row, column)->toolTip().isNull() && !ui->mapTableWidget->item(row, column)->toolTip().isEmpty()) {
					QStringList infos = ui->mapTableWidget->item(row, column)->toolTip().split("\n", QString::SkipEmptyParts);

					int excelRow = 1;
					excel.setColumnWidth(excelColumn, 20);
					excel.write(excelRow++, excelColumn, "Monstre n°" + QString::number(++nbMonstre));

					for (QString info : infos) {
						excel.write(excelRow, excelColumn, info.split(" : ")[0]);
						excel.write(excelRow++, excelColumn + 1, info.split(" : ")[1]);
					}

					excelColumn += 3;
				}
			}
		}

		excel.saveAs(file);
	}
}

void MainWindow::on_manageButton_clicked()
{
	GroupForm *window = new GroupForm(this);

	window->move(QPoint((QApplication::desktop()->width() - window->width())/2, (QApplication::desktop()->height() - window->height())/2));
	window->show();
}

void MainWindow::on_resetButton_clicked()
{
	resetMobForm();
}

void MainWindow::on_saveButton_clicked()
{
	createMissingMobDir(ui->typeComboBox->currentText());
	QFile file(QFileDialog::getSaveFileName(this, "Sauvegarder le mob", dataPath + "/mobs/" +
											ui->typeComboBox->currentText() + "/" + ui->nameLineEdit->text() + ".json", "Fichier JSON (*.json)"));

	if (!file.fileName().isEmpty()) {
		/** Création minSkills **/
		MobSkills *minSkills = new MobSkills();
		minSkills->setLevel(ui->levelSpinMin->value());
		minSkills->setHp(ui->hpSpinMin->value());
		minSkills->setPA(ui->paSpinMin->value());
		minSkills->setPM(ui->pmSpinMin->value());
		minSkills->setPC(ui->pcSpinMin->value());
		minSkills->setWaterMastery(ui->waterMasterySpinMin->value());
		minSkills->setWaterBlock(ui->waterBlockSpinMin->value());
		minSkills->setFireMastery(ui->fireMasterySpinMin->value());
		minSkills->setFireBlock(ui->fireBlockSpinMin->value());
		minSkills->setEarthMastery(ui->earthMasterySpinMin->value());
		minSkills->setEarthBlock(ui->earthBlockSpinMin->value());
		minSkills->setWindMastery(ui->windMasterySpinMin->value());
		minSkills->setWindBlock(ui->windBlockSpinMin->value());
		minSkills->setCritical(ui->criticalSpinMin->value());
		minSkills->setInitiative(ui->initiativeSpinMin->value());
		minSkills->setParade(ui->paradeSpinMin->value());
		minSkills->setPO(ui->poSpinMin->value());
		minSkills->setWill(ui->willSpinMin->value());
		minSkills->setTackle(ui->tackleSpinMin->value());
		minSkills->setDodge(ui->dodgeSpinMin->value());
		minSkills->setControl(ui->controlSpinMin->value());
		minSkills->setCriticalMastery(ui->criticalMasterySpinMin->value());
		minSkills->setCriticalBlock(ui->criticalBlockSpinMin->value());
		/** Fin création minSkills **/

		/** Création maxSkills **/
		MobSkills *maxSkills = new MobSkills();
		maxSkills->setLevel(ui->levelSpinMax->value());
		maxSkills->setHp(ui->hpSpinMax->value());
		maxSkills->setPA(ui->paSpinMax->value());
		maxSkills->setPM(ui->pmSpinMax->value());
		maxSkills->setPC(ui->pcSpinMax->value());
		maxSkills->setWaterMastery(ui->waterMasterySpinMax->value());
		maxSkills->setWaterBlock(ui->waterBlockSpinMax->value());
		maxSkills->setFireMastery(ui->fireMasterySpinMax->value());
		maxSkills->setFireBlock(ui->fireBlockSpinMax->value());
		maxSkills->setEarthMastery(ui->earthMasterySpinMax->value());
		maxSkills->setEarthBlock(ui->earthBlockSpinMax->value());
		maxSkills->setWindMastery(ui->windMasterySpinMax->value());
		maxSkills->setWindBlock(ui->windBlockSpinMax->value());
		maxSkills->setCritical(ui->criticalSpinMax->value());
		maxSkills->setInitiative(ui->initiativeSpinMax->value());
		maxSkills->setParade(ui->paradeSpinMax->value());
		maxSkills->setPO(ui->poSpinMax->value());
		maxSkills->setWill(ui->willSpinMax->value());
		maxSkills->setTackle(ui->tackleSpinMax->value());
		maxSkills->setDodge(ui->dodgeSpinMax->value());
		maxSkills->setControl(ui->controlSpinMax->value());
		maxSkills->setCriticalMastery(ui->criticalMasterySpinMax->value());
		maxSkills->setCriticalBlock(ui->criticalBlockSpinMax->value());
		/** Fin création maxSkills **/

		/** Ajout des attaques **/
		std::vector<Attack *> attacks;
		for(int i = 0; i < ui->attacksOwnedListWidget->count(); ++i) {
			QFile file(dataPath + "/attacks/" + ui->attacksOwnedListWidget->item(i)->text() + ".json");

			if (!file.fileName().isEmpty()) {
				file.open(QIODevice::ReadOnly);
				QByteArray savedAttack = file.readAll();
				QJsonDocument loadDoc(QJsonDocument::fromJson(savedAttack));

				Attack *attack = new Attack();
				attack->read(loadDoc.object());
				file.close();

				attacks.push_back(attack);
			}
		}
		/** Fin ajout des attaques **/

		/** Création mob **/
		if (mob != nullptr) {
			delete mob;
		}

		mob = new Mob();
		mob->setName(ui->nameLineEdit->text());
		mob->setType(ui->typeComboBox->currentText());
		mob->setMinSkills(minSkills);
		mob->setMaxSkills(maxSkills);
		mob->setAttacks(attacks);
		/** Fin création mob **/

		/** Sérialisation **/
		file.open(QIODevice::WriteOnly | QIODevice::Truncate);

		QJsonObject mobObject;
		mob->write(mobObject);

		QJsonDocument saveDoc(mobObject);
		file.write(saveDoc.toJson());

		file.close();
		/** Fin sérialisation **/
	}
}


void MainWindow::on_loadButton_clicked()
{
	QFile file(QFileDialog::getOpenFileName(this, "Choisir le monstre à charger", dataPath + "/mobs", "Fichier JSON (*.json)"));

	if (!file.fileName().isEmpty()) {
		file.open(QIODevice::ReadOnly);
		QByteArray savedMob = file.readAll();
		QJsonDocument loadDoc(QJsonDocument::fromJson(savedMob));

		if (mob != nullptr) {
			delete mob;
		}

		mob = new Mob();
		mob->read(loadDoc.object());
		file.close();

		ui->nameLineEdit->setText(mob->getName());
		ui->typeComboBox->setCurrentText(mob->getType());

		/** Remplissage minSkills **/
		ui->levelSpinMin->setValue(mob->getMinSkills()->getLevel());
		ui->hpSpinMin->setValue(mob->getMinSkills()->getHp());
		ui->paSpinMin->setValue(mob->getMinSkills()->getPA());
		ui->pmSpinMin->setValue(mob->getMinSkills()->getPM());
		ui->pcSpinMin->setValue(mob->getMinSkills()->getPC());
		ui->waterMasterySpinMin->setValue(mob->getMinSkills()->getWaterMastery());
		ui->waterBlockSpinMin->setValue(mob->getMinSkills()->getWaterBlock());
		ui->fireMasterySpinMin->setValue(mob->getMinSkills()->getFireMastery());
		ui->fireBlockSpinMin->setValue(mob->getMinSkills()->getFireBlock());
		ui->earthMasterySpinMin->setValue(mob->getMinSkills()->getEarthMastery());
		ui->earthBlockSpinMin->setValue(mob->getMinSkills()->getEarthBlock());
		ui->windMasterySpinMin->setValue(mob->getMinSkills()->getWindMastery());
		ui->windBlockSpinMin->setValue(mob->getMinSkills()->getWindBlock());
		ui->criticalSpinMin->setValue(mob->getMinSkills()->getCritical());
		ui->initiativeSpinMin->setValue(mob->getMinSkills()->getInitiative());
		ui->paradeSpinMin->setValue(mob->getMinSkills()->getParade());
		ui->poSpinMin->setValue(mob->getMinSkills()->getPO());
		ui->willSpinMin->setValue(mob->getMinSkills()->getWill());
		ui->tackleSpinMin->setValue(mob->getMinSkills()->getTackle());
		ui->dodgeSpinMin->setValue(mob->getMinSkills()->getDodge());
		ui->controlSpinMin->setValue(mob->getMinSkills()->getControl());
		ui->criticalMasterySpinMin->setValue(mob->getMinSkills()->getCriticalMastery());
		ui->criticalBlockSpinMin->setValue(mob->getMinSkills()->getCriticalBlock());
		/** Fin remplissage minSkills **/

		/** Remplissage maxSkills **/
		ui->levelSpinMax->setValue(mob->getMaxSkills()->getLevel());
		ui->hpSpinMax->setValue(mob->getMaxSkills()->getHp());
		ui->paSpinMax->setValue(mob->getMaxSkills()->getPA());
		ui->pmSpinMax->setValue(mob->getMaxSkills()->getPM());
		ui->pcSpinMax->setValue(mob->getMaxSkills()->getPC());
		ui->waterMasterySpinMax->setValue(mob->getMaxSkills()->getWaterMastery());
		ui->waterBlockSpinMax->setValue(mob->getMaxSkills()->getWaterBlock());
		ui->fireMasterySpinMax->setValue(mob->getMaxSkills()->getFireMastery());
		ui->fireBlockSpinMax->setValue(mob->getMaxSkills()->getFireBlock());
		ui->earthMasterySpinMax->setValue(mob->getMaxSkills()->getEarthMastery());
		ui->earthBlockSpinMax->setValue(mob->getMaxSkills()->getEarthBlock());
		ui->windMasterySpinMax->setValue(mob->getMaxSkills()->getWindMastery());
		ui->windBlockSpinMax->setValue(mob->getMaxSkills()->getWindBlock());
		ui->criticalSpinMax->setValue(mob->getMaxSkills()->getCritical());
		ui->initiativeSpinMax->setValue(mob->getMaxSkills()->getInitiative());
		ui->paradeSpinMax->setValue(mob->getMaxSkills()->getParade());
		ui->poSpinMax->setValue(mob->getMaxSkills()->getPO());
		ui->willSpinMax->setValue(mob->getMaxSkills()->getWill());
		ui->tackleSpinMax->setValue(mob->getMaxSkills()->getTackle());
		ui->dodgeSpinMax->setValue(mob->getMaxSkills()->getDodge());
		ui->controlSpinMax->setValue(mob->getMaxSkills()->getControl());
		ui->criticalMasterySpinMax->setValue(mob->getMaxSkills()->getCriticalMastery());
		ui->criticalBlockSpinMax->setValue(mob->getMaxSkills()->getCriticalBlock());
		/** Fin remplissage maxSkills **/

		/** Remplissage attaques **/
		loadAttackLists();
		/** Fin remplissage attaque **/
	}
}
/** Fin formulaires et génération **/
/** Gestion des boutons **/

/** Affichage des attaques **/
void MainWindow::on_attacksOwnedListWidget_itemClicked(QListWidgetItem *item)
{
	displayAttackInformation(item->text());
}

void MainWindow::on_attacksLeftListWidget_itemClicked(QListWidgetItem *item)
{
	displayAttackInformation(item->text());
}
/** Fin affichage des attaques **/
