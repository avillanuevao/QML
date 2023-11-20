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

void SceneCreator::createScene()
{
    int numberColumns = 1;
    createColumn(numberColumns);
    int numberRows = 5;
    createRows(numberRows);
    QVector<QQuickItem*> itemIDRow = rowLayoutCreator.getItemId();
    QVector<int> numberTexts = {1, 0, 0, 0, 0};
    QVector<QString> textLabel = {"0"};
    createText(numberTexts, itemIDRow, textLabel);
    QVector<QString> textButton = {"", "7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "/", "Ce", "0", "=", "*"};
    QVector<int> numberButtons = {1, 4, 4, 4, 4};
    createButtons(numberButtons, itemIDRow, textButton);
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

void SceneCreator::createText(QVector<int> numberTexts, QVector<QQuickItem*> itemID, QVector<QString> textLabel)
{
    for(int j = 0; j < itemID.size(); j++)
    {
        for(int i = 0; i < numberTexts.at(j); i++)
        {
            textCreator.createText(itemID.at(j), textLabel.at(0));
            textLabel.removeFirst();
        }
    }
}

void SceneCreator::createButtons(QVector<int> numberButtons, QVector<QQuickItem*> itemID, QVector<QString> textButton)
{
    for(int j = 0; j < itemID.size(); j++)
    {
        for(int i = 0; i < numberButtons.at(j); i++)
        {
            ButtonCreator* buttonCreator = new ButtonCreator(engine, this);
            QString label = textButton.at(0);
            buttonCreator->createButton(itemID.at(j), textButton.at(0), SLOT(handleButtonClick()), [this, buttonCreator, label]()
            {
                std::function<void ()> function = buttonHandlerSelector(label);
                connect(buttonCreator, &ButtonCreator::buttonClicked, this, function);
            });
            textButton.removeFirst();
        }
    }
}

std::function<void ()> SceneCreator::buttonHandlerSelector(QString input)
{
    if(stringToCalculorComponent(input) == CalculatorComponent::EMPTY)
    {
        return buttonHandlerSelected(input);
    }else
    {
        return buttonHandlerSelected(stringToCalculorComponent(input));
    }
}

std::function<void ()> SceneCreator::buttonHandlerSelected(QString input)
{
    return std::bind(&SceneCreator::handleButtonNumericClicked, this, input.toInt());
}

std::function<void ()> SceneCreator::buttonHandlerSelected(CalculatorComponent input)
{
    return std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, input);

}

CalculatorComponent SceneCreator::stringToCalculorComponent(QString input)
{
    if(input == "+")
    {
        return CalculatorComponent::ADD;
    }else if(input == "-")
    {
        return CalculatorComponent::SUBTRACT;
    }else if(input == "/")
    {
        return CalculatorComponent::DIVIDE;
    }else if(input == "*")
    {
        return CalculatorComponent::MULTIPLY;
    }else if(input == "Ce")
    {
        return CalculatorComponent::CLEAR;
    }else if(input == "=")
    {
        return CalculatorComponent::EQUAL;
    }else
    {
        return CalculatorComponent::EMPTY;
    }

}

