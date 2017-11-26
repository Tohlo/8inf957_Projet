#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <vector>

#include "inc/serializer/serializable.h"
#include "inc/data/data.h"
#include "inc/data/typeArea.h"
#include "buff.h"

class Attack : public Serializable {
	private:
		QString name;

		/** Coûts **/
		int PA;
		int PM;
		int PC;
		/** Fin coûts **/

		/** Lancer **/
		int POMin;
		int POMax;

		bool viewLine;

		TypeArea *typeArea;
		TypeLaunch::Enum typeLaunch;
		/** Fin lancer **/

		/** Dégâts et soins **/
		Element::Enum element;

		int damageMin;
		int damageMax;

		int healMin;
		int healMax;
		/** Fin dégâts et soins **/

		/** Buffs **/
		std::vector<Buff *> buffs;
		/** Fin buffs **/

	public:
		Attack();
		Attack(Attack const& attaque);

		virtual ~Attack();

		/** Accesseurs **/
		QString getName() const;
		void setName(const QString &value);

		int getPA() const;
		void setPA(int value);

		int getPM() const;
		void setPM(int value);

		int getPC() const;
		void setPC(int value);

		int getPOMin() const;
		void setPOMin(int value);

		int getPOMax() const;
		void setPOMax(int value);

		bool getViewLine() const;
		void setViewLine(bool value);

		TypeArea *getTypeArea() const;
		void setTypeArea(TypeArea *value);

		TypeLaunch::Enum getTypeLaunch() const;
		void setTypeLaunch(const TypeLaunch::Enum &value);

		Element::Enum getElement() const;
		void setElement(const Element::Enum &value);

		int getDamageMin() const;
		void setDamageMin(int value);

		int getDamageMax() const;
		void setDamageMax(int value);

		int getHealMin() const;
		void setHealMin(int value);

		int getHealMax() const;
		void setHealMax(int value);

		std::vector<Buff *> getBuffs() const;
		void setBuffs(const std::vector<Buff *> &value);
		/** Fin accesseurs **/

		void read(const QJsonObject &json);
		void write(QJsonObject &json) const;
};

#endif // ATTAQUE_H
