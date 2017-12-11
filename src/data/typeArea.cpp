#include "inc/data/typeArea.h"

TypeArea::TypeArea() {
}

TypeArea::TypeArea(Form::Enum form, int size) : form(form), size(size) {
}

/** Accesseurs **/
Form::Enum TypeArea::getForm() const
{
	return form;
}

void TypeArea::setForm(const Form::Enum &value)
{
	form = value;
}

int TypeArea::getSize() const
{
	return size;
}

void TypeArea::setSize(int value)
{
	size = value;
}
/** Fin accesseurs **/

void TypeArea::read(const QJsonObject &json)
{
	form = Form::Enum(qRound(json["form"].toDouble()));
	size = json["size"].toInt();
}

void TypeArea::write(QJsonObject &json) const
{
	json["form"] = static_cast<int>(form);
	json["size"] = size;
}
