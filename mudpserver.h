#ifndef MUDPSERVER_H
#define MUDPSERVER_H

#include <QObject>
#include <QUdpSocket>

class MUDPServer : public QObject
{
    Q_OBJECT
public:
    explicit MUDPServer(QObject *parent = nullptr);

    void start();
    void stop();

private:
    QUdpSocket* serverSocket;
    void processTheDatagram(QNetworkDatagram&);

signals:

public slots:
    void handleRequest();
};

#endif // MUDPSERVER_H
