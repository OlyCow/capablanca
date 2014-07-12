#include "hoverrepaint.h"

HoverRepaint::HoverRepaint()
{
}

bool HoverRepaint::repaintLineEdit(QLineEdit* obj, QEvent* event)
{
	switch (event->type()) {
		case QEvent::HoverEnter :
		case QEvent::HoverMove :
		case QEvent::HoverLeave :
			obj->repaint();
			break;
	}
	return true;
}
