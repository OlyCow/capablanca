#include "checkboxgroupfilter.h"

CheckboxGroupFilter::CheckboxGroupFilter(QObject* parent, QButtonGroup* group_parent) :
	QObject(parent),
	group(group_parent)
{
}

CheckboxGroupFilter::~CheckboxGroupFilter()
{
	delete group;
}

// TODO: Make this have only one exit point :P
bool CheckboxGroupFilter::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress) {
		QAbstractButton* button = static_cast<QAbstractButton*>(obj);
		if (button->isChecked()) {
			group->setExclusive(false);
			button->setChecked(false);
			group->setExclusive(true);
			return true;
		}
	}
	return false;
}
