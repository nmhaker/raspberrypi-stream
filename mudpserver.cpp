#include "mudpserver.h"
#include "qnetworkdatagram.h"

#include "qprocess.h"

MUDPServer::MUDPServer(QObject *parent) : QObject(parent)
{

}

void MUDPServer::start(){
   serverSocket = new QUdpSocket(this);
   if(!serverSocket->bind(QHostAddress("127.0.0.1"), 8000)){
      qDebug("Nije binded");
   }else{
       qDebug("Binded");
   }

   connect(serverSocket, SIGNAL(readyRead()), this, SLOT(handleRequest()));
}

QProcess* firefoxProc = nullptr;

void MUDPServer::stop()
{
    serverSocket->close();
    firefoxProc->close();
    delete firefoxProc;
}

void MUDPServer::processTheDatagram(QNetworkDatagram &datagram){
    qDebug("Received bytes: " + datagram.data());
    firefoxProc = new QProcess(this);
    firefoxProc->execute("firefox --new-tab " + datagram.data());
}

void MUDPServer::handleRequest(){
    qDebug("Handling request");
    while (serverSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = serverSocket->receiveDatagram();
        processTheDatagram(datagram);
    }
}


