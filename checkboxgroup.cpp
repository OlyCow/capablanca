#include "checkboxgroup.h"

CheckboxGroup::CheckboxGroup(QObject* parent) :
	QButtonGroup(parent),
	unchecker(new CheckboxGroupFilter(parent, this))
{
}

CheckboxGroup::~CheckboxGroup()
{
	delete unchecker;
}

void CheckboxGroup::addButton(QAbstractButton* button, int id)
{
	button->installEventFilter(unchecker);
	QButtonGroup::addButton(button, id);
}
