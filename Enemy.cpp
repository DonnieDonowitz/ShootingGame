#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    int randomNumber = rand() % 700;
    setPos(randomNumber, 0);

    setPixmap(QPixmap("Images/enemy-50-40.png"));
    setTransformOriginPoint(50, 50);
    setRotation(180);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y() + 5);
    if (pos().y() > 600)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}