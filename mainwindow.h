#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "mapscene.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    mapScene scene;
    QAction *zoomIn, *zoomOut, *zoomOriginal, *fitBest;

private slots:
    void imageZoomIn();
    void imageZoomOut();
    void imageZoomOriginal();
    void imageFitBest();

public slots:
    void showCoordinates(qreal x, qreal y);
};

#endif // MAINWINDOW_H
