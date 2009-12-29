#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsSceneMouseEvent>

class mapScene : public QGraphicsScene
{
signals:
    void coordinatesChanged(qreal x, qreal y);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // MAPSCENE_H
