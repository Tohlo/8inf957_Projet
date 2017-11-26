#ifndef MOB_H
#define MOB_H

#include <vector>
#include <QString>

#include "inc/items/drop.h"
#include "attack.h"
#include "mobSkills.h"

class Mob : public Serializable {
	private:
		QString name;
		QString type;
		MobSkills *minSkills;
		MobSkills *maxSkills;

		MobSkills *currentSkills;

		std::vector<Attack *> attacks;
		std::vector<std::pair<Drop *, double> > drops;
		std::vector<Buff *> buffs;

	public:
		Mob();
		Mob(Mob const& mob);

		virtual ~Mob();

		MobSkills *calculateSkills(int level);
		float calculateSkill(float maxSkill, float minSkill);

		QString display();
		QString displayMainInfo();

		/** Accesseurs **/
		QString getName() const;
		void setName(const QString &value);

		QString getType() const;
		void setType(const QString &value);

		MobSkills *getMinSkills() const;
		void setMinSkills(MobSkills *value);

		MobSkills *getMaxSkills() const;
		void setMaxSkills(MobSkills *value);

		MobSkills *getCurrentSkills() const;
		void setCurrentSkills(MobSkills *value);

		std::vector<Attack *> getAttacks() const;
		void setAttacks(const std::vector<Attack *> &value);

		std::vector<std::pair<Drop *, double> > getDrops() const;
		void setDrops(const std::vector<std::pair<Drop *, double> > &value);

		std::vector<Buff *> getBuffs() const;
		void setBuffs(const std::vector<Buff *> &value);
		/** Fin accesseurs **/

		void read(const QJsonObject &json);
		void write(QJsonObject &json) const;


};

#endif // MOB_H
