#ifndef CHECKBOXGROUPFILTER_H
#define CHECKBOXGROUPFILTER_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QAbstractButton>
#include <QButtonGroup>

class CheckboxGroupFilter : public QObject
{
	Q_OBJECT

public:
	CheckboxGroupFilter(QObject* parent, QButtonGroup* group_parent);
	~CheckboxGroupFilter();

protected:
	QButtonGroup* group;

	bool eventFilter(QObject *obj, QEvent *event);
};

#endif // CHECKBOXGROUPFILTER_H
