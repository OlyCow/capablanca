#ifndef CHECKBOXGROUP_H
#define CHECKBOXGROUP_H

#include <QObject>
#include <QButtonGroup>
#include "checkboxgroupfilter.h"

class CheckboxGroup : public QButtonGroup
{
	Q_OBJECT

public:
	CheckboxGroup(QObject* parent = 0);
	~CheckboxGroup();

	void addButton(QAbstractButton* button, int id = -1);

private:
	CheckboxGroupFilter* unchecker;
};

#endif // CHECKBOXGROUP_H
