#ifndef ROWLAYOUTCREATOR_H
#define ROWLAYOUTCREATOR_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QQuickItem>
#include <QString>
#include <QVector>

class RowLayoutCreator : public QObject {
    Q_OBJECT
public:
    explicit RowLayoutCreator(QQmlApplicationEngine &engine, QObject *parent = nullptr);
    Q_INVOKABLE void createRowLayout(QQuickItem *property);
    QVector<QQuickItem*> getItemId();
    void resetItemId();

private:
    QQmlApplicationEngine &engine;
    QVector<QQuickItem*> itemID;
};

#endif
