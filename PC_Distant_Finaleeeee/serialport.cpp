#include "serialport.h"
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <QDebug>

SerialPort::SerialPort(const QString &portName) : portName(portName), fd(-1) {}

SerialPort::~SerialPort() {
    closePort();
}

bool SerialPort::openPort() {
    fd = open(portName.toStdString().c_str(), O_RDWR | O_NOCTTY);
    if (fd == -1) {
        qDebug() << "[SerialPort] ❌ Erreur ouverture port série :" << portName;
        return false;
    }

    struct termios tty;
    if (tcgetattr(fd, &tty) != 0) {
        qDebug() << "[SerialPort] ❌ Erreur configuration série.";
        return false;
    }

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    tcsetattr(fd, TCSANOW, &tty);
    qDebug() << "[SerialPort] ✅ Port série ouvert :" << portName;
    return true;
}

void SerialPort::closePort() {
    if (fd != -1) {
        close(fd);
        fd = -1;
    }
}

bool SerialPort::writeData(const QString &data) {
    if (fd != -1) {
        QByteArray bytes = data.toUtf8();
        write(fd, bytes.constData(), bytes.size());
        return true;
    }
    return false;
}
