#include "QmlUser.h"

#include <QDebug>
#include "Src/Network.h"

QmlUser::QmlUser(QString t, QObject *parent)
    : QObject(parent),
      _name(t)
{

}

QString QmlUser::name() {
    return _name;
}

void QmlUser::setName(QString newName) {
    _name = newName;
    statusChanged();
}

void QmlUser::setPass(QString newPass)
{
    _pass = newPass;
    statusChanged();
}

QString QmlUser::status() {
    qInfo() << this << _name;
    if (_name.size() == 0)
        return "Введите login> ";

    if (_pass.size() == 0)
        return "Введите pass> ";

    return "> ";
}

void QmlUser::enter(QString str)
{
    qInfo() << "void QmlUser::enter(QString str):" << str;
    qInfo() << "_name" << _name;
    qInfo() << "_pass" << _pass;
    if (_name.size() == 0) {
        if (str.startsWith(status()))
            setName(str.mid(status().size()));

        qInfo() << "_name" << _name;
        user = new User(_name);
        QString u1key = network->reg(user);
        qInfo() << __LINE__ << u1key;
        setLog("key: " + u1key);

        return ;
    }

    if (_pass.size() == 0) {
        if (str.startsWith(status()))
            setPass(str.mid(status().size()));

        if (network->openConnect(user, _pass)) {
            setLog("connected!");
            connect(user, &User::echo,
                    this, &QmlUser::setLog);
        }
        else
            setLog("Error(");

        return;
    }

    user->sms(network, str.mid(status().size()));
    statusChanged();
}

void QmlUser::setServer(Network *newNetwork) {
    network = newNetwork;
}

QString QmlUser::log() const {
    return _log;
}

void QmlUser::setLog(QString str) {
    _log += str + "\n";
    logChanged();
}
