#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "QmlNetwork.h"
#include "QmlUser.h"
#include "Src/Network.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Network network;

    QmlNetwork qmlNetwork;
    QmlUser qmlUser1;
    QmlUser qmlUser2;
    QmlUser qmlUser3;
    QmlUser qmlUser4;

    qmlUser1.setServer(&network);
    qmlUser2.setServer(&network);
    qmlUser3.setServer(&network);
    qmlUser4.setServer(&network);
    qmlNetwork.setServer(&network);


    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();

    context->setContextProperty("qmlNetwork", &qmlNetwork);

    context->setContextProperty("qmlUser1", &qmlUser1);
    context->setContextProperty("qmlUser2", &qmlUser2);
    context->setContextProperty("qmlUser3", &qmlUser3);
    context->setContextProperty("qmlUser4", &qmlUser4);

    qmlRegisterType<QmlNetwork>("My", 1,0, "QmlNetwork");
    qmlRegisterType<QmlUser>("My", 1,0, "QmlUser");


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
