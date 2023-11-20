#include "SceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine),
    columnLayoutCreator(engine),
    rowLayoutCreator(engine),
    buttonCreator(engine),
    textCreator(engine)
{
    // Constructor implementation
}

void SceneCreator::createScene(int numberColumns, int numberRows, QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void()>> functionVector)
{
    createColumn(numberColumns);
    createRows(numberRows);
    createText("0");
    createButtons(numberButtons, textButton, functionVector);
}

void SceneCreator::scenaryDefinition()
{

    QVector<QString> textButton = {"", "7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "/", "Ce", "0", "=", "*"};
    int numberColumns = 1;
    int numberRows = 5;
    QVector<int> numberButtons = {1, 4, 4, 4, 4};
    QVector<std::function<void()>> functionVector;
    functionVector.append(std::bind(&SceneCreator::handleButtonSolutionClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 7));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 8));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 9));
    functionVector.append(std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, CalculatorComponent::ADD));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 4));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 5));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 6));
    functionVector.append(std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, CalculatorComponent::SUBTRACT));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 1));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 2));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 3));
    functionVector.append(std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, CalculatorComponent::DIVIDE));
    functionVector.append(std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, CalculatorComponent::CLEAR));
    functionVector.append(std::bind(&SceneCreator::handleButtonNumericClicked, this, 0));
    functionVector.append(std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, CalculatorComponent::EQUAL));
    functionVector.append(std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, CalculatorComponent::MULTIPLY));
    createScene(numberColumns, numberRows, numberButtons, textButton, functionVector);
}

void SceneCreator::updateText(QString text)
{
    textCreator.updateText(text);
}

void SceneCreator::handleButtonNumericClicked(int value)
{
    emit buttonNumericClicked(value);
}

void SceneCreator::handleButtonCalculatorComponentClicked(CalculatorComponent value)
{
    emit buttonOperationalClicked(value);
}

void SceneCreator::handleButtonSolutionClicked()
{
    qDebug() << "handleButtonClicked ";
}

void SceneCreator::createColumn(int numberColumns)
{
    for(int i = 0; i < numberColumns; i++)
    {
        columnLayoutCreator.createColumnLayout();
    }
}

void SceneCreator::createRows(int numberRows)
{
    QVector<QQuickItem*> itemID = columnLayoutCreator.getItemId();
    for(int i = 0; i < numberRows; i++)
    {
        rowLayoutCreator.createRowLayout(itemID.at(0));
    }
}

void SceneCreator::createText(QString text)
{
    QVector<QQuickItem*> itemID = rowLayoutCreator.getItemId();
    textCreator.createText(itemID.at(0), text);
}

void SceneCreator::createButtons(QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void()>> functionVector)
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
