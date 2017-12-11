#ifndef TYPELAUNCH_H
#define TYPELAUNCH_H

#include "inc/data/data.h"

class TypeArea
{
	private:
		Form::Enum form;
		int size;

	public:
		TypeArea();
		TypeArea(Form::Enum form, int size);

		/** Accesseurs **/
		Form::Enum getForm() const;
		void setForm(const Form::Enum &value);

		int getSize() const;
		void setSize(int value);
		/** Fin accesseurs **/

		void read(const QJsonObject &json);
		void write(QJsonObject &json) const;
};

#endif // TYPELAUNCH_H
