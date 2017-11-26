#ifndef SKILLS_H
#define SKILLS_H

class Skills {
	private:
		/** Base **/
		int hp;

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
		int critical;

		int initiative;
		int parade;
		int PO;

		int will;

		int tackle;
		int dodge;

		int wisdom;
		int prospection;

		int control;
		/** Fin combat **/

		/** Secondaire **/
		int distanceMastery;
		int meleeMastery;
		int areaMastery;
		int singleMastery;

		int criticalMastery;
		int criticalBlock;
		/** Fin secondaire **/

	public:
		Skills();
		Skills(Skills const& skills);

		~Skills();

		/** Accesseurs **/
		int getHp() const;
		void setHp(int value);

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

		int getWisdom() const;
		void setWisdom(int value);

		int getProspection() const;
		void setProspection(int value);

		int getControl() const;
		void setControl(int value);

		int getDistanceMastery() const;
		void setDistanceMastery(int value);

		int getMeleeMastery() const;
		void setMeleeMastery(int value);

		int getAreaMastery() const;
		void setAreaMastery(int value);

		int getSingleMastery() const;
		void setSingleMastery(int value);

		int getCriticalMastery() const;
		void setCriticalMastery(int value);

		int getCriticalBlock() const;
		void setCriticalBlock(int value);
		/** Fin accesseurs **/
};

#endif // SKILLS_H
