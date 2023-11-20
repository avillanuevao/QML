#ifndef TEXTCREATOR_H
#define TEXTCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>
#include <QQuickWindow>

class TextCreator : public QObject {
    Q_OBJECT
public:
    explicit TextCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createText(QQuickItem* property, QString text);
    QQuickItem* getTextId();
    void updateText(QString newText);
private:
    QQmlApplicationEngine &engine;
    QQuickItem* textId;
};

#endif
