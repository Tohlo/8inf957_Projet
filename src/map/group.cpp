#include <QJsonArray>

#include "inc/map/group.h"

Group::Group() :
	cellVector(std::vector<Cell *>()), offset({0, 0})
{



}

Group::Group(std::vector<Cell *> cellVector) :
	cellVector(cellVector), offset({0, 0})
{

}

Group::Group(Group const& value) :
	cellVector(value.cellVector), offset(value.offset)
{


}

Group::~Group() {
	for (Cell *cell : cellVector) {
		delete cell;
	}

	cellVector.clear();
}

/** Accesseurs **/
std::vector<int> Group::getOffset() const
{
    return offset;
}

void Group::setOffset(const std::vector<int> &value)
{
    offset = value;
}

std::vector<Cell *> Group::getCellVector() const
{
    return cellVector;
}

void Group::setCellVector(const std::vector<Cell *> &value)
{
    cellVector = value;
}
/** Fin accesseurs **/

int Group::getLength() {
    int max = 0;

	for (Cell *cell : cellVector) {
		if (cell->getX() > max) {
            max = cell->getX();
        }
    }

    return max;
}

int Group::getWidth() {
    int max = 0;
	for(Cell *cell : cellVector) {
		if (cell->getY() > max) {
			max = cell->getY();
        }
    }

    return max;
}

int Group::getXOffset()
{
    return offset[0];
}

int Group::getYOffset()
{
	return offset[1];
}

void Group::toOrigin()
{
	int minX = std::numeric_limits<int>::max();
	int minY = std::numeric_limits<int>::max();

	for (Cell *cell : cellVector) {
		if (cell->getX() < minX) {
			minX = cell->getX();
		}

		if (cell->getY() < minY) {
			minY = cell->getY();
		}
	}

	for (Cell *cell : cellVector) {
		cell->setCoordinates({cell->getX() - minX, cell->getY() - minY});
	}
}

void Group::read(const QJsonObject &json)
{
	cellVector.clear();

    QJsonArray cellArray = json["cellVector"].toArray();
    for (int i = 0; i < cellArray.size(); ++i) {
        QJsonObject cellObject = cellArray[i].toObject();

        Cell *cell = new Cell();
        cell->read(cellObject);
        cellVector.push_back(cell);
    }
}

void Group::write(QJsonObject &json) const
{
    QJsonArray cellArray;
    foreach (const Cell *cell, cellVector) {
        QJsonObject cellObject;
        cell->write(cellObject);
        cellArray.push_back(cellObject);
    }
    json["cellVector"] = cellArray;
}
