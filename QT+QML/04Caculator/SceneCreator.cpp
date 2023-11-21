#include "SceneCreator.hpp"

SceneCreator::SceneCreator(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    engine(engine),
    m_columnLayoutCreator(engine),
    m_rowLayoutCreator(engine),
    m_buttonCreator(engine),
    m_textCreator(engine)
{
}

void SceneCreator::createScene()
{
    int numberColumns = 1;
    createColumn(numberColumns);
    int numberRows = 5;
    createRows(numberRows);
    QVector<QQuickItem*> itemIDRow = m_rowLayoutCreator.getItemId();
    QVector<int> numberTexts = {1, 0, 0, 0, 0};
    QVector<QString> textLabel = {"0"};
    createText(numberTexts, itemIDRow, textLabel);
    QVector<QString> textButton = {"7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "/", "Ce", "0", "=", "*"};
    QVector<int> numberButtons = {0, 4, 4, 4, 4};
    createButtons(numberButtons, itemIDRow, textButton);
}

void SceneCreator::createColumn(int numberColumns)
{
    for(int i = 0; i < numberColumns; i++)
    {
        m_columnLayoutCreator.createColumnLayout();
    }
}

void SceneCreator::createRows(int numberRows)
{
    QVector<QQuickItem*> itemID = m_columnLayoutCreator.getItemId();
    for(int i = 0; i < numberRows; i++)
    {
        m_rowLayoutCreator.createRowLayout(itemID.at(0));
    }
}

void SceneCreator::createText(QVector<int> numberTexts, QVector<QQuickItem*> itemID, QVector<QString> textLabel)
{
    for(int j = 0; j < itemID.size(); j++)
    {
        for(int i = 0; i < numberTexts.at(j); i++)
        {
            m_textCreator.createText(itemID.at(j), textLabel.at(0));
            textLabel.removeFirst();
        }
    }
}

void SceneCreator::updateText(QString text)
{
    m_textCreator.updateText(text);
}

void SceneCreator::createButtons(QVector<int> numberButtons, QVector<QQuickItem*> itemID, QVector<QString> textButton)
{
    for(int j = 0; j < itemID.size(); j++)
    {
        for(int i = 0; i < numberButtons.at(j); i++)
        {
            ButtonCreator* buttonCreator = new ButtonCreator(engine, this);
            QString label = textButton.at(0);
            buttonCreator->createButton(itemID.at(j), textButton.at(0), [this, buttonCreator, label]()
            {
                connect(buttonCreator, &ButtonCreator::buttonClicked, this, buttonHandlerSelector(label));
            });
            textButton.removeFirst();
        }
    }
}

void SceneCreator::handleButtonNumericClicked(int value)
{
    m_calculatorController.setNumericalInput(value);
    QString displayText = m_calculatorController.getNumericalInput();
    updateText(displayText);
}

void SceneCreator::handleButtonCalculatorComponentClicked(CalculatorComponent value)
{
    m_calculatorController.setOperationalInput(value);
    QString displayText = m_calculatorController.getOperationalInput();
    updateText(displayText);
}

std::function<void ()> SceneCreator::buttonHandlerSelector(QString input)
{
    if(m_calculatorComponentConverter.stringToCalculorComponent(input) == CalculatorComponent::EMPTY)
    {
        return std::bind(&SceneCreator::handleButtonNumericClicked, this, input.toInt());
    }else
    {
        return std::bind(&SceneCreator::handleButtonCalculatorComponentClicked, this, m_calculatorComponentConverter.stringToCalculorComponent(input));
    }
}


