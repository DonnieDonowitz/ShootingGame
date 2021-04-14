#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent), 
    bulletSound(new QMediaPlayer)
{
    bulletSound->setMedia(QUrl("Sounds/bullet.wav"));
    setPixmap(QPixmap("Images/player-50-40.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        setPos(x() - 10, y());
        break;
    case Qt::Key_Right:
        setPos(x() + 10, y());
        break;
    case Qt::Key_Space:
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
        if (bulletSound->state() == QMediaPlayer::PlayingState) 
        {
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState) 
        {
            bulletSound->play();
        }
        break;
    }
    default:
        break;
    }
}

void Player::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
