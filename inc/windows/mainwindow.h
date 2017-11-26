#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QListWidgetItem>
#include <QCloseEvent>

#include "inc/mobs/mob.h"
#include "inc/map/map.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		/** Méthodes **/
			/** Reset **/
		void reset();
		void resetMobForm();
		void resetMapEditor();
			/** Fin reset **/

			/** Affichage **/
		void displayAttackInformation(QString attackName);
		int calculatePercentBlock(int block);
			/** Fin affichage **/

			/** Chargements informations **/
		void loadAttackLists();
		void loadTypeMob();
			/** Fin chargements informations **/

			/** Settings **/
		void readSettings();
		void writeSettings();
			/** Fin settings **/

			/** Répertoires **/
		void createMissingDir();
		void createMissingMobDir(QString type);
			/** Fin répertoires **/

			/** Récupérateurs d'objets **/
		std::vector<Group *> deserializeGroups(int length, int width);
		std::vector<Mob *> deserializeMobs(QString type, int level);
			/** Fin récupérateurs d'objets **/

			/** Confirmations de changements **/
		void confirmHomepage();
		void confirmCloseApplication();
			/** Fin confirmations de changements **/
		/** Fin méthodes **/

		/** Accesseurs **/
		QString getDataPath() const;
		void setDataPath(const QString &value);
		/** Fin accesseurs **/

	private slots:
		/** Gestion des boutons **/
			/** Changement de page **/
		void on_bestiaryButton_clicked();
		void on_actionBestiary_triggered();

		void on_homepageButton_clicked();
		void on_homepageButton_2_clicked();

		void on_quitButton_clicked();
		void on_actionQuit_triggered();

		void on_createBattleButton_clicked();
		void on_actionCreateBattle_triggered();

		void on_actionSettings_triggered();
			/** Fin changement de page **/

			/** Formulaires et génération **/
		void on_createAttackButton_clicked();

		void on_changeAttackButton_clicked();

		void on_generateButton_clicked();

		void on_exportButton_clicked();

		void on_manageButton_clicked();

		void on_resetButton_clicked();

		void on_saveButton_clicked();

		void on_loadButton_clicked();
			/** Fin formulaires et génération **/
		/** Fin gestion des boutons **/

		/** Affichage des attaques **/
		void on_attacksOwnedListWidget_itemClicked(QListWidgetItem *item);

		void on_attacksLeftListWidget_itemClicked(QListWidgetItem *item);
		/** Fin affichage des attaques **/

		/** EDITION DES MOBS **/
		/** Changement valeur minimale **/
			/** Base **/
		void on_levelSpinMin_valueChanged(int arg1);

		void on_hpSpinMin_valueChanged(int arg1);

		void on_paSpinMin_valueChanged(int arg1);

		void on_pmSpinMin_valueChanged(int arg1);

		void on_pcSpinMin_valueChanged(int arg1);
			/** Fin base **/

			/** Maîtrises **/
		void on_waterBlockSpinMin_valueChanged(int arg1);

		void on_waterMasterySpinMin_valueChanged(int arg1);

		void on_earthMasterySpinMin_valueChanged(int arg1);

		void on_earthBlockSpinMin_valueChanged(int arg1);

		void on_windMasterySpinMin_valueChanged(int arg1);

		void on_windBlockSpinMin_valueChanged(int arg1);

		void on_fireMasterySpinMin_valueChanged(int arg1);

		void on_fireBlockSpinMin_valueChanged(int arg1);
			/** Fin maîtrise **/

			/** Combat **/
		void on_criticalSpinMin_valueChanged(int arg1);

		void on_paradeSpinMin_valueChanged(int arg1);

		void on_initiativeSpinMin_valueChanged(int arg1);

		void on_poSpinMin_valueChanged(int arg1);

		void on_dodgeSpinMin_valueChanged(int arg1);

		void on_tackleSpinMin_valueChanged(int arg1);

		void on_controlSpinMin_valueChanged(int arg1);

		void on_willSpinMin_valueChanged(int arg1);
			/** Fin combat **/

			/** Secondaire **/
		void on_criticalMasterySpinMin_valueChanged(int arg1);

		void on_criticalBlockSpinMin_valueChanged(int arg1);

		void on_meleeMasterySpinMin_valueChanged(int arg1);

		void on_distanceMasterySpinMin_valueChanged(int arg1);

		void on_singleMasterySpinMin_valueChanged(int arg1);

		void on_areaMasterySpinMin_valueChanged(int arg1);
			/** Fin secondaire **/
		/** Fin changement valeur minimale **/

		/** Changement valeur maximale **/
			/** Base **/
		void on_levelSpinMax_valueChanged(int arg1);

		void on_hpSpinMax_valueChanged(int arg1);

		void on_paSpinMax_valueChanged(int arg1);

		void on_pmSpinMax_valueChanged(int arg1);

		void on_pcSpinMax_valueChanged(int arg1);
			/** Fin base **/

			/** Maîtrises **/
		void on_waterBlockSpinMax_valueChanged(int arg1);

		void on_waterMasterySpinMax_valueChanged(int arg1);

		void on_earthMasterySpinMax_valueChanged(int arg1);

		void on_earthBlockSpinMax_valueChanged(int arg1);

		void on_windMasterySpinMax_valueChanged(int arg1);

		void on_windBlockSpinMax_valueChanged(int arg1);

		void on_fireMasterySpinMax_valueChanged(int arg1);

		void on_fireBlockSpinMax_valueChanged(int arg1);
			/** Fin maîtrise **/

			/** Combat **/
		void on_criticalSpinMax_valueChanged(int arg1);

		void on_paradeSpinMax_valueChanged(int arg1);

		void on_initiativeSpinMax_valueChanged(int arg1);

		void on_poSpinMax_valueChanged(int arg1);

		void on_dodgeSpinMax_valueChanged(int arg1);

		void on_tackleSpinMax_valueChanged(int arg1);

		void on_controlSpinMax_valueChanged(int arg1);

		void on_willSpinMax_valueChanged(int arg1);
			/** Fin combat **/

			/** Secondaire **/
		void on_criticalMasterySpinMax_valueChanged(int arg1);

		void on_criticalBlockSpinMax_valueChanged(int arg1);

		void on_meleeMasterySpinMax_valueChanged(int arg1);

		void on_distanceMasterySpinMax_valueChanged(int arg1);

		void on_singleMasterySpinMax_valueChanged(int arg1);

		void on_areaMasterySpinMax_valueChanged(int arg1);
			/** Fin secondaire **/
		/** Fin changement valeur maximale **/
		/** FIN EDITION DES MOBS **/

		/** EDITION DU COMBAT **/
		/** Map **/
		void on_lengthSpin_valueChanged(int arg1);

		void on_widthSpin_valueChanged(int arg1);
		/** Fin map **/
		/** FIN EDITION DU COMBAT **/


	private:
		Ui::MainWindow *ui;

		Mob *mob = nullptr;

		QString dataPath;

	protected:
		void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
