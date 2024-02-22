#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "SmileItem.h"

// �Զ��� Item
CustomItem::CustomItem(QGraphicsItem* parent)
	: QGraphicsRectItem(parent)
{
	// ���� - �߿�ɫ
	QPen p = pen();
	p.setWidth(2);
	p.setColor(QColor(0, 160, 230));

	setPen(p);
	// ��ˢ - ����ɫ
	setBrush(QColor(247, 160, 57));

	// ��ѡ�񡢿��ƶ�
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		if (event->modifiers() == Qt::ShiftModifier) {
			qDebug() << "Custom item left clicked with shift key.";
			// ѡ�� item
			setSelected(true);
		}
		else if (event->modifiers() == Qt::AltModifier) {

			qDebug() << "Custom item left clicked with alt key.";
			// ���� item ��С
			double radius = boundingRect().width() / 2.0;
			QPointF topLeft = boundingRect().topLeft();
			qDebug() << "WWW" << pos() << boundingRect();
			//m_centerPointF�� item���ε�ͼ������ ��scence�е�����
			m_centerPointF = QPointF(topLeft.x() + pos().x() + radius, topLeft.y() + pos().y() + radius);
			QPointF pos = event->scenePos();
			qDebug() << boundingRect() << radius << this->pos() << pos << event->pos();
			double dist = sqrt(pow(m_centerPointF.x() - pos.x(), 2) + pow(m_centerPointF.y() - pos.y(), 2));
			if (dist / radius > 0.8) { //�ж� �����קitem�ı߽� �Ƿ�Ϊ�߽�
				qDebug() << dist << radius << dist / radius;
				m_bResizing = true;
			}
			else {
				m_bResizing = false;
			}
		}
		else {
			qDebug() << "Custom item left clicked.";
			QGraphicsItem::mousePressEvent(event);//ʹ�ã�itemĬ�ϵĴ���ʽ
			event->accept();
		}
	}
	else if (event->button() == Qt::RightButton) {
		qDebug() << "Custom item right clicked.";
		event->ignore(); //���¼������ϲ㼴scence���� //���ȥ����һ�д��룬�������item��û�е���accept��ignore��Ĭ�����¼��������𣿴𰸣�Ĭ�� �¼��Ѿ���item�����ˡ�

	}
}

void CustomItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {
		QPointF pos = event->scenePos();
		double dist = sqrt(pow(m_centerPointF.x() - pos.x(), 2) + pow(m_centerPointF.y() - pos.y(), 2));
		setRect(m_centerPointF.x() - this->pos().x() - dist, //λ�úʹ�С //wgj ����ͼ�ε��������겻�䣬�˴��߼�����ͼ
			m_centerPointF.y() - this->pos().y() - dist,
			dist * 2, dist * 2);

	}
	else if (event->modifiers() != Qt::AltModifier) {
		qDebug() << "~~~" << this->scene()->sceneRect()<< this->pos() << this->scenePos();//Ϊʲô��ı䣿

		qDebug() << "Custom item moved.";

		QGraphicsItem::mouseMoveEvent(event);//�˺����ڲ����޸�scencePos

		qDebug() << "~~~" << this->scene()->sceneRect() << this->pos() << this->scenePos();//Ϊʲô��ı䣿

		qDebug() << "moved" << pos();
	}
}

void CustomItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {
		m_bResizing = false;
	}
	else {
		QGraphicsItem::mouseReleaseEvent(event);
	}
}

int CustomItem::type() const
{
	return UserType + 1;
}

// �Զ��� Scene
void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	qDebug() << "Custom scene clicked.";
	QGraphicsScene::mousePressEvent(event);//�˴������У�ͼ����ͼ����� ���¼�������ϵ
	if (!event->isAccepted()) {
		//��������item��û�д�����¼�
		if (event->button() == Qt::LeftButton) {
			// �� Scene �����һ���Զ��� item
			QPointF point = event->scenePos();
			CustomItem* item = new CustomItem();
			item->setRect(point.x() - 25, point.y() - 25, 60, 60);
			//qDebug() << item->pos()<<item->scenePos();
			addItem(item);
		}
		else if (event->button() == Qt::RightButton) {
			// ��������Ƿ��� item
			QGraphicsItem* itemToRemove = NULL;
			foreach(QGraphicsItem * item, items(event->scenePos())) {
				if (item->type() == QGraphicsItem::UserType + 1) {
					itemToRemove = item;
					break;
				}
			}
			// �� Scene ���Ƴ� item
			if (itemToRemove != NULL)
				removeItem(itemToRemove);
		}
	}
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	qDebug() << "Custom scene moved.";
	QGraphicsScene::mouseMoveEvent(event);
}

void CustomScene::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Backspace) {
		// �Ƴ�����ѡ�е� items
		qDebug() << "selected items " << selectedItems().size();
		while (!selectedItems().isEmpty()) {
			removeItem(selectedItems().front());
		}
	}
	else {
		QGraphicsScene::keyPressEvent(event);
	}
}
