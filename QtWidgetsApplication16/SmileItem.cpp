#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "SmileItem.h"

// 自定义 Item
CustomItem::CustomItem(QGraphicsItem* parent)
	: QGraphicsRectItem(parent)
{
	// 画笔 - 边框色
	QPen p = pen();
	p.setWidth(2);
	p.setColor(QColor(0, 160, 230));

	setPen(p);
	// 画刷 - 背景色
	setBrush(QColor(247, 160, 57));

	// 可选择、可移动
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		if (event->modifiers() == Qt::ShiftModifier) {
			qDebug() << "Custom item left clicked with shift key.";
			// 选中 item
			setSelected(true);
		}
		else if (event->modifiers() == Qt::AltModifier) {

			qDebug() << "Custom item left clicked with alt key.";
			// 重置 item 大小
			double radius = boundingRect().width() / 2.0;
			QPointF topLeft = boundingRect().topLeft();
			qDebug() << "WWW" << pos() << boundingRect();
			//m_centerPointF是 item矩形的图形中心 在scence中的坐标
			m_centerPointF = QPointF(topLeft.x() + pos().x() + radius, topLeft.y() + pos().y() + radius);
			QPointF pos = event->scenePos();
			qDebug() << boundingRect() << radius << this->pos() << pos << event->pos();
			double dist = sqrt(pow(m_centerPointF.x() - pos.x(), 2) + pow(m_centerPointF.y() - pos.y(), 2));
			if (dist / radius > 0.8) { //判断 鼠标拖拽item的边界 是否为边界
				qDebug() << dist << radius << dist / radius;
				m_bResizing = true;
			}
			else {
				m_bResizing = false;
			}
		}
		else {
			qDebug() << "Custom item left clicked.";
			QGraphicsItem::mousePressEvent(event);//使用：item默认的处理方式
			event->accept();
		}
	}
	else if (event->button() == Qt::RightButton) {
		qDebug() << "Custom item right clicked.";
		event->ignore(); //把事件交给上层即scence处理 //如果去掉这一行代码，即：如果item中没有调用accept和ignore，默认是事件接收了吗？答案：默认 事件已经被item接收了。

	}
}

void CustomItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {
		QPointF pos = event->scenePos();
		double dist = sqrt(pow(m_centerPointF.x() - pos.x(), 2) + pow(m_centerPointF.y() - pos.y(), 2));
		setRect(m_centerPointF.x() - this->pos().x() - dist, //位置和大小 //wgj 保持图形的中心坐标不变，此处逻辑见下图
			m_centerPointF.y() - this->pos().y() - dist,
			dist * 2, dist * 2);

	}
	else if (event->modifiers() != Qt::AltModifier) {
		qDebug() << "~~~" << this->scene()->sceneRect()<< this->pos() << this->scenePos();//为什么会改变？

		qDebug() << "Custom item moved.";

		QGraphicsItem::mouseMoveEvent(event);//此函数内部会修改scencePos

		qDebug() << "~~~" << this->scene()->sceneRect() << this->pos() << this->scenePos();//为什么会改变？

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

// 自定义 Scene
void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	qDebug() << "Custom scene clicked.";
	QGraphicsScene::mousePressEvent(event);//此处必须有：图形视图框架中 的事件传播体系
	if (!event->isAccepted()) {
		//继续处理：item中没有处理的事件
		if (event->button() == Qt::LeftButton) {
			// 在 Scene 上添加一个自定义 item
			QPointF point = event->scenePos();
			CustomItem* item = new CustomItem();
			item->setRect(point.x() - 25, point.y() - 25, 60, 60);
			//qDebug() << item->pos()<<item->scenePos();
			addItem(item);
		}
		else if (event->button() == Qt::RightButton) {
			// 检测光标下是否有 item
			QGraphicsItem* itemToRemove = NULL;
			foreach(QGraphicsItem * item, items(event->scenePos())) {
				if (item->type() == QGraphicsItem::UserType + 1) {
					itemToRemove = item;
					break;
				}
			}
			// 从 Scene 上移除 item
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
		// 移除所有选中的 items
		qDebug() << "selected items " << selectedItems().size();
		while (!selectedItems().isEmpty()) {
			removeItem(selectedItems().front());
		}
	}
	else {
		QGraphicsScene::keyPressEvent(event);
	}
}
