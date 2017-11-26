#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include "drop.h"
#include "skills.h"

class Equipment : public Drop {
	private:
		int level;

		Skills *skills;

	public:
		Equipment();
		Equipment(Equipment const& equipement);

		~Equipment();
};

#endif // EQUIPEMENT_H
