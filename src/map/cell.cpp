#include "inc/map/cell.h"

Cell::Cell() :
	color(QBrush()), coordinates({0, 0}),
	blockViewLine(false), isWalkable(true),
	isPlayerStartingPoint(false), isEnemyStartingPoint(false)
{

}

Cell::Cell(int x, int y):
	color(QBrush()), coordinates({x, y}),
	blockViewLine(false), isWalkable(true),
	isPlayerStartingPoint(false), isEnemyStartingPoint(false)
{

}

Cell::Cell(Cell const& value) :
	color(value.color), coordinates(value.coordinates),
	blockViewLine(value.blockViewLine), isWalkable(value.isWalkable),
	isPlayerStartingPoint(value.isPlayerStartingPoint), isEnemyStartingPoint(value.isEnemyStartingPoint)
{


}


Cell::~Cell()
{


}

/** Accesseurs **/
QBrush Cell::getColor() const
{
	return color;
}

void Cell::setColor(const QBrush &value)
{
	color = value;
}

std::vector<int> Cell::getCoordinates() const
{
	return coordinates;
}

void Cell::setCoordinates(const std::vector<int> &value)
{
	coordinates = value;
}

bool Cell::getBlockViewLine() const
{
	return blockViewLine;
}

void Cell::setBlockViewLine(bool value)
{
	blockViewLine = value;
}

bool Cell::getIsWalkable() const
{
	return isWalkable;
}

void Cell::setIsWalkable(bool value)
{
	isWalkable = value;
}

bool Cell::getIsPlayerStartingPoint() const
{
	return isPlayerStartingPoint;
}

void Cell::setIsPlayerStartingPoint(bool value)
{
	isPlayerStartingPoint = value;
}

bool Cell::getIsEnemyStartingPoint() const
{
	return isEnemyStartingPoint;
}

void Cell::setIsEnemyStartingPoint(bool value)
{
	isEnemyStartingPoint = value;
}
/** Fin accesseurs **/

int Cell::getX()
{
	return coordinates[0];
}

int Cell::getY()
{
	return coordinates[1];
}

void Cell::read(const QJsonObject &json)
{
	coordinates.clear();

	if (json["color"].toString() == "black") {
		color = Qt::black;
	}
	else if (json["color"].toString() == "blue") {
		color = Qt::blue;
	}
	else {
		color = QBrush();
	}
	coordinates.push_back(json["x"].toInt());
	coordinates.push_back(json["y"].toInt());
	blockViewLine = json["blockViewLine"].toBool();
	isWalkable = json["isWalkable"].toBool();
	isPlayerStartingPoint =json["isPlayerStartingPoint"].toBool();
	isEnemyStartingPoint = json["isEnemyStartingPoint"].toBool();
}

void Cell::write(QJsonObject &json) const
{
	if (color == Qt::black) {
		json["color"] = "black";
	}
	else if (color == Qt::blue) {
		json["color"] = "blue";
	}
	else {
		json["color"] = "any";
	}
	json["x"] = coordinates[0];
	json["y"] = coordinates[1];
	json["blockViewLine"] = blockViewLine;
	json["isWalkable"] = isWalkable;
	json["isPlayerStartingPoint"] = isPlayerStartingPoint;
	json["isEnemyStartingPoint"] = isEnemyStartingPoint;
}




