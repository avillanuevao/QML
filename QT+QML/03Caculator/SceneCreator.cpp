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


void SceneCreator::createScene(QVector<QString> textButton, int numberRows, QVector<int> numberButtons, QVector<std::function<void()>> functionVector)
{
    int numberColumns = 1;
    createColumn(numberColumns);
    createRows(numberRows);
    createText("Result");
    createButtons(numberButtons, textButton, functionVector);
}

void SceneCreator::handleButtonSolutionClicked()
{
    qDebug() << "handleButtonClicked";
}

void SceneCreator::handleButtonSevenClicked()
{
    emit buttonNumericClicked(7);
}

void SceneCreator::handleButtonEightClicked()
{
    emit buttonNumericClicked(8);
}

void SceneCreator::handleButtonNineClicked()
{
    emit buttonNumericClicked(9);
}

void SceneCreator::handleButtonAdditionClicked()
{
    emit buttonOperationalClicked(CalculatorComponent::ADD);
}

void SceneCreator::handleButtonFourClicked()
{
    emit buttonNumericClicked(4);
}

void SceneCreator::handleButtonFiveClicked()
{
    emit buttonNumericClicked(5);
}

void SceneCreator::handleButtonSixClicked()
{
    emit buttonNumericClicked(6);
}

void SceneCreator::handleButtonSubtractionClicked()
{
    emit buttonOperationalClicked(CalculatorComponent::SUBTRACT);

}

void SceneCreator::handleButtonOneClicked()
{
    emit buttonNumericClicked(1);
}

void SceneCreator::handleButtonTwoClicked()
{
    emit buttonNumericClicked(2);
}

void SceneCreator::handleButtonThreeClicked()
{
    emit buttonNumericClicked(3);
}

void SceneCreator::handleButtonDivisionClicked()
{
    emit buttonOperationalClicked(CalculatorComponent::DIVIDE);
}

void SceneCreator::handleButtonCeClicked()
{
    emit buttonOperationalClicked(CalculatorComponent::CLEAR);
}

void SceneCreator::handleButtonZeroClicked()
{
    emit buttonNumericClicked(0);
}

void SceneCreator::handleButtonEqualClicked()
{
    emit buttonOperationalClicked(CalculatorComponent::EQUAL);
}

void SceneCreator::handleButtonMultiplicationClicked()
{
    emit buttonOperationalClicked(CalculatorComponent::MULTIPLY);
}


void SceneCreator::removePreviousScene(QString property)
{
}

void SceneCreator::createScenery()
{

    QVector<QString> textButton = {"Solution", "7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "/", "Ce", "0", "=", "*"};
    int numberRows = 5;
    QVector<int> numberButtons = {1, 4, 4, 4, 4};
    QVector<std::function<void()>> functionVector;
    functionVector.append(std::bind(&SceneCreator::handleButtonSolutionClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonSevenClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonEightClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonNineClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonAdditionClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonFourClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonFiveClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonSixClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonSubtractionClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonOneClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonTwoClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonThreeClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonDivisionClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonCeClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonZeroClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonEqualClicked, this));
    functionVector.append(std::bind(&SceneCreator::handleButtonMultiplicationClicked, this));
    createScene(textButton, numberRows, numberButtons, functionVector);
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

void SceneCreator::updateText(QString text)
{
    textCreator.updateText(text);
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
