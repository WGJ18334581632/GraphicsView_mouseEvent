#include <QApplication>
#include <QGraphicsView>
#include "SmileItem.h"
#include <QDebug>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	// ���� item
	CustomItem* pItem = new CustomItem();
	pItem->setRect(100, 20, 60, 60);
	qDebug() << pItem->scenePos();

	//����
	CustomItem* pItem1 = new CustomItem();
	pItem1->setRect(100, 20, 60, 60);
	pItem1->setRotation(45); //��ת45��


	// �� item �����������
	CustomScene scene;
	scene.setSceneRect(0, 0, 400, 300);
	scene.addItem(pItem);
	scene.addItem(pItem1);//test
	qDebug()<< scene.sceneRect();

	// Ϊ��ͼ���ó���
	QGraphicsView view;
	view.setScene(&scene);
	view.show();
	view.resize(400, 300);

	return a.exec();
}
