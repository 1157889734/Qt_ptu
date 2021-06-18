#include "myudp.h"
#include "mywidget.h"
#define PORT 50152

myudp::myudp(QObject *parent) : QObject(parent)
{
    udpInit();
    //startThread(&pthread_fd,this->receive_proc,this);
    //receive_data();
    init();
}
void myudp::init()
{
    dataTimer = new QTimer(this);
    connect(dataTimer,SIGNAL(timeout()),this,SLOT(receive_data()));
    dataTimer->start(1000);
}
int myudp::udpInit()
{
    myudpSocket = new QUdpSocket(this);
    bool result = myudpSocket->bind(PORT);
    if(!result)
    {
        return -1;
    }
    return 0;
}
void myudp::read_data()
{
    while(myudpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(myudpSocket->pendingDatagramSize());
        myudpSocket->readDatagram(datagram.data(),datagram.size());
        QByteArray data = datagram.toHex();
        char buf[256];
        int len = data.size();
        int len_buf=sizeof(buf);
        int real_len = qMin(len,len_buf);
        memcpy(buf,data,real_len);
        int i ;
        for(i = 0;i<real_len;i++)
        {
            databuf[i]=buf[i];
        }
    }

}
void myudp::receive_data()
{   
    read_data();
}
int myudp::startThread(pthread_t *fd, void *(*fun)(void *), void *arg)
{
    int ret;
    ret = pthread_create(fd, NULL, fun, arg);

    if (ret < 0)
    {
        perror("pthread_create");
        return -1;
    }
    return 1;
}


