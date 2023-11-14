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
    buttonCreator.createButton(itemID.at(0), "Software Team", SLOT(handleButtonClick()));
    buttonCreator.createButton(itemID.at(0), "Hardware Team", SLOT(handleButtonClick()));
    buttonCreator.createButton(itemID.at(1), "Villanueva", SLOT(handleButtonClick()));
    buttonCreator.createButton(itemID.at(1), "Fernandez", SLOT(handleButtonClick()));
    buttonCreator.createButton(itemID.at(1), "Moran", SLOT(handleButtonClick()));
}
