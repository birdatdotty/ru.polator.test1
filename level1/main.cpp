#include <QCoreApplication>

#include "Network.h"
#include "User.h"

#include <QDebug>

// "subscribe: user2" - подписатся на user2
// "to user2: txt" - отправить сообщение пользователю user2

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Network network;
    User    user1("user1"),
            user2("user2"),
            user3("user3"),
            user4("user4");

    bool rc;
    QString u1key = network.reg(&user1);
    rc = network.openConnect(&user1, u1key);
//    qInfo() << rc;

    QString u2key = network.reg(&user2);
    rc = network.openConnect(&user2, u2key);
//    qInfo() << rc;

    QString u3key = network.reg(&user3);
    rc = network.openConnect(&user3, u3key);
//    qInfo() << rc;

    QString u4key = network.reg(&user4);
    rc = network.openConnect(&user4, u4key);


    // subscribe:
    user1.sms(&network, "subscribe: user2");
    user2.sms(&network, "subscribe: user2");
    user3.sms(&network, "subscribe: r user2");

    // send message:
    user2.sms(&network, "MSG))))");
    user2.sms(&network, "to user2: txt");
    user2.sms(&network, "to user3: txt");


    user1.sms(&network, "get users list");
    return a.exec();
}
