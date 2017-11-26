#include <QJsonArray>

#include "inc/mobs/mob.h"

Mob::Mob() : minSkills(new MobSkills()), maxSkills(new MobSkills()), currentSkills(new MobSkills())
{

}

Mob::Mob(const Mob &mob) :
	name(mob.name),
	minSkills(new MobSkills(*(mob.minSkills))), maxSkills(new MobSkills(*(mob.maxSkills))), currentSkills(new MobSkills(*(mob.currentSkills)))
{

}

Mob::~Mob()
{
	delete minSkills;
	delete maxSkills;
	delete currentSkills;
}

MobSkills *Mob::calculateSkills(int level)
{
	MobSkills *newSkills = new MobSkills;
	newSkills->setLevel(level);
	newSkills->setHp(calculateSkill(maxSkills->getHp(), minSkills->getHp()) * level);
	newSkills->setPA(calculateSkill(maxSkills->getPA(), minSkills->getPA()) * level);
	newSkills->setPM(calculateSkill(maxSkills->getPM(), minSkills->getPM()) * level);
	newSkills->setPC(calculateSkill(maxSkills->getPC(), minSkills->getPC()) * level);
	newSkills->setWaterMastery(calculateSkill(maxSkills->getWaterMastery(), minSkills->getWaterMastery()) * level);
	newSkills->setWaterBlock(calculateSkill(maxSkills->getWaterBlock(), minSkills->getWaterBlock()) * level);
	newSkills->setFireMastery(calculateSkill(maxSkills->getFireMastery(), minSkills->getFireMastery()) * level);
	newSkills->setFireBlock(calculateSkill(maxSkills->getFireBlock(), minSkills->getFireBlock()) * level);
	newSkills->setEarthMastery(calculateSkill(maxSkills->getEarthMastery(), minSkills->getEarthMastery()) * level);
	newSkills->setEarthBlock(calculateSkill(maxSkills->getEarthBlock(), minSkills->getEarthBlock()) * level);
	newSkills->setWindMastery(calculateSkill(maxSkills->getWindMastery(), minSkills->getWindMastery()) * level);
	newSkills->setWindBlock(calculateSkill(maxSkills->getWindBlock(), minSkills->getWindBlock()) * level);
	newSkills->setCritical(calculateSkill(maxSkills->getCritical(), minSkills->getCritical()) * level);
	newSkills->setInitiative(calculateSkill(maxSkills->getInitiative(), minSkills->getInitiative()) * level);
	newSkills->setParade(calculateSkill(maxSkills->getParade(), minSkills->getParade()) * level);
	newSkills->setPO(calculateSkill(maxSkills->getPO(), minSkills->getPO()) * level);
	newSkills->setWill(calculateSkill(maxSkills->getWill(), minSkills->getWill()) * level);
	newSkills->setTackle(calculateSkill(maxSkills->getTackle(), minSkills->getTackle()) * level);
	newSkills->setDodge(calculateSkill(maxSkills->getDodge(), minSkills->getDodge()) * level);
	newSkills->setControl(calculateSkill(maxSkills->getControl(), minSkills->getControl()) * level);
	newSkills->setCriticalMastery(calculateSkill(maxSkills->getCriticalMastery(), minSkills->getCriticalMastery()) * level);
	newSkills->setCriticalBlock(calculateSkill(maxSkills->getCriticalBlock(), minSkills->getCriticalBlock()) * level);

	return newSkills;
}

int Mob::calculateSkill(int maxSkill, int minSkill) {
	return (maxSkill - minSkill) / (1  + maxSkills->getLevel() - minSkills->getLevel());
}

QString Mob::display()
{
	return "Nom : " + name +
			"\nNiveau : " + QString::number(currentSkills->getLevel()) +
			"\nVie : " + QString::number(currentSkills->getHp()) +
			"\nPA : " + QString::number(currentSkills->getPA()) +
			"\nPM : " + QString::number(currentSkills->getPM()) +
			"\nPC : " + QString::number(currentSkills->getPC()) +
			"\nDégâts Eau : " + QString::number(currentSkills->getWaterMastery()) +
			"\nRésistance Eau : " + QString::number(currentSkills->getWaterBlock()) +
			"\nDégâts Feu : " + QString::number(currentSkills->getFireMastery()) +
			"\nRésistance Feu : " + QString::number(currentSkills->getFireBlock()) +
			"\nDégâts Terre : " + QString::number(currentSkills->getEarthMastery()) +
			"\nRésistance Terre : " + QString::number(currentSkills->getEarthBlock()) +
			"\nDégâts Air : " + QString::number(currentSkills->getWindMastery()) +
			"\nRésistance Air : " + QString::number(currentSkills->getWindBlock()) +
			"\nTaux de Critique : " + QString::number(currentSkills->getCritical()) +
			"\nInitiative : " + QString::number(currentSkills->getInitiative()) +
			"\nParade : " + QString::number(currentSkills->getParade()) +
			"\nPO : " + QString::number(currentSkills->getPO()) +
			"\nVolonté : " + QString::number(currentSkills->getWill()) +
			"\nTacle : " + QString::number(currentSkills->getTackle()) +
			"\nEsquive : " + QString::number(currentSkills->getDodge()) +
			"\nContrôle : " + QString::number(currentSkills->getControl()) +
			"\nDégâts Critiques : " + QString::number(currentSkills->getCriticalMastery()) +
			"\nRésistance Critique : " + QString::number(currentSkills->getCriticalBlock())
			;

}

QString Mob::displayMainInfo()
{
	return "Nom : " + name +
			"\nNiveau : " + QString::number(currentSkills->getLevel())
			;
}

/** Accesseurs **/
QString Mob::getName() const
{
	return name;
}

void Mob::setName(const QString &value)
{
	name = value;
}

QString Mob::getType() const
{
	return type;
}

void Mob::setType(const QString &value)
{
	type = value;
}

MobSkills *Mob::getMinSkills() const
{
	return minSkills;
}

void Mob::setMinSkills(MobSkills *value)
{
	minSkills = value;
}

MobSkills *Mob::getMaxSkills() const
{
	return maxSkills;
}

void Mob::setMaxSkills(MobSkills *value)
{
	maxSkills = value;
}

MobSkills *Mob::getCurrentSkills() const
{
	return currentSkills;
}

void Mob::setCurrentSkills(MobSkills *value)
{
	currentSkills = value;
}

std::vector<Attack *> Mob::getAttacks() const
{
	return attacks;
}

void Mob::setAttacks(const std::vector<Attack *> &value)
{
	attacks = value;
}

std::vector<std::pair<Drop *, double> > Mob::getDrops() const
{
	return drops;
}

void Mob::setDrops(const std::vector<std::pair<Drop *, double> > &value)
{
	drops = value;
}

std::vector<Buff *> Mob::getBuffs() const
{
	return buffs;
}

void Mob::setBuffs(const std::vector<Buff *> &value)
{
	buffs = value;
}
/** Fin accesseurs **/

void Mob::read(const QJsonObject &json)
{
	attacks.clear();

	name = json["name"].toString();
	type = json["type"].toString();
	minSkills->read(json["minSkills"].toObject());
	maxSkills->read(json["maxSkills"].toObject());

	QJsonArray attackArray = json["attacks"].toArray();
	for (int i = 0; i < attackArray.size(); ++i) {
		QJsonObject attackObject = attackArray[i].toObject();

		Attack *attack = new Attack();
		attack->read(attackObject);
		attacks.push_back(attack);
	}
}

void Mob::write(QJsonObject &json) const
{
	json["name"] = name;
	json["type"] = type;

	QJsonObject minSkillsObject;
	minSkills->write(minSkillsObject);
	json["minSkills"] = minSkillsObject;

	QJsonObject maxSkillsObject;
	maxSkills->write(maxSkillsObject);
	json["maxSkills"] = maxSkillsObject;

	QJsonArray attackArray;
	foreach (const Attack *attack, attacks) {
		QJsonObject attackObject;
		attack->write(attackObject);
		attackArray.push_back(attackObject);
	}
	json["attacks"] = attackArray;
}
