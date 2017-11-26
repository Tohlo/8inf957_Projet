#include <QDir>
#include <QJsonDocument>

#include "inc/map/map.h"


Map::Map() :
    grid(std::vector<std::vector<Cell *> >()), groups(std::vector<Group *>()),
    length(0), width(0)
{

}

Map::Map(std::vector<Group *> groups, int length, int width, int nbGroups) :
    grid(std::vector<std::vector<Cell *> >()), groups(groups),
	length(length), width(width)
{
	for(int i = 0; i < length; i++) {
		std::vector<Cell *> line = std::vector<Cell *>();

		for(int j = 0; j < width; j++) {
			line.push_back(new Cell(i,j));
		}

		grid.push_back(line);
	}

	placeGroups(nbGroups);

}

Map::Map(const Map &value) :
	grid(value.grid), groups(value.groups), length(value.length), width(value.width)
{

}


Map::~Map() {

}

/** Accesseurs **/
std::vector<std::vector<Cell *> > Map::getGrid() const
{
	return grid;
}

void Map::setGrid(const std::vector<std::vector<Cell *> > &value)
{
	grid = value;
}

std::vector<Group *> Map::getGroups() const
{
	return groups;
}

void Map::setGroups(const std::vector<Group *> &value)
{
	groups = value;
}

int Map::getLength() const
{
	return length;
}

void Map::setLength(int value)
{
	length = value;
}

int Map::getWidth() const
{
	return width;
}

void Map::setWidth(int value)
{
	width = value;
}
/** Fin accesseurs **/

void Map::placeGroups(int nbGroups) {
	for (int k=0; k<nbGroups; k++) {
		if (!groups.empty()) {
			Group *ng = groups[rand() % groups.size()];
			int i = 0;

			do {
				++i;
				ng->setOffset({rand() % (length - ng->getLength()), rand() % (width - ng->getWidth())});

				if (isAvailable(ng)) {
					for (Cell *ngCell: ng->getCellVector()) {
						Cell *cell = new Cell(*ngCell);
						cell->setCoordinates({ng->getXOffset() + ngCell->getX(), ng->getYOffset() + ngCell->getY()});

						grid[cell->getX()][cell->getY()] = cell;
					}
					break;
				}

			} while (i<length*width/2);
		}
    }
}



bool Map::isAvailable(Group * gp) {
	for(Cell *gpCell : gp->getCellVector()) {
		if (grid[gp->getXOffset() + gpCell->getX()][gp->getYOffset() + gpCell->getY()]->getColor() != QBrush()) {
			return false;
		}
	}

	return true;
}
