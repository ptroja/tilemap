#include "mapscene.h"

#include "ui_mainwindow.h"

void mapScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//    printf("mousePressEvent\n");
}

void mapScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//    printf("%f %f\n", mouseEvent->scenePos().x(), mouseEvent->scenePos().y());
//    ui->statusBar->showMessage("kupa");
    emit coordinatesChanged(mouseEvent->scenePos().x(), mouseEvent->scenePos().y());
}

void mapScene::coordinatesChanged(qreal x, qreal y)
{
//    printf("coordinatesChanged signalled\n");
}
