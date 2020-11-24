#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QMap>
#include <QSet>

class User;

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    QString reg(User* user);
    bool openConnect(User* user, QString key);
    bool sms(User *user, QString txt);

private:
    QMap<QString, QString> regs;
    QMap<QString, User*> users;
    QMap<QString, QStringList> subscribers;
    QString getRandomString(int randomStringLength = 12) const;

    bool sendUser(QString user, QString txt);


signals:

};

#endif // NETWORK_H
