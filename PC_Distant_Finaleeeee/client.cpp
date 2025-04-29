#include "client.h"
#include <QHostAddress>
#include <QDebug>

Client::Client(QObject *parent)
    : QObject(parent), socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::connectToServer(const QString &host, quint16 port)
{
    qDebug() << "[Client] Tentative de connexion à" << host << ":" << port;
    socket->connectToHost(QHostAddress(host), port);
    if (!socket->waitForConnected(3000)) {
        qWarning() << "Erreur de connexion au serveur:" << socket->errorString();
    } else {
        qDebug() << "[Client] Connecté au serveur";
    }
}

void Client::sendMessage(const QString &message)
{
    qDebug() << "[Client] Envoi du message:" << message;

    if (socket->state() == QAbstractSocket::ConnectedState) {
        QByteArray data = message.toUtf8();
        socket->write(data);
    }
}

void Client::onReadyRead()
{
    while (socket->bytesAvailable()) {
        QString message = QString::fromUtf8(socket->readAll());
        qDebug() << "[Client] Message reçu:" << message;
        emit messageReceived(message);
    }
}
