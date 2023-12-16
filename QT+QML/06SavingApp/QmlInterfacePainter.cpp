#include "QmlInterfacePainter.h"

QmlInterfacePainter::QmlInterfacePainter(QQmlApplicationEngine &engine, QObject *parent) :
    QObject(parent),
    m_engine(engine),
    m_QmlFactory(engine, parent)
{
    paintInterface();
    setUIText();
    connectQQuickItem();
}

void QmlInterfacePainter::paintInterface()
{
    int rowParentId = 0;
    int comboBoxIdA = 0;
    int comboBoxIdB = 1;
    int textFieldId = 2;
    int buttonId = 3;
    int textId = 4;

    m_QmlFactory.createColumn(m_columnQQuickItem);
    m_QmlFactory.createRow(m_columnQQuickItem, rowParentId, m_rowQQuickItem);
    m_QmlFactory.createRow(m_columnQQuickItem, rowParentId, m_rowQQuickItem);
    m_QmlFactory.createRow(m_columnQQuickItem, rowParentId, m_rowQQuickItem);
    m_QmlFactory.createRow(m_columnQQuickItem, rowParentId, m_rowQQuickItem);
    m_QmlFactory.createRow(m_columnQQuickItem, rowParentId, m_rowQQuickItem);
    m_QmlFactory.createRow(m_columnQQuickItem, rowParentId, m_rowQQuickItem);
    m_QmlFactory.createComboBox(m_rowQQuickItem, comboBoxIdA, m_comboBoxQQuickItem, UIDropDown::Language);
    m_QmlFactory.createComboBox(m_rowQQuickItem, comboBoxIdB, m_comboBoxQQuickItem, UIDropDown::Operation);
    m_QmlFactory.createComboBox(m_rowQQuickItem, comboBoxIdB, m_comboBoxQQuickItem, UIDropDown::Fund);
    m_QmlFactory.createTextField(m_rowQQuickItem, textFieldId, m_textFieldQQuickItem);
    m_QmlFactory.createButton(m_rowQQuickItem, buttonId, m_buttonQQuickItem, UIButton::Accept);
    m_QmlFactory.createTextElement(m_rowQQuickItem, textId, m_textQQuickItem);

    setUIText();
}

void QmlInterfacePainter::updateInterface(int uiFund)
{

}

void QmlInterfacePainter::handleButton()
{
    QQuickItem *senderItem = qobject_cast<QQuickItem*>(sender());
    m_QmlInterfaceController.handleButtonByType(senderItem);
}

void QmlInterfacePainter::handleComboBox()
{
    QQuickItem *senderItem = qobject_cast<QQuickItem*>(sender());
    m_QmlInterfaceController.handleComboBoxByType(senderItem);
}

void QmlInterfacePainter::handleTextField()
{
    QQuickItem *senderItem = qobject_cast<QQuickItem*>(sender());
    m_QmlInterfaceController.handleTextFieldInput(senderItem);
}

void QmlInterfacePainter::setUIText()
{
    std::map<Vocabulary, QString> word;
    QStringList modelListLanguage;
    QStringList modelListFinances;
    QStringList modelListItems;

    // Assuming that m_buttonQQuickItem and m_comboBoxQQuickItem are not null
    if (!m_buttonQQuickItem.empty() && !m_comboBoxQQuickItem.empty()) {
        word = m_language.getLanguage(Languages::English);

        modelListLanguage << word[Vocabulary::EnglishWord] << word[Vocabulary::SpanishWord];
        QQmlProperty(m_comboBoxQQuickItem.at(UIDropDown::Language), "model").write(QVariant::fromValue(modelListLanguage));

        modelListFinances << word[Vocabulary::DepositWord] << word[Vocabulary::WithdrawalWord];
        QQmlProperty(m_comboBoxQQuickItem.at(UIDropDown::Operation), "model").write(QVariant::fromValue(modelListFinances));

        modelListItems << word[Vocabulary::SavingsWord] << word[Vocabulary::HousingWord] << word[Vocabulary::FoodWord]
                << word[Vocabulary::TransportationWord] << word[Vocabulary::EntertainmentWord]
                << word[Vocabulary::TravelWord] << word[Vocabulary::ClothingWord] << word[Vocabulary::DebtsWord]
                << word[Vocabulary::CarWord];
        QQmlProperty(m_comboBoxQQuickItem.at(UIDropDown::Fund), "model").write(QVariant::fromValue(modelListItems));

        m_buttonQQuickItem.at(UIButton::Accept)->setProperty("text", word[Vocabulary::AcceptWord]);
    }
}

void QmlInterfacePainter::connectQQuickItem()
{
    for (QQuickItem* item : m_buttonQQuickItem) {
        connect(item, SIGNAL(clicked()), this, SLOT(handleButton()));
    }
    for (QQuickItem* item : m_comboBoxQQuickItem) {
        connect(item, SIGNAL(currentIndexChanged()), this, SLOT(handleComboBox()));
    }
    for (QQuickItem* item : m_textFieldQQuickItem) {
        connect(item, SIGNAL(textChanged()), this, SLOT(handleTextField()));
    }
}
