#ifndef QMLNetwork_H
#define QMLNetwork_H

#include <QObject>
#include "Src/Network.h"

class QmlNetwork : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString log1
               READ getLog
               NOTIFY logChanged)
public:
    explicit QmlNetwork(QObject *parent = nullptr);
    void setServer(Network *newNetwork);
    QString getLog();

private:
    Network* network;
    QString _log;

signals:
    void logChanged();

private slots:
    void log(QString str);
};

#endif // QMLNetwork_H
