#ifndef COMMUNICATIONCONTROLLER_HPP
#define COMMUNICATIONCONTROLLER_HPP

#include <QObject>
#include <QTcpSocket>
#include <stdint.h>

const quint8 CMD_SERVO_CONTROL = 0xFA;
const quint8 CMD_MOTOR_CONTROL = 0xFB;

struct Command
{
  uint16_t code;
  uint16_t hiParam;
  uint16_t loParam;
};

class CommunicationController : public QObject
{
   Q_OBJECT
public:
   explicit CommunicationController(QObject *parent = 0);
   ~CommunicationController();   

public slots:

   void connectToHost( const QString& host, quint16 port );
   void disconnectFromHost();

   void changeCameraPosition(quint16 rotX, quint16 rotZ );

private slots:
   void onConnected();
   void onDisconnected();
   void onDataArrived();

private:
   QTcpSocket mSocket;
};

#endif // COMMUNICATIONCONTROLLER_HPP
