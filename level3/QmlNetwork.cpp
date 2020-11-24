#include "QmlNetwork.h"

#include <QDebug>

QmlNetwork::QmlNetwork(QObject *parent) : QObject(parent)
{
}

void QmlNetwork::setServer(Network *newNetwork) {
    network = newNetwork;
    connect(network, &Network::log,
            this, &QmlNetwork::log);
    logChanged();
}

void QmlNetwork::log(QString str) {
    _log += str + "\n";
    qInfo() << __LINE__ << _log;
    logChanged();
}
