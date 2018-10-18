//#define USE_QML
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "game/game.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
#ifdef USE_QML
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
#else
    game clock;
    clock.show();
#endif
    return app.exec();
}
