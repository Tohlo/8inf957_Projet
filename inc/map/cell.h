#ifndef CELL_H
#define CELL_H

#include <vector>
#include <QBrush>
#include <QJsonObject>

#include "inc/serializer/serializable.h"

class Cell : public Serializable {
	private:
		QBrush color;
		std::vector<int> coordinates;

		bool blockViewLine;
		bool isWalkable;
		bool isPlayerStartingPoint;
		bool isEnemyStartingPoint;

	public:
		Cell();
		Cell(int x,int y);
		Cell(Cell const& value);
		virtual ~Cell();

		/** Début accesseurs **/
		QBrush getColor() const;
		void setColor(const QBrush &value);

		std::vector<int> getCoordinates() const;
		void setCoordinates(const std::vector<int> &value);

		bool getBlockViewLine() const;
		void setBlockViewLine(bool value);

		bool getIsWalkable() const;
		void setIsWalkable(bool value);

		bool getIsPlayerStartingPoint() const;
		void setIsPlayerStartingPoint(bool value);

		bool getIsEnemyStartingPoint() const;
		void setIsEnemyStartingPoint(bool value);
		/** Fin accesseurs **/

		int getX();
		int getY();

		void read(const QJsonObject &json);
		void write(QJsonObject &json) const;
};

#endif // CELL_H
