#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include "Enemy.h"
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent):
    scene(new QGraphicsScene()),
    player(new Player()),
    score(new Score()),
    health(new Health())
{
    scene->setSceneRect(0, 0, 810, 610);
    setBackgroundBrush(QBrush(QImage("Images/bg.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(810, 610);

    player->setPos(400, 500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);
    scene->addItem(score);

    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("Sounds/bgsound.wav"));
    music->play();

    show();
}

Game::~Game()
{
    delete scene;
    delete player;
    delete score;
    delete health;
}
