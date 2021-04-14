#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy(QGraphicsItem *parent = 0);
 
public slots:
    void move();
};
