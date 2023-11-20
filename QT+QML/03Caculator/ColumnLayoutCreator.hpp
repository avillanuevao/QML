#ifndef COLUMNLAYOUTCREATOR_H
#define COLUMNLAYOUTCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QQuickItem>
#include <QString>
#include <QVector>

class ColumnLayoutCreator : public QObject {
    Q_OBJECT
public:
    explicit ColumnLayoutCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createColumnLayout();
    QVector<QQuickItem*> getItemId();
    void resetItemId();

private:
    QQmlApplicationEngine &engine;
    QVector<QQuickItem*> itemID;
};

#endif
