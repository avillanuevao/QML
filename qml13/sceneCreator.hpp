#ifndef SCENECREATOR_H
#define SCENECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>

#include "rowLayoutCreator.hpp"
#include "buttonCreator.hpp"

class SceneCreator : public QObject {
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createScene(QString property, int height, int width);

private:
    QQmlApplicationEngine &engine;
    RowLayoutCreator rowLayoutCreator;
    ButtonCreator buttonCreator;
};

#endif
