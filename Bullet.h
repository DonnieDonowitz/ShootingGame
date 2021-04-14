#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet(QGraphicsItem *parent = 0);
 
public slots:
    void move();
};
