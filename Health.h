#pragma once

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
    Q_OBJECT

public:
    Health(QGraphicsItem *parent = 0);
    void decrease();
    int getHealth();

private:
    int health;
};
