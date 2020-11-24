/**
  * Класс Network - сеть для обмена сообщениями
  */

#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QMap>
#include <QSet>

#include "User.h"

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    /*!
     * \param user - объект подключаемого пользователя
     * \return ключ для входа в систему или пустая строка, если регистрация не удачна
     */
    QString reg(User* user);
    /*!
     * \param user - объект подключаемого пользователя
     * \param key - ключ для подключения
     * \return статус подключения
     */
    bool openConnect(User* user, QString key);
    /*!
     * \param user - объект которому отправляется сообщение
     * \param txt - сообщение
     * \return статус отправки
     *
     * "/?" - данная справка
     * "subscribe: user2" - подписатся на user2
     * "to user2: txt" - отправить сообщение пользователю user2
     * "get connected users" - список подключенных пользователей
     * "get users list" - список зарегистрированных пользователей
     */
    bool sms(User *user, QString txt);

private:
    QMap<QString, QString> regs; //!< QMap зарегистрированных пользователей (пользователь|ключ)
    QMap<QString, User*> users; //!< QMap вошедших пользователей (имя|User*)
    QMap<QString, QStringList> subscribers; //!< QMap подписчиков (имя пользователя|его подписчики)
    /*!
     * \brief Метод для генерации случайной строки
     * \param randomStringLength - длина строки
     * \return случайная строка
     */
    QString getRandomString(int randomStringLength = 12) const;
    /**
     * \brief Метод для отправки пользователю сообщения
     * \param user - имя пользователя
     * \param txt - сообщение
     * \return статус отправки
     */
    bool sendUser(QString user, QString txt);


signals:
    /*!
     \param msg - сообщение
     signal для отправки сообщения от Network
     */
    void log(QString msg);
};

#endif // NETWORK_H
