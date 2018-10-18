#ifndef GAME_H
#define GAME_H
#include "rasterwindow/rasterwindow.h"
#include "rnd/rnd.h"

class game: public RasterWindow{
public:
    game();
protected:
    int mousex = 0;
    int mousey = 0;
    static const int nx = 20;
    static const int ny = 20;
    QPoint red = QPoint(nx / 2, ny / 2);
    int table[nx][ny];
    QColor STATES[5] = {
        QColor(180, 180, 180),
        QColor(30, 30, 30),
        QColor(100, 100, 100),
        QColor(200, 0, 0),
        QColor(0, 200, 0)};
    QPainter *p;
    Rnd *r = new Rnd();
    void renderPosition(int i, int j);
    void timerEvent(QTimerEvent *) override;
    void render(QPainter *p) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mousePressEvent(QMouseEvent *e) override;

private:
    int m_timerId;
};

#endif // GAME_H
