#include "SceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine),
    rowLayoutCreator(engine),
    buttonCreator(engine)
{
    // Constructor implementation
}


void SceneCreator::createScene(QString property, QVector<QString> textButton, int numberRows, QVector<int> numberButtons, QVector<std::function<void()>> functionVector)
{
//    QVector<std::function<void()>> functionVector;
//    functionVector.append(std::bind(&SceneCreator::handleNameButtonClick, this));
//    functionVector.append(std::bind(&SceneCreator::handleIdButtonClick, this));
    createRows(property, numberRows);
    createButtons(property, numberButtons, textButton, functionVector);
}

void SceneCreator::removePreviousScene(QString property)
{
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->property(property.toStdString().c_str()).value<QObject*>();

    if(qmlObject)
    {
        QQuickItem *object = qobject_cast<QQuickItem*>(qmlObject);

        if(object)
        {
            QList<QQuickItem *> childItems = object->childItems();
            for (QQuickItem *child : childItems)
            {
                child->deleteLater();
            }
        }
    }
    rowLayoutCreator.resetItemId();
}

void SceneCreator::createRows(QString property, int numberRows)
{
    for(int i = 0; i < numberRows; i++)
    {
        rowLayoutCreator.createRowLayout(property);
    }
}

void SceneCreator::createButtons(QString property, QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void()>> functionVector)
{
    QVector<QQuickItem*> itemID = rowLayoutCreator.getItemId();
    for(int j = 0; j < itemID.size(); j++)
    {
        for(int i = 0; i < numberButtons.at(j); i++)
        {
            ButtonCreator* buttonCreator = new ButtonCreator(engine, this);
            std::function<void()> buttonFunction = functionVector.at(0);
            buttonCreator->createButton(itemID.at(j), textButton.at(0), SLOT(handleButtonClick()), [this, buttonFunction, buttonCreator]()
            {
                connect(buttonCreator, &ButtonCreator::buttonClicked, this, buttonFunction);
            });
            textButton.removeFirst();
            functionVector.removeFirst();
        }
    }
}

void SceneCreator::handleNameButtonClick()
{
    qDebug() << "handleNameButtonClick";

}

void SceneCreator::handleIdButtonClick()
{
    qDebug() << "handleIdButtonClick";
}
