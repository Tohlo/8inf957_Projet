#include "inc/windows/mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::calculatePercentBlock(int block) {
	return (1 - std::pow(0.85l, block/100.l)) * 100;
}

/** EDITION DES MOBS **/
/** Changement valeur minimale **/
/** Base **/
void MainWindow::on_levelSpinMin_valueChanged(int arg1)
{
	ui->levelSpinMax->setValue(std::max(arg1, ui->levelSpinMax->value()));
}

void MainWindow::on_hpSpinMin_valueChanged(int arg1)
{
	ui->hpSpinMax->setValue(std::max(arg1, ui->hpSpinMax->value()));
}

void MainWindow::on_paSpinMin_valueChanged(int arg1)
{
	ui->paSpinMax->setValue(std::max(arg1, ui->paSpinMax->value()));
}

void MainWindow::on_pmSpinMin_valueChanged(int arg1)
{
	ui->pmSpinMax->setValue(std::max(arg1, ui->pmSpinMax->value()));
}

void MainWindow::on_pcSpinMin_valueChanged(int arg1)
{
	ui->pcSpinMax->setValue(std::max(arg1, ui->pcSpinMax->value()));
}
/** Fin base **/

/** Maîtrises **/
void MainWindow::on_waterMasterySpinMin_valueChanged(int arg1)
{
	ui->waterMasterySpinMax->setValue(std::max(arg1, ui->waterMasterySpinMax->value()));
}

void MainWindow::on_waterBlockSpinMin_valueChanged(int arg1)
{
	ui->waterBlockSpinMax->setValue(std::max(arg1, ui->waterBlockSpinMax->value()));

	ui->waterBlockPercentMin->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}

void MainWindow::on_earthMasterySpinMin_valueChanged(int arg1)
{
	ui->earthMasterySpinMax->setValue(std::max(arg1, ui->earthMasterySpinMax->value()));
}

void MainWindow::on_earthBlockSpinMin_valueChanged(int arg1)
{
	ui->earthBlockSpinMax->setValue(std::max(arg1, ui->earthBlockSpinMax->value()));

	ui->earthBlockPercentMin->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}

void MainWindow::on_windMasterySpinMin_valueChanged(int arg1)
{
	ui->windMasterySpinMax->setValue(std::max(arg1, ui->windMasterySpinMax->value()));
}

void MainWindow::on_windBlockSpinMin_valueChanged(int arg1)
{
	ui->windBlockSpinMax->setValue(std::max(arg1, ui->windBlockSpinMax->value()));

	ui->windBlockPercentMin->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}

void MainWindow::on_fireMasterySpinMin_valueChanged(int arg1)
{
	ui->fireMasterySpinMax->setValue(std::max(arg1, ui->fireMasterySpinMax->value()));
}

void MainWindow::on_fireBlockSpinMin_valueChanged(int arg1)
{
	ui->fireBlockSpinMax->setValue(std::max(arg1, ui->fireBlockSpinMax->value()));

	ui->fireBlockPercentMin->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}
/** Fin maîtrises **/

/** Combat **/
void MainWindow::on_criticalSpinMin_valueChanged(int arg1)
{
	ui->criticalSpinMax->setValue(std::max(arg1, ui->criticalSpinMax->value()));
}

void MainWindow::on_paradeSpinMin_valueChanged(int arg1)
{
	ui->paradeSpinMax->setValue(std::max(arg1, ui->paradeSpinMax->value()));
}

void MainWindow::on_initiativeSpinMin_valueChanged(int arg1)
{
	ui->initiativeSpinMax->setValue(std::max(arg1, ui->initiativeSpinMax->value()));
}

void MainWindow::on_poSpinMin_valueChanged(int arg1)
{
	ui->poSpinMax->setValue(std::max(arg1, ui->poSpinMax->value()));
}

void MainWindow::on_dodgeSpinMin_valueChanged(int arg1)
{
	ui->dodgeSpinMax->setValue(std::max(arg1, ui->dodgeSpinMax->value()));
}

void MainWindow::on_tackleSpinMin_valueChanged(int arg1)
{
	ui->tackleSpinMax->setValue(std::max(arg1, ui->tackleSpinMax->value()));
}

void MainWindow::on_controlSpinMin_valueChanged(int arg1)
{
	ui->controlSpinMax->setValue(std::max(arg1, ui->controlSpinMax->value()));
}

void MainWindow::on_willSpinMin_valueChanged(int arg1)
{
	ui->willSpinMax->setValue(std::max(arg1, ui->willSpinMax->value()));
}
/** Fin combat **/

/** Secondaire **/
void MainWindow::on_criticalMasterySpinMin_valueChanged(int arg1)
{
	ui->criticalMasterySpinMax->setValue(std::max(arg1, ui->criticalMasterySpinMax->value()));
}

void MainWindow::on_criticalBlockSpinMin_valueChanged(int arg1)
{
	ui->criticalBlockSpinMax->setValue(std::max(arg1, ui->criticalBlockSpinMax->value()));
}

void MainWindow::on_meleeMasterySpinMin_valueChanged(int arg1)
{
	ui->meleeMasterySpinMax->setValue(std::max(arg1, ui->meleeMasterySpinMax->value()));
}

void MainWindow::on_distanceMasterySpinMin_valueChanged(int arg1)
{
	ui->distanceMasterySpinMax->setValue(std::max(arg1, ui->distanceMasterySpinMax->value()));
}

void MainWindow::on_singleMasterySpinMin_valueChanged(int arg1)
{
	ui->singleMasterySpinMax->setValue(std::max(arg1, ui->singleMasterySpinMax->value()));
}

void MainWindow::on_areaMasterySpinMin_valueChanged(int arg1)
{
	ui->areaMasterySpinMax->setValue(std::max(arg1, ui->areaMasterySpinMax->value()));
}
/** Fin secondaire **/
/** Fin changement valeur minimale **/

/** Changement valeur maximale **/
/** Base **/
void MainWindow::on_levelSpinMax_valueChanged(int arg1)
{
	ui->levelSpinMin->setValue(std::min(arg1, ui->levelSpinMin->value()));
}

void MainWindow::on_hpSpinMax_valueChanged(int arg1)
{
	ui->hpSpinMin->setValue(std::min(arg1, ui->hpSpinMin->value()));
}

void MainWindow::on_paSpinMax_valueChanged(int arg1)
{
	ui->paSpinMin->setValue(std::min(arg1, ui->paSpinMin->value()));
}

void MainWindow::on_pmSpinMax_valueChanged(int arg1)
{
	ui->pmSpinMin->setValue(std::min(arg1, ui->pmSpinMin->value()));
}

void MainWindow::on_pcSpinMax_valueChanged(int arg1)
{
	ui->pcSpinMin->setValue(std::min(arg1, ui->pcSpinMin->value()));
}
/** Fin base **/

/** Maîtrises **/
void MainWindow::on_waterMasterySpinMax_valueChanged(int arg1)
{
	ui->waterMasterySpinMin->setValue(std::min(arg1, ui->waterMasterySpinMin->value()));
}

void MainWindow::on_waterBlockSpinMax_valueChanged(int arg1)
{
	ui->waterBlockSpinMin->setValue(std::min(arg1, ui->waterBlockSpinMin->value()));

	ui->waterBlockPercentMax->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}

void MainWindow::on_earthMasterySpinMax_valueChanged(int arg1)
{
	ui->earthMasterySpinMin->setValue(std::min(arg1, ui->earthMasterySpinMin->value()));
}

void MainWindow::on_earthBlockSpinMax_valueChanged(int arg1)
{
	ui->earthBlockSpinMin->setValue(std::min(arg1, ui->earthBlockSpinMin->value()));

	ui->earthBlockPercentMax->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}

void MainWindow::on_windMasterySpinMax_valueChanged(int arg1)
{
	ui->windMasterySpinMin->setValue(std::min(arg1, ui->windMasterySpinMin->value()));
}

void MainWindow::on_windBlockSpinMax_valueChanged(int arg1)
{
	ui->windBlockSpinMin->setValue(std::min(arg1, ui->windBlockSpinMin->value()));

	ui->windBlockPercentMax->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}

void MainWindow::on_fireMasterySpinMax_valueChanged(int arg1)
{
	ui->fireMasterySpinMin->setValue(std::min(arg1, ui->fireMasterySpinMin->value()));
}

void MainWindow::on_fireBlockSpinMax_valueChanged(int arg1)
{
	ui->fireBlockSpinMin->setValue(std::min(arg1, ui->fireBlockSpinMin->value()));

	ui->fireBlockPercentMax->setText(QString::number(calculatePercentBlock(arg1)) + "%");
}
/** Fin maîtrises **/

/** Combat **/
void MainWindow::on_criticalSpinMax_valueChanged(int arg1)
{
	ui->criticalSpinMin->setValue(std::min(arg1, ui->criticalSpinMin->value()));
}

void MainWindow::on_paradeSpinMax_valueChanged(int arg1)
{
	ui->paradeSpinMin->setValue(std::min(arg1, ui->paradeSpinMin->value()));
}

void MainWindow::on_initiativeSpinMax_valueChanged(int arg1)
{
	ui->initiativeSpinMin->setValue(std::min(arg1, ui->initiativeSpinMin->value()));
}

void MainWindow::on_poSpinMax_valueChanged(int arg1)
{
	ui->poSpinMin->setValue(std::min(arg1, ui->poSpinMin->value()));
}

void MainWindow::on_dodgeSpinMax_valueChanged(int arg1)
{
	ui->dodgeSpinMin->setValue(std::min(arg1, ui->dodgeSpinMin->value()));
}

void MainWindow::on_tackleSpinMax_valueChanged(int arg1)
{
	ui->tackleSpinMin->setValue(std::min(arg1, ui->tackleSpinMin->value()));
}

void MainWindow::on_controlSpinMax_valueChanged(int arg1)
{
	ui->controlSpinMin->setValue(std::min(arg1, ui->controlSpinMin->value()));
}

void MainWindow::on_willSpinMax_valueChanged(int arg1)
{
	ui->willSpinMin->setValue(std::min(arg1, ui->willSpinMin->value()));
}
/** Fin combat **/

/** Secondaire **/
void MainWindow::on_criticalMasterySpinMax_valueChanged(int arg1)
{
	ui->criticalMasterySpinMin->setValue(std::min(arg1, ui->criticalMasterySpinMin->value()));
}

void MainWindow::on_criticalBlockSpinMax_valueChanged(int arg1)
{
	ui->criticalBlockSpinMin->setValue(std::min(arg1, ui->criticalBlockSpinMin->value()));
}

void MainWindow::on_meleeMasterySpinMax_valueChanged(int arg1)
{
	ui->meleeMasterySpinMin->setValue(std::min(arg1, ui->meleeMasterySpinMin->value()));
}

void MainWindow::on_distanceMasterySpinMax_valueChanged(int arg1)
{
	ui->distanceMasterySpinMin->setValue(std::min(arg1, ui->distanceMasterySpinMin->value()));
}

void MainWindow::on_singleMasterySpinMax_valueChanged(int arg1)
{
	ui->singleMasterySpinMin->setValue(std::min(arg1, ui->singleMasterySpinMin->value()));
}

void MainWindow::on_areaMasterySpinMax_valueChanged(int arg1)
{
	ui->areaMasterySpinMin->setValue(std::min(arg1, ui->areaMasterySpinMin->value()));
}
/** Fin secondaire **/
/** Fin changement valeur maximale **/
/** FIN EDITION DES MOBS **/
