#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include <QJsonObject>

#include "inc/serializer/serializable.h"
#include "cell.h"

class Group : public Serializable {
	private:
		std::vector<Cell *> cellVector;
		std::vector<int> offset;

	public:
		Group();
		Group(std::vector<Cell *> cellVector);
		Group(Group const& value);
		virtual ~Group();

		/** Début accesseurs **/
		std::vector<int> getOffset() const;
		void setOffset(const std::vector<int> &value);

		std::vector<Cell *> getCellVector() const;
		void setCellVector(const std::vector<Cell *> &value);
		/** Fin accesseurs **/

		int getLength();
		int getWidth();
		int getXOffset();
		int getYOffset();

		void toOrigin();

		/** Serializable **/
		void read(const QJsonObject &json);
		void write(QJsonObject &json) const;
		/** Serializable **/
};

#endif // GROUP_H
