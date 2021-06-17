#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>

class myudp : public QObject
{
    Q_OBJECT
public:
    explicit myudp(QObject *parent = nullptr);

public:
    int udpInit();
    void read_data();
    int  receive_data();
    QUdpSocket *myudpSocket;
    int startThread(pthread_t *fd, void *(*fun)(void *), void *arg);
    char databuf[1024];
public:
    pthread_t pthread_fd;

signals:

public slots:
};

#endif // MYUDP_H
