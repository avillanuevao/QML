#ifndef QMLINTERFACEPAINTER_H
#define QMLINTERFACEPAINTER_H

#include <QObject>
#include "QmlFactory.h"
#include "QmlInterfaceController.h"
#include "Language.hpp"


class QmlInterfacePainter : public QObject
{
    Q_OBJECT
public:
    QmlInterfacePainter(QQmlApplicationEngine &engine, QObject *parent);
    void paintInterface();
    void updateInterface(int uiFund);
public slots:
    void handleButton();
    void handleComboBox();
    void handleTextField();
private:
    QQmlApplicationEngine &m_engine;
    QmlFactory m_QmlFactory;
    QmlInterfaceController m_QmlInterfaceController;
    WordBook m_language;
    QVector<QQuickItem*> m_columnQQuickItem;
    QVector<QQuickItem*> m_rowQQuickItem;
    QVector<QQuickItem*> m_textFieldQQuickItem;
    QVector<QQuickItem*> m_textQQuickItem;
    QVector<QQuickItem*> m_buttonQQuickItem;
    QVector<QQuickItem*> m_comboBoxQQuickItem;
    void setUIText();
    void connectQQuickItem();
};

#endif // QMLINTERFACEPAINTER_H
