// https://www.youtube.com/watch?v=sEGxuScquDo
#include <QtTest>

// add necessary includes here
#include "Src/Network.h"
#include "Src/User.h"

class level2 : public QObject
{
    Q_OBJECT

public:
    level2();
    ~level2();

private:
    Network *network;
    User *user1;
    User *user2;
    User *user3;
    User *user4;

private slots:
    void test_case1();
    void test_case2();
};

level2::level2()
{
    network = new Network;

    user1 = new User("user1");
    user2 = new User("user2");
    user3 = new User("user3");
    user4 = new User("user4");
}

level2::~level2()
{
    delete network;

    delete user1;
    delete user2;
    delete user3;
    delete user4;
}

void level2::test_case1()
{
    QString u1key = network->reg(user1);
    QCOMPARE(u1key.size() > 0, true);
    QCOMPARE(network->openConnect(user1, u1key), true);

// повторное подключение того же объекта не допустима
    QCOMPARE(network->openConnect(user1, u1key), false);


    QString u2key = network->reg(user2);
    QCOMPARE(network->openConnect(user2, u2key), true);

    QString u3key = network->reg(user3);
    QCOMPARE(network->openConnect(user3, u3key), true);

    QString u4key = network->reg(user4);
    QCOMPARE(network->openConnect(user4, u4key), true);
}

void level2::test_case2() {
// повторная регистрация тогоже объекта не допустима
    QString u1key = network->reg(user1);
    QCOMPARE(u1key.size() > 0, false);
    QCOMPARE(network->openConnect(user1, u1key), false);
}


QTEST_APPLESS_MAIN(level2)

#include "tst_level2.moc"
