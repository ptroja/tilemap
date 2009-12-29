#include "mapgraphicsview.h"

#include <QtOpenGL/QGLWidget>

mapGraphicsView::mapGraphicsView(QWidget* parent)
        :QGraphicsView(parent)
{
    setupViewport(new QGLWidget);
}
