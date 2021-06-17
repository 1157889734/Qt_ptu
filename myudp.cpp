#include "myudp.h"
#include "mywidget.h"
#define PORT 50152
static int socketFd = -1;

myudp::myudp(QObject *parent) : QObject(parent)
{
    //udpInit();
    //startThread(&pthread_fd,this->receive_proc,this);
    receive_data();

}
int myudp::udpInit()
{
    myudpSocket = new QUdpSocket(this);
    bool result = myudpSocket->bind(PORT);
    if(!result)
    {
        return -1;
    }
}
void myudp::read_data()
{
    //memset(databuf,0,sizeof(databuf));

    while(myudpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(myudpSocket->pendingDatagramSize());
        myudpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
//           myudpSocket->readDatagram(databuf,1024);
//        for(int i=0;i<64;i++)
//        {
//            qDebug()<<"data:"<<databuf[i];
//        }
        //ReceiceTextEdit->insertPlainText(msg);
        qDebug()<<"1111111111111"<<msg<<endl;
    }

}
int myudp::receive_data()
{

    int res = -1;
    while (res < 0)
    {
        res = udpInit();
    }
    while (1)
    {
        //read_data();
    }
    return 0;
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

