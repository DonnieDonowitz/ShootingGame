#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent):
    QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 10));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
