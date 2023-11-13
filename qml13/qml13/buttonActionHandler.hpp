#ifndef BUTTONACTIONHANDLER_H
#define BUTTONACTIONHANDLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>

class ButtonActionHandler : public QObject {
    Q_OBJECT
public:
    void handleButtonSoftware();
    void handleButtonHardware();
    void handleButtonVillanueva();
    void handleButtonFernandez();
    void handleButtonMoran();
};

#endif
