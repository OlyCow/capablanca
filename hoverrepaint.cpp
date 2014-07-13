#include "hoverrepaint.h"

HoverRepaint::HoverRepaint(QObject* parent):
	QObject(parent)
{
}

bool HoverRepaint::eventFilter(QObject* obj, QEvent* event)
{
	bool did_process = false;
	switch (event->type()) {
		case QEvent::HoverEnter :
		case QEvent::HoverMove :
		case QEvent::HoverLeave :
			QLineEdit* edit = static_cast<QLineEdit*>(obj);
			edit->repaint();
			did_process = true;
			break;
	}
	return did_process;
}
