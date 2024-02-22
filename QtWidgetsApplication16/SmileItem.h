#ifndef CUSTOM_ITEM_H
#define CUSTOM_ITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

//QGraphicsScene����QGraphicsItem������/ѡ��/�ƶ�/����/ɾ����
// �Զ��� Item
class CustomItem : public QGraphicsRectItem
{
public:
	explicit CustomItem(QGraphicsItem* parent = 0);
protected:
	// Shift+���������ѡ��  Alt��׼������
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	// Alt+��ק����������  �ƶ�
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	// ʹitem��ʹ��qgraphicsitem_cast
	int type() const;
private:
	QPointF m_centerPointF;
	bool m_bResizing;
};

// �Զ��� Scene
class CustomScene : public QGraphicsScene
{
protected:
	// ��������item  �Ҽ����Ƴ�item
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	// Backspace���Ƴ�item
	void keyPressEvent(QKeyEvent* event);
};

#endif // CUSTOM_ITEM_H
