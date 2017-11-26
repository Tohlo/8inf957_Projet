#ifndef CARACTERISTIQUESMOB_H
#define CARACTERISTIQUESMOB_H

#include "inc/serializer/serializable.h"

class MobSkills : public Serializable
{
	private:
		/** Base **/
		int level;

		int maxHp;
		int hp;
		int armor;

		int PA;
		int PM;
		int PC;
		/** Fin base **/

		/** Maîtrises **/
		int waterMastery;
		int waterBlock;

		int fireMastery;
		int fireBlock;

		int earthMastery;
		int earthBlock;

		int windMastery;
		int windBlock;
		/** Fin maîtrises **/

		/** Combat **/
		int finalDamages;
		int finalHeal;

		int critical;

		int initiative;
		int parade;
		int PO;

		int will;

		int tackle;
		int dodge;

		int control;
		/** Fin combat **/

		/** Secondaire **/
		int criticalMastery;
		int criticalBlock;
		/** Fin secondaire **/

	public:
		MobSkills();
		MobSkills(MobSkills const& mobSkills);

		virtual ~MobSkills();

		/** Accesseurs **/
		int getLevel() const;
		void setLevel(int value);

		int getMaxHp() const;
		void setMaxHp(int value);

		int getHp() const;
		void setHp(int value);

		int getArmor() const;
		void setArmor(int value);

		int getPA() const;
		void setPA(int value);

		int getPM() const;
		void setPM(int value);

		int getPC() const;
		void setPC(int value);

		int getWaterMastery() const;
		void setWaterMastery(int value);

		int getWaterBlock() const;
		void setWaterBlock(int value);

		int getFireMastery() const;
		void setFireMastery(int value);

		int getFireBlock() const;
		void setFireBlock(int value);

		int getEarthMastery() const;
		void setEarthMastery(int value);

		int getEarthBlock() const;
		void setEarthBlock(int value);

		int getWindMastery() const;
		void setWindMastery(int value);

		int getWindBlock() const;
		void setWindBlock(int value);

		int getFinalDamages() const;
		void setFinalDamages(int value);

		int getFinalHeal() const;
		void setFinalHeal(int value);

		int getCritical() const;
		void setCritical(int value);

		int getInitiative() const;
		void setInitiative(int value);

		int getParade() const;
		void setParade(int value);

		int getPO() const;
		void setPO(int value);

		int getWill() const;
		void setWill(int value);

		int getTackle() const;
		void setTackle(int value);

		int getDodge() const;
		void setDodge(int value);

		int getControl() const;
		void setControl(int value);

		int getCriticalMastery() const;
		void setCriticalMastery(int value);

		int getCriticalBlock() const;
		void setCriticalBlock(int value);
		/** Fin accesseurs **/

		void read(const QJsonObject &json);
		void write(QJsonObject &json) const;
};

#endif // CARACTERISTIQUESMOB_H
