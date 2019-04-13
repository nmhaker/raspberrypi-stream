#include <QCoreApplication>
#include <QtDebug>
#include <QUdpSocket>

#include "mudpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MUDPServer *server = new MUDPServer();
    server->start();

    return a.exec();

    server->stop();
    delete server;

}

