#ifndef BUTTONCREATOR_H
#define BUTTONCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>

class ButtonCreator : public QObject {
    Q_OBJECT
public:
    explicit ButtonCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createButton(QQuickItem* property, QString textButton, const char *slotFunction, const std::function<void()> &connectFunction);
signals:
    void buttonClicked();
public slots:
    void handleButtonClick();
private:
    QQmlApplicationEngine &engine;
};

#endif
