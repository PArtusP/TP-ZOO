#ifndef ZOO_H
#define ZOO_H

#include "zoobudget.h"
#include "zoomessages.h"
#include "zooobject.h"
#include "zoostock.h"
#include <QMap>

typedef QMap<QString, ZooStock*> Stocklist;

class Zoo : public ZooObject
{
    ZooMessages *m_messages;
    ZooBudget *m_budget;
    Stocklist stockList;
    static Zoo *m_zoo;
public:
    static Zoo *getInstance(const QString &name = "");
    ~Zoo();
    int addMoney(int amount);
    bool removeMoney(int amount);
    int getMoney();
    void testMe();
    void addmessage(ZooMessage *message);
    ZooMessages *getMessage();
    void setMessages(ZooMessages);
    

private:
    Zoo(const QString &name);
};

#endif // ZOO_H
