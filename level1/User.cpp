#include "User.h"
#include "Network.h"

#include <QDebug>

User::User(QString name, QObject *parent)
    : QObject(parent),
      _name(name)
{}

QString User::name() const
{
    return _name;
}

bool User::sms(Network *network, QString txt)
{
    return network->sms(this, txt);
}

void User::sms(QString txt) {
    qInfo() << _name + ": " << txt;
    recivedMessages << txt;
}
