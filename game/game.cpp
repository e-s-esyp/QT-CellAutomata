#include "game.h"

game::game(){
setTitle("Analog Clock");
resize(320, 240);
for(int i = 0; i < nx; ++i){
    for(int j = 0; j < ny; ++j){
        int v = r->rnd(2);
        table[i][j] = (i == 0 || j == 0 || i == nx - 1 || j == ny - 1) ? 1 : (2 * v);
    }
}
m_timerId = startTimer(10);
}
void game::renderPosition(int i, int j){
    p->setPen(STATES[table[i][j]]);
    p->setBrush(STATES[table[i][j]]);
    p->drawRect(i * 10 + 1, j * 10 + 1, 8, 8);
}

void game::timerEvent(QTimerEvent *event){
    if (event->timerId() == m_timerId){
        int i = red.x();
        int j = red.y();
        bool success = false;
        table[red.x()][red.y()] = 0;
        int direction = r->rnd(4);
        int tests = 0;
        while(not success && tests++ < 4){
            switch(direction++){
            case 0:{
                if (i > 1 && table[i-1][j] == 0) {
                    red.setX(i - 1);
                    success = true;
                }
                break;
            }
            case 1:{
                if (i < nx - 2 && table[i+1][j] == 0) {
                    red.setX(i + 1);
                    success = true;
                }
                break;
            }
            case 2: {
                if (j > 1 && table[i][j-1] == 0) {
                    red.setY(j - 1);
                    success = true;
                }
                break;
            }
            case 3: {
                if (j < ny - 2 && table[i][j+1] == 0) {
                    red.setY(j + 1);
                    success = true;
                }
                break;
            }
            }
            direction %= 4;
        }
        table[red.x()][red.y()] = 3;
        renderLater();
    }
}

void game::render(QPainter *p){
    int side = qMin(width(), height());
    p->setRenderHint(QPainter::Antialiasing);
    p->scale(side / 200.0, side / 200.0);
    p->setBrush(QColor(0, 0, 0, 50));
    this->p = p;
    for(int i = 0; i < nx; ++i){
        for(int j = 0; j < ny; ++j){
            renderPosition(i, j);
        }
    }
    QFont font = p->font();
    font.setPixelSize(10);
    p -> setFont(font);
    p->drawText(202, 10, QString("x=%1").arg(mousex));
    p->drawText(202, 20, QString("y=%1").arg(mousey));
    p->drawText(202, 30, QString("i=%1").arg(nx * mousex / side));
    p->drawText(202, 40, QString("j=%1").arg(ny * mousey / side));
    p->drawText(202, 50, QString("height=%1").arg(p->fontMetrics().height()));
}

void game::mouseMoveEvent(QMouseEvent *e){
    mousex = e->x();
    mousey = e->y();
    renderLater();
}

void game::mousePressEvent(QMouseEvent *e){
    mousex = e->x();
    mousey = e->y();
    int side = qMin(width(), height());
    int i = nx * mousex / side;
    int j = ny * mousey / side;
    if (i < nx && j < ny){
        table[i][j]++;
        table[i][j] %= 5;
    }
    renderLater();
}

