#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QStyle>
#include <QtOpenGL/QGLWidget>
#include <QtCore/QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    zoomIn = new QAction(QIcon(":/zoom-in.svg"), tr("Zoom in"), this);
    connect(zoomIn, SIGNAL(triggered()), this, SLOT(imageZoomIn()));
    ui->mainToolBar->addAction(zoomIn);

    zoomOut = new QAction(QIcon(":/zoom-out.svg"), tr("Zoom out"), this);
    connect(zoomOut, SIGNAL(triggered()), this, SLOT(imageZoomOut()));
    ui->mainToolBar->addAction(zoomOut);

    zoomOriginal = new QAction(QIcon(":/zoom-original.svg"), tr("Zoom original"), this);
    connect(zoomOriginal, SIGNAL(triggered()), this, SLOT(imageZoomOriginal()));
    ui->mainToolBar->addAction(zoomOriginal);

    fitBest = new QAction(QIcon(":/zoom-fit-best.svg"), tr("Fit best"), this);
    connect(fitBest, SIGNAL(triggered()), this, SLOT(imageFitBest()));
    ui->mainToolBar->addAction(fitBest);

    QGraphicsPixmapItem *item;

//    const int ymin = 606, ymax = 609, xmin = 187, xmax = 191;
//    const QString mappath("/home/ptroja/ports/fetch_map/map_cache/rka/25000_256_256/655_300/map_rka_25000_%1_%2.png");

    const int minFileSize = 3385; // minimum file size

    const int ymin = 225, ymax = 316, xmin = 503, xmax = 595;
    const QString mappath("/home/ptroja/boost/tilemap/maps/map_rka_15000_%1_%2.png");

    QSize tileSize;

    int loaded = 0, processed = 0;

    for (int y = ymin, yind = 0; y <= ymax; y++, yind++)
    {
        for (int x = xmin, xind = 0; x <= xmax; x++, xind++)
        {
            const QString tilefile(mappath.arg(QString::number(y)).arg(QString::number(x)));
            QFile file(tilefile);
            ++processed;
            if(file.size() < minFileSize) {
                continue;
            }
            item = scene.addPixmap(QPixmap(tilefile));
            if (!tileSize.isValid()) {
                tileSize = item->pixmap().size();
            }
            if (item->pixmap().size() != tileSize) {
                qFatal("Tiles size differ: %s is (%dx%d), expected (%dx%d).",
                       tilefile.toAscii().constData(),
                       item->pixmap().width(), item->pixmap().height(),
                       tileSize.width(), tileSize.height());
            }
            item->setPos(xind*tileSize.width(), yind*tileSize.height());
            ++loaded;
        }
    }

    QString statusMessage("Tile size: %1x%2 #(%3/%4)");
    statusMessage = statusMessage
                    .arg(QString::number(tileSize.width())).arg(QString::number(tileSize.height()))
                    .arg(QString::number(loaded)).arg(QString::number(processed));
    ui->statusBar->showMessage(statusMessage);

    ui->graphicsView->setScene(&scene);

//    connect((mapScene *) &scene, SIGNAL(coordinatesChanged(qreal,qreal)), this, SLOT(showCoordinates(qreal, qreal)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::imageZoomIn()
{
    ui->graphicsView->scale(1.1, 1.1);
}

void MainWindow::imageZoomOut()
{
    ui->graphicsView->scale(0.9, 0.9);
}

void MainWindow::imageZoomOriginal()
{
    ui->graphicsView->resetMatrix();
}

void MainWindow::imageFitBest()
{
    ui->graphicsView->fitInView(ui->graphicsView->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::showCoordinates(qreal x, qreal y)
{
    printf("kupa :(\n");
    QString msg("(%1,%2)");

    msg.arg(QString::number(x)).arg(QString::number(y));

    ui->statusBar->showMessage(msg);
}

