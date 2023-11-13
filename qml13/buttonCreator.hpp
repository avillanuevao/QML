#ifndef BUTTONCREATOR_H
#define BUTTONCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>

class ButtonCreator : public QObject {
    Q_OBJECT
public:
    explicit ButtonCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createButton(QQuickItem* property, int height, int width);

private:
    QQmlApplicationEngine &engine;
};

#endif
