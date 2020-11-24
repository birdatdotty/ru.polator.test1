/**
  * Класс User - пользователь сети Network
  */

#ifndef USER_H
#define USER_H

#include <QObject>

class Network;

class User : public QObject
{
    Q_OBJECT
public:
    //! User constructor.
    /*!
      \param name - имя пользователя
      объект пользователя сети
    */
    explicit User(QString name, QObject *parent = nullptr);
    /*!
     \return имя пользователя
     */
    QString name() const;
    /**
     * @param network - сеть, которой будет отправленно сообщение
     * @param txt - сообщение
     * @return статус отправки
     * @brief отправка сообщения
     */
    bool sms(Network* network, QString txt);
    /**
     * @param txt - сообщение
     * @brief получение сообщения
     */
    void sms(QString txt);


private:
    QString _name; ///< имя пользователя
    QStringList recivedMessages; ///< список полученных сообщений

signals:
    /**
     * @brief signal для полученных сообщений
     * @param msg - сообщение
     */
    void echo(QString msg);
};

#endif // USER_H
