#ifndef HOVERREPAINT_H
#define HOVERREPAINT_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QLineEdit>

class HoverRepaint : public QObject
{
	Q_OBJECT

public:
	HoverRepaint(QObject *parent);

private:
	bool eventFilter(QObject* obj, QEvent* event);
};

#endif // HOVERREPAINT_H
