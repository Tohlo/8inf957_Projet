#ifndef MAP_H
#define MAP_H

#include <vector>

#include "group.h"

class Map {
	private:
		std::vector<std::vector<Cell *> > grid;
		std::vector<Group *> groups;
		int length;
		int width;

	public:
		Map();
        Map(std::vector<Group *> groups, int length, int width, int nbGroups);
		Map(Map const& value);
		virtual ~Map();

		/** Début accesseurs **/
		std::vector<std::vector<Cell *> > getGrid() const;
		void setGrid(const std::vector<std::vector<Cell *> > &value);

		std::vector<Group *> getGroups() const;
		void setGroups(const std::vector<Group *> &value);

		int getLength() const;
		void setLength(int value);

		int getWidth() const;
		void setWidth(int value);
		/** Fin accesseurs **/

		void placeGroups(int nbGroups);
		bool isAvailable(Group * gp);
};

#endif // MAP_H
