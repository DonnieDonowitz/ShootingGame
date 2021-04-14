#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("Images/bullett-20-22.png"));
    setRotation(90);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding = collidingItems();
    for (int i = 0, n = colliding.size(); i < n; ++i) {
        if (typeid(*(colliding[i])) == typeid(Enemy)) {
            game->score->increase();
            scene()->removeItem(colliding[i]);
            scene()->removeItem(this);
            delete colliding[i];
            delete this;
            return;
        }
    }
    setPos(x(), y() - 10);
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
