#ifndef KEcm_H
#define KEcm_H

#include <KMainWindow>
#include <qtsoap.h>
#include <QNetworkReply>
#include <KLocale>
#include <KMenuBar>
#include "KEcmConfigure.h"

class KEcm : public KMainWindow
{
Q_OBJECT
public:
    KEcm();
    virtual ~KEcm();
public slots:
  void authenticationRequired(QNetworkReply *reply, QAuthenticator *auth);
  void httpFinished( QNetworkReply *reply);
  void httpReadyRead(QNetworkReply *reply);
  void getResponse(const QtSoapMessage &);

private slots:
  void ecmConfigure();
  
private:
  QtSoapHttpTransport http;
  KMenuBar *menubar;
};

#endif // KEcm_H
