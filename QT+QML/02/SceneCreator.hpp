#ifndef SCENECREATOR_H
#define SCENECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QPair>

#include "RowLayoutCreator.hpp"
#include "ButtonCreator.hpp"
#include "ButtonSlot.hpp"

class SceneCreator : public QObject {
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createScene(QString property, QVector<QString> textButton, int numberRows, QVector<int> numberButtons, QVector<std::function<void ()> > functionVector);
public slots:
    void handleNameButtonClick();
    void handleIdButtonClick();
private:
    QQmlApplicationEngine &engine;
    RowLayoutCreator rowLayoutCreator;
    ButtonCreator buttonCreator;
    void removePreviousScene(QString property);
    void createRows(QString property, int numberRows);
    void createButtons(QString property, QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void ()> > functionVector);
};

#endif
