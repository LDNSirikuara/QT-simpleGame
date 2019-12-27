#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include <QDebug>

Bullet::Bullet(){
    // drew the rect
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // if bullet collides with enemy, destroy both
    QList < QGraphicsItem * > colliding_item = collidingItems();
    for (int i = 0, n = colliding_item.size(); i < n; ++i){
        if (typeid(*(colliding_item[i])) == typeid (Enemy)){
            // Remove them both
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_item[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
