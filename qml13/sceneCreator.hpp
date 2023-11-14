#ifndef SCENECREATOR_H
#define SCENECREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QPair>

#include "rowLayoutCreator.hpp"
#include "buttonCreator.hpp"

class SceneCreator : public QObject {
    Q_OBJECT
public:
    explicit SceneCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    void createSceneryA();

    Q_INVOKABLE void createScene(QString property, QVector<QString> textButton, int numberRows, QVector<int> numberButtons, QVector<std::function<void()>> functionVector);
public slots:
    void handleButtonClicked();
    void handleButtonSoftwareTeam();
    void handleButtonHardwareTeam();
private:
    QQmlApplicationEngine &engine;
    RowLayoutCreator rowLayoutCreator;
    ButtonCreator buttonCreator;
    void removePreviousScene(QString property);
    void createSceneryB();
    void createRows(QString property, int numberRows);
    void createButtons(QString property, QVector<int> numberButtons, QVector<QString> textButton, QVector<std::function<void ()>> functionVector);
};

#endif
