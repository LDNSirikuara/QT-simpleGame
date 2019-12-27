#ifndef GAME_H
#define GAME_H

#include <QGraphicsRectItem>

class Game: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // GAME_H
