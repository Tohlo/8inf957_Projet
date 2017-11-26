#include "inc/mobs/attack.h"

Attack::Attack() : typeArea(new TypeArea()) {

}

Attack::Attack(const Attack &attack) :
	PA(attack.PA), PM(attack.PM), PC(attack.PC),
	POMin(attack.POMin), POMax(attack.POMax), viewLine(attack.viewLine),
	typeArea(attack.typeArea), typeLaunch(attack.typeLaunch),
	element(attack.element), damageMin(attack.damageMin), damageMax(attack.damageMax),
	healMin(attack.healMin), healMax(attack.healMax), buffs(attack.buffs)
{

}

Attack::~Attack()
{

}

/** Accesseurs **/
QString Attack::getName() const
{
	return name;
}

void Attack::setName(const QString &value)
{
	name = value;
}

int Attack::getPA() const
{
	return PA;
}

void Attack::setPA(int value)
{
	PA = value;
}

int Attack::getPM() const
{
	return PM;
}

void Attack::setPM(int value)
{
	PM = value;
}

int Attack::getPC() const
{
	return PC;
}

void Attack::setPC(int value)
{
	PC = value;
}

int Attack::getPOMin() const
{
	return POMin;
}

void Attack::setPOMin(int value)
{
	POMin = value;
}

int Attack::getPOMax() const
{
	return POMax;
}

void Attack::setPOMax(int value)
{
	POMax = value;
}

bool Attack::getViewLine() const
{
	return viewLine;
}

void Attack::setViewLine(bool value)
{
	viewLine = value;
}

TypeArea *Attack::getTypeArea() const
{
	return typeArea;
}

void Attack::setTypeArea(TypeArea *value)
{
	typeArea = value;
}

TypeLaunch::Enum Attack::getTypeLaunch() const
{
	return typeLaunch;
}

void Attack::setTypeLaunch(const TypeLaunch::Enum &value)
{
	typeLaunch = value;
}

Element::Enum Attack::getElement() const
{
	return element;
}

void Attack::setElement(const Element::Enum &value)
{
	element = value;
}

int Attack::getDamageMin() const
{
	return damageMin;
}

void Attack::setDamageMin(int value)
{
	damageMin = value;
}

int Attack::getDamageMax() const
{
	return damageMax;
}

void Attack::setDamageMax(int value)
{
	damageMax = value;
}

int Attack::getHealMin() const
{
	return healMin;
}

void Attack::setHealMin(int value)
{
	healMin = value;
}

int Attack::getHealMax() const
{
	return healMax;
}

void Attack::setHealMax(int value)
{
	healMax = value;
}

std::vector<Buff *> Attack::getBuffs() const
{
	return buffs;
}

void Attack::setBuffs(const std::vector<Buff *> &value)
{
	buffs = value;
}

void Attack::read(const QJsonObject &json)
{
	name = json["name"].toString();
	PA = json["pa"].toInt();
	PM = json["pm"].toInt();
	PC = json["pc"].toInt();
	POMin = json["poMin"].toInt();
	POMax = json["poMax"].toInt();
	viewLine = json["viewLine"].toBool();
	typeArea->read(json["typeArea"].toObject());
	typeLaunch = static_cast<TypeLaunch::Enum>(json["typeLaunch"].toInt());
	element = static_cast<Element::Enum>(json["element"].toInt());
	damageMin = json["damageMin"].toInt();
	damageMax = json["damageMax"].toInt();
	healMin = json["healMin"].toInt();
	healMax = json["healMax"].toInt();
}

void Attack::write(QJsonObject &json) const
{
	json["name"] = name;
	json["pa"] = PA;
	json["pm"] = PM;
	json["pc"] = PC;
	json["poMin"] = POMin;
	json["poMax"] = POMax;
	json["viewLine"] = viewLine;

	QJsonObject typeAreaObject;
	typeArea->write(typeAreaObject);
	json["typeArea"] = typeAreaObject;

	json["typeLaunch"] = static_cast<int>(typeLaunch);
	json["element"] = static_cast<int>(element);
	json["damageMin"] = damageMin;
	json["damageMax"] = damageMax;
	json["healMin"] = healMin;
	json["healMax"] = healMax;
}
/** Fin accesseurs **/
