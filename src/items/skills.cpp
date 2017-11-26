#include "inc/items/skills.h"

Skills::Skills()
{

}

Skills::Skills(const Skills &skills) :
	hp(skills.hp), PA(skills.PA), PM(skills.PM), PC(skills.PC),
	waterMastery(skills.waterMastery), waterBlock(skills.waterBlock),
	fireMastery(skills.fireMastery), fireBlock(skills.fireBlock),
	earthMastery(skills.earthMastery), earthBlock(skills.earthBlock),
	windMastery(skills.windMastery), windBlock(skills.windBlock),
	critical(skills.critical), initiative(skills.initiative), parade(skills.parade),
	PO(skills.PO), will(skills.will), tackle(skills.tackle), dodge(skills.dodge),
	wisdom(skills.wisdom), prospection(skills.prospection), control(skills.control),
	distanceMastery(skills.distanceMastery), meleeMastery(skills.meleeMastery),
	areaMastery(skills.areaMastery), singleMastery(skills.singleMastery),
	criticalMastery(skills.criticalMastery), criticalBlock(skills.criticalBlock)
{

}

Skills::~Skills()
{

}

/** Accesseurs **/
int Skills::getHp() const
{
	return hp;
}

void Skills::setHp(int value)
{
	hp = value;
}

int Skills::getPA() const
{
	return PA;
}

void Skills::setPA(int value)
{
	PA = value;
}

int Skills::getPM() const
{
	return PM;
}

void Skills::setPM(int value)
{
	PM = value;
}

int Skills::getPC() const
{
	return PC;
}

void Skills::setPC(int value)
{
	PC = value;
}

int Skills::getWaterMastery() const
{
	return waterMastery;
}

void Skills::setWaterMastery(int value)
{
	waterMastery = value;
}

int Skills::getWaterBlock() const
{
	return waterBlock;
}

void Skills::setWaterBlock(int value)
{
	waterBlock = value;
}

int Skills::getFireMastery() const
{
	return fireMastery;
}

void Skills::setFireMastery(int value)
{
	fireMastery = value;
}

int Skills::getFireBlock() const
{
	return fireBlock;
}

void Skills::setFireBlock(int value)
{
	fireBlock = value;
}

int Skills::getEarthMastery() const
{
	return earthMastery;
}

void Skills::setEarthMastery(int value)
{
	earthMastery = value;
}

int Skills::getEarthBlock() const
{
	return earthBlock;
}

void Skills::setEarthBlock(int value)
{
	earthBlock = value;
}

int Skills::getWindMastery() const
{
	return windMastery;
}

void Skills::setWindMastery(int value)
{
	windMastery = value;
}

int Skills::getWindBlock() const
{
	return windBlock;
}

void Skills::setWindBlock(int value)
{
	windBlock = value;
}

int Skills::getCritical() const
{
	return critical;
}

void Skills::setCritical(int value)
{
	critical = value;
}

int Skills::getInitiative() const
{
	return initiative;
}

void Skills::setInitiative(int value)
{
	initiative = value;
}

int Skills::getParade() const
{
	return parade;
}

void Skills::setParade(int value)
{
	parade = value;
}

int Skills::getPO() const
{
	return PO;
}

void Skills::setPO(int value)
{
	PO = value;
}

int Skills::getWill() const
{
	return will;
}

void Skills::setWill(int value)
{
	will = value;
}

int Skills::getTackle() const
{
	return tackle;
}

void Skills::setTackle(int value)
{
	tackle = value;
}

int Skills::getDodge() const
{
	return dodge;
}

void Skills::setDodge(int value)
{
	dodge = value;
}

int Skills::getWisdom() const
{
	return wisdom;
}

void Skills::setWisdom(int value)
{
	wisdom = value;
}

int Skills::getProspection() const
{
	return prospection;
}

void Skills::setProspection(int value)
{
	prospection = value;
}

int Skills::getControl() const
{
	return control;
}

void Skills::setControl(int value)
{
	control = value;
}

int Skills::getDistanceMastery() const
{
	return distanceMastery;
}

void Skills::setDistanceMastery(int value)
{
	distanceMastery = value;
}

int Skills::getMeleeMastery() const
{
	return meleeMastery;
}

void Skills::setMeleeMastery(int value)
{
	meleeMastery = value;
}

int Skills::getAreaMastery() const
{
	return areaMastery;
}

void Skills::setAreaMastery(int value)
{
	areaMastery = value;
}

int Skills::getSingleMastery() const
{
	return singleMastery;
}

void Skills::setSingleMastery(int value)
{
	singleMastery = value;
}

int Skills::getCriticalMastery() const
{
	return criticalMastery;
}

void Skills::setCriticalMastery(int value)
{
	criticalMastery = value;
}

int Skills::getCriticalBlock() const
{
	return criticalBlock;
}

void Skills::setCriticalBlock(int value)
{
	criticalBlock = value;
}
/** Fin accesseurs **/
