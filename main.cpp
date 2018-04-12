#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <iostream>
#include <string>
#include "game.h"
#include "token.h"
#include "player.h"
#include "messagedisplay.h"
#include <iostream>
#include <QtGui>


using namespace std ;

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);


    Game newGame("Player 1", "Player 2") ;

    QQmlApplicationEngine engine ;
    engine.rootContext()->setContextProperty("vueGame", &newGame) ;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml"))) ;

    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();

}
