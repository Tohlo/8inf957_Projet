#include "inc/mobs/mobSkills.h"

MobSkills::MobSkills()
{

}

MobSkills::MobSkills(const MobSkills &mobSkills) :
	level(mobSkills.level), maxHp(mobSkills.maxHp), hp(mobSkills.hp),
	armor(mobSkills.armor),	PA(mobSkills.PA), PM(mobSkills.PM), PC(mobSkills.PC),
	waterMastery(mobSkills.waterMastery), waterBlock(mobSkills.waterBlock),
	fireMastery(mobSkills.fireMastery), fireBlock(mobSkills.fireBlock),
	earthMastery(mobSkills.earthMastery), earthBlock(mobSkills.earthBlock),
	windMastery(mobSkills.windMastery), windBlock(mobSkills.windBlock),
	finalDamages(mobSkills.finalDamages), finalHeal(mobSkills.finalHeal),
	critical(mobSkills.critical), initiative(mobSkills.initiative), parade(mobSkills.parade),
	PO(mobSkills.PO), will(mobSkills.will), tackle(mobSkills.tackle), dodge(mobSkills.dodge), control(mobSkills.control),
	criticalMastery(mobSkills.criticalMastery), criticalBlock(mobSkills.criticalBlock)
{

}

MobSkills::~MobSkills()
{

}

/** Accesseurs **/
int MobSkills::getLevel() const
{
	return level;
}

void MobSkills::setLevel(int value)
{
	level = value;
}

int MobSkills::getMaxHp() const
{
	return maxHp;
}

void MobSkills::setMaxHp(int value)
{
	maxHp = value;
}

int MobSkills::getHp() const
{
	return hp;
}

void MobSkills::setHp(int value)
{
	hp = value;
}

int MobSkills::getArmor() const
{
	return armor;
}

void MobSkills::setArmor(int value)
{
	armor = value;
}

int MobSkills::getPA() const
{
	return PA;
}

void MobSkills::setPA(int value)
{
	PA = value;
}

int MobSkills::getPM() const
{
	return PM;
}

void MobSkills::setPM(int value)
{
	PM = value;
}

int MobSkills::getPC() const
{
	return PC;
}

void MobSkills::setPC(int value)
{
	PC = value;
}

int MobSkills::getWaterMastery() const
{
	return waterMastery;
}

void MobSkills::setWaterMastery(int value)
{
	waterMastery = value;
}

int MobSkills::getWaterBlock() const
{
	return waterBlock;
}

void MobSkills::setWaterBlock(int value)
{
	waterBlock = value;
}

int MobSkills::getFireMastery() const
{
	return fireMastery;
}

void MobSkills::setFireMastery(int value)
{
	fireMastery = value;
}

int MobSkills::getFireBlock() const
{
	return fireBlock;
}

void MobSkills::setFireBlock(int value)
{
	fireBlock = value;
}

int MobSkills::getEarthMastery() const
{
	return earthMastery;
}

void MobSkills::setEarthMastery(int value)
{
	earthMastery = value;
}

int MobSkills::getEarthBlock() const
{
	return earthBlock;
}

void MobSkills::setEarthBlock(int value)
{
	earthBlock = value;
}

int MobSkills::getWindMastery() const
{
	return windMastery;
}

void MobSkills::setWindMastery(int value)
{
	windMastery = value;
}

int MobSkills::getWindBlock() const
{
	return windBlock;
}

void MobSkills::setWindBlock(int value)
{
	windBlock = value;
}

int MobSkills::getFinalDamages() const
{
	return finalDamages;
}

void MobSkills::setFinalDamages(int value)
{
	finalDamages = value;
}

int MobSkills::getFinalHeal() const
{
	return finalHeal;
}

void MobSkills::setFinalHeal(int value)
{
	finalHeal = value;
}

int MobSkills::getCritical() const
{
	return critical;
}

void MobSkills::setCritical(int value)
{
	critical = value;
}

int MobSkills::getInitiative() const
{
	return initiative;
}

void MobSkills::setInitiative(int value)
{
	initiative = value;
}

int MobSkills::getParade() const
{
	return parade;
}

void MobSkills::setParade(int value)
{
	parade = value;
}

int MobSkills::getPO() const
{
	return PO;
}

void MobSkills::setPO(int value)
{
	PO = value;
}

int MobSkills::getWill() const
{
	return will;
}

void MobSkills::setWill(int value)
{
	will = value;
}

int MobSkills::getTackle() const
{
	return tackle;
}

void MobSkills::setTackle(int value)
{
	tackle = value;
}

int MobSkills::getDodge() const
{
	return dodge;
}

void MobSkills::setDodge(int value)
{
	dodge = value;
}

int MobSkills::getControl() const
{
	return control;
}

void MobSkills::setControl(int value)
{
	control = value;
}

int MobSkills::getCriticalMastery() const
{
	return criticalMastery;
}

void MobSkills::setCriticalMastery(int value)
{
	criticalMastery = value;
}

int MobSkills::getCriticalBlock() const
{
	return criticalBlock;
}

void MobSkills::setCriticalBlock(int value)
{
	criticalBlock = value;
}

void MobSkills::read(const QJsonObject &json)
{
	level = json["level"].toInt();
	hp = json["hp"].toInt();
	PA = json["pa"].toInt();
	PM = json["pm"].toInt();
	PC = json["pc"].toInt();
	waterMastery = json["waterMastery"].toInt();
	waterBlock = json["waterBlock"].toInt();
	fireMastery = json["fireMastery"].toInt();
	fireBlock = json["fireBlock"].toInt();
	earthMastery = json["earthMastery"].toInt();
	earthBlock = json["earthBlock"].toInt();
	windMastery = json["windMastery"].toInt();
	windBlock = json["windBlock"].toInt();
	critical = json["critical"].toInt();
	initiative = json["initiative"].toInt();
	parade = json["parade"].toInt();
	PO = json["PO"].toInt();
	will = json["will"].toInt();
	tackle = json["tackle"].toInt();
	dodge = json["dodge"].toInt();
	control = json["control"].toInt();
	criticalMastery = json["criticalMastery"].toInt();
	criticalBlock = json["criticalBlock"].toInt();
}

void MobSkills::write(QJsonObject &json) const
{
	json["level"] = level;
	json["hp"] = hp;
	json["pa"] = PA;
	json["pm"] = PM;
	json["pc"] = PC;
	json["waterMastery"] = waterMastery;
	json["waterBlock"] = waterBlock;
	json["fireMastery"] = fireMastery;
	json["fireBlock"] = fireBlock;
	json["earthMastery"] = earthMastery;
	json["earthBlock"] = earthBlock;
	json["windMastery"] = windMastery;
	json["windBlock"] = windBlock;
	json["critical"] = critical;
	json["initiative"] = initiative;
	json["parade"] = parade;
	json["PO"] = PO;
	json["will"] = will;
	json["tackle"] = tackle;
	json["dodge"] = dodge;
	json["control"] = control;
	json["criticalMastery"] = criticalMastery;
	json["criticalBlock"] = criticalBlock;
}
/** Fin accesseurs **/
