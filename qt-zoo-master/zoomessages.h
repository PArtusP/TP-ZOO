#ifndef ZOOMESSAGES_H
#define ZOOMESSAGES_H

#include "zoomessage.h"
#include "zooobject.h"
#include <QVector>


class ZooMessages : public ZooObject
{
    typedef QVector<ZooMessage*> MessagesList;
    MessagesList messages;

public:
    ZooMessages();
    void addMessage(ZooMessage *message);
    MessagesList getMessages() const;
    MessagesList getMessagesByErrorLevel(ZooErrorLevel lvl);
    MessagesList getMessagesByEmittor(ZooObject* emetteur);
    MessagesList getInstance();
    QString getLastMessage();
};

#endif // ZOOMESSAGES_H



