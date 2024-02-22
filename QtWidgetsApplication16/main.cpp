#include <QApplication>
#include <QGraphicsView>
#include "SmileItem.h"
#include <QDebug>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	// 创建 item
	CustomItem* pItem = new CustomItem();
	pItem->setRect(100, 20, 60, 60);
	qDebug() << pItem->scenePos();

	//测试
	CustomItem* pItem1 = new CustomItem();
	pItem1->setRect(100, 20, 60, 60);
	pItem1->setRotation(45); //旋转45°


	// 将 item 添加至场景中
	CustomScene scene;
	scene.setSceneRect(0, 0, 400, 300);
	scene.addItem(pItem);
	scene.addItem(pItem1);//test
	qDebug()<< scene.sceneRect();

	// 为视图设置场景
	QGraphicsView view;
	view.setScene(&scene);
	view.show();
	view.resize(400, 300);

	return a.exec();
}
