#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>

class myudp : public QObject
{
    Q_OBJECT
public:
    explicit myudp(QObject *parent = nullptr);

public:
    void init();
    int udpInit();
    void read_data();
    QUdpSocket *myudpSocket;
    int startThread(pthread_t *fd, void *(*fun)(void *), void *arg);
    char databuf[1024];
    QTimer  *dataTimer;
public:
    pthread_t pthread_fd;

signals:

public slots:
    void receive_data();
};

#endif // MYUDP_H
