#ifndef USER_H
#define USER_H

#include <QObject>

class Network;

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QString name, QObject *parent = nullptr);
    QString name() const;
    bool sms(Network* network, QString txt);
    void sms(QString txt);


private:
    QString _name;
    QStringList recivedMessages;


signals:

};

#endif // USER_H
