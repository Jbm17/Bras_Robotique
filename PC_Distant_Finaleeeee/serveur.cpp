#include "serveur.h"
#include "serialport.h"
#include <QDebug>

Serveur::Serveur(SerialPort *serialPort, QObject *parent)
    : QObject(parent), serial(serialPort)
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &Serveur::onNewConnection);
}

bool Serveur::startServer(quint16 port)
{
    return tcpServer->listen(QHostAddress::Any, port);
}

void Serveur::onNewConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    clients.append(clientSocket);

    connect(clientSocket, &QTcpSocket::readyRead, this, &Serveur::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Serveur::onClientDisconnected);

    qDebug() << "[Serveur] Nouveau client connecté:" << clientSocket->peerAddress().toString();
}

void Serveur::onReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    QByteArray data = clientSocket->readAll();
    QString message = QString::fromUtf8(data);
    qDebug() << "[Serveur] Message reçu:" << message;

    emit messageRecu(message);

    // Si tu veux aussi renvoyer à tous les clients (broadcast)
    /*
    for (QTcpSocket *client : clients) {
        if (client->state() == QAbstractSocket::ConnectedState) {
            client->write(data);
        }
    }
    */
}

void Serveur::onClientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    clients.removeAll(clientSocket);
    clientSocket->deleteLater();

}
