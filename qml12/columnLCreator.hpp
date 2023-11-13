#ifndef COLUMNLCREATOR_H
#define COLUMNLCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QString>

class ColumnLCreator : public QObject {
    Q_OBJECT
public:
    explicit ColumnLCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createColumnL(QString property, int height, int width);

private:
    QQmlApplicationEngine &engine;
};

#endif
