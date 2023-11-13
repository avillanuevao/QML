#include "sceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine),
    rowLayoutCreator(engine),
    buttonCreator(engine)
{
    // Constructor implementation
}


void SceneCreator::createScene(QString property, int height, int width)
{
    rowLayoutCreator.createRowLayout("principalColumn", 30, 30);
    rowLayoutCreator.createRowLayout("principalColumn", 30, 30);
    QVector<QQuickItem*> itemID = rowLayoutCreator.getItemId();
    buttonCreator.createButton(itemID.at(0), "Software Team", 0);
    buttonCreator.createButton(itemID.at(0), "Hardware Team", 1);
    buttonCreator.createButton(itemID.at(1), "Villanueva", 2);
    buttonCreator.createButton(itemID.at(1), "Fernandez", 3);
    buttonCreator.createButton(itemID.at(1), "Moran", 4);

}
