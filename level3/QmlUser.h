#ifndef QMLUSER_H
#define QMLUSER_H

#include <QObject>
#include "Src/User.h"

class QmlUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name
               READ name
               WRITE setName)
    Q_PROPERTY(QString status
               READ status
               NOTIFY statusChanged)
    Q_PROPERTY(QString log READ log NOTIFY logChanged)

public:
    explicit QmlUser(QString t = "", QObject *parent = nullptr);

    QString name();
    void setName(QString newName);
    void setPass(QString newPass);

    QString status();
    Q_INVOKABLE void enter(QString str);
    Q_INVOKABLE void setServer(Network* newNetwork);

    QString log() const;

private:
    User *user;

    QString _name;
    QString _pass;
    Network* network;

    QString _log;

private slots:
    void setLog(QString str);

signals:
    void statusChanged();
    void logChanged();
};

#endif // QMLUSER_H
