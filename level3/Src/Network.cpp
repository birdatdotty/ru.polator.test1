#include "Network.h"

#include "User.h"

#define SUBSCRIBE "subscribe"
#define TO "to "
#define USERSLIST "get users list"
#define CONNECTUSERSLIST "get connected users"

Network::Network(QObject *parent) : QObject(parent)
{

}

QString Network::reg(User *user) {
    QString name = user->name();
    if (regs.contains(name))
        return "";

    QString key = getRandomString();
    regs[name] = key;

    return key;
}

bool Network::openConnect(User *user, QString key)
{
    const QString name = user->name();

    if (!regs.contains(name))
        return false;

    if (key != regs[name])
        return false;

    if (users.contains(name))
        return false;

    users[name] = user;

    return true;
}

bool Network::sms(User *user, QString txt)
{
    QString userName = user->name();
    log(userName + ": " + txt);
    if (txt == USERSLIST) {
        QString recTxt = regs.keys().join("; ");
        user->sms(recTxt);
        return true;
    }
    if (txt.startsWith(SUBSCRIBE ":")) {
        QString issuerName = txt.mid(strlen(SUBSCRIBE ":")).trimmed();
        if (issuerName == userName) return false;
        subscribers[issuerName] << userName;

        return true;
    }
    if (txt.startsWith(CONNECTUSERSLIST)) {
        user->sms(users.keys().join("; "));

        return true;
    }

    if (txt.startsWith(TO)) {
        int colonPos = txt.indexOf(':');
        if (colonPos > -1) {
            QString sendTo = txt.mid(strlen(TO), colonPos - strlen(TO)).trimmed();

            return sendUser(sendTo, txt);
        }
    }

    if (txt == "/?") {
        user->sms("* \"/?\" - данная справка\n"
                  "* \"subscribe: user2\" - подписатся на user2\n"
                  "* \"to user2: txt\" - отправить сообщение пользователю user2\n"
                  "* \"get connected users\" - список подключенных пользователей\n"
                  "* \"get users list\" - список зарегистрированных пользователей\n");

        return true;
    }

    QStringList set = subscribers[userName];
    for (QString userIt: set)
        sendUser(userIt, txt);

    return true;
}

QString Network::getRandomString(int randomStringLength) const
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = rand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }

    return randomString;
}

bool Network::sendUser(QString user, QString txt) {
    if (users.contains(user)) {
        users[user]->sms(txt);

        return true;
    }

    return false;
}


