#include "KEcm.h"

#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QAction>
#include <iostream>
#include <qtsoap/qtsoap.h>
#include <QAuthenticator>
#include <QMessageBox>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <KAction>
KEcm::KEcm()
{  
    QLabel* l = new QLabel( this );
    l->setText( "Hello World!" );
    setCentralWidget( l );
    KAction* a = new KAction(this);
    a->setText( "Quit" );
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    
      menubar = new KMenuBar;
    menubar->addMenu("File" )->addAction( a );
    
    setMenuBar(menubar);
    KAction* autenticacao = new KAction(this);
    autenticacao->setText( ki18n("&WebServices").toString() );
    connect(autenticacao, SIGNAL(triggered()), SLOT(ecmConfigure()) );
        
    menubar->addMenu( ki18n("&Configurações").toString() )->addAction( autenticacao );    
    
    connect(&http, SIGNAL(responseReady(const QtSoapMessage &)),
            this, SLOT(getResponse(const QtSoapMessage &)));
    
    connect(http.networkAccessManager(), SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
             this, SLOT(authenticationRequired(QNetworkReply*,QAuthenticator*)));
    
    QtSoapMessage request;
    
    request.setMethod("DocInfoByName", "http://www.stellent.com/DocInfo");
        
   
    request.addMethodArgument("dDocName", "http://www.stellent.com/DocInfo", "CSNOTE16200000201");
     
    // Submit the request the the web service.    
    http.setHost("csnote",false,16200);
    http.setAction("http://csnote:16200/_dav/cs/idcplg/DocInfo");
    
    http.submitRequest(request, "_dav/cs/idcplg/DocInfo?WSDL");
    //std::cout << request.toXmlString().toStdString() << "\n\n\n";
   // delete type;
    /*
    request.setMethod("GetEaster",
		      "http://www.27seconds.com/Holidays/US/Dates/");
    request.addMethodArgument("year", "", 10);

    http.setHost("www.27seconds.com");
    http.setAction("http://www.27seconds.com/Holidays/US/Dates/GetEaster");
    http.submitRequest(request, "/Holidays/US/Dates/USHolidayDates.asmx");*/
    /*
    std::cout << "tt " << request.errorString().toStdString() << endl;
    std::cout << "tt " << request.returnValue().toString().toStdString() << "\n\n" << endl;
    std::cout << request.toXmlString().toStdString() << "\n\n\n";
    
    
    
    qDebug("passou");
    
    // create and show your widgets here
    const QtSoapMessage &message = http.getResponse();
    std::cout << message.returnValue().toString().toStdString();
    // Check if the response is a SOAP Fault message
    if (message.isFault()) {
        qDebug("Error: %s", message.faultString().value().toString().toLatin1().constData());
    }
    else {
      std::cout <<  message.toXmlString().toStdString() ;
        // Get the return value, and print the result.
        const QtSoapType &response = message.returnValue();
        qDebug("%s Teste",
               response["DocInfoByNameResult"].value().toString().toLatin1().constData());
    }
    
    QUrl url("http://csnote:16200/_dav/cs/idcplg/DocInfo?WSDL");
    QNetworkRequest request(url);
    QNetworkAccessManager *qnam  = new QNetworkAccessManager(this);;
    
    
    connect(qnam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(httpFinished(QNetworkReply*)));
   connect(qnam, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)),
             this, SLOT(authenticationRequired(QNetworkReply*, QAuthenticator*)));
   
   
   QByteArray arr;
   arr.append("<soapenv:Envelope xmlns:soapenv=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:doc=\"http://www.stellent.com/DocInfo/\">");
   arr.append("<soapenv:Header>");
   arr.append("</soapenv:Header>");
   arr.append("<soapenv:Body>");
    arr.append("<doc:DocInfoByName>");
      arr.append("<doc:dDocName>CSNOTE16200000201</doc:dDocName>");
    arr.append("</doc:DocInfoByName>");
   arr.append("</soapenv:Body>");
   arr.append("</soapenv:Envelope>");
   
   request.setHeader(QNetworkRequest::ContentTypeHeader,"text/xml");
   
   
   qnam->post(request,arr);*/
   
}
void KEcm::authenticationRequired(QNetworkReply *reply, QAuthenticator *auth)
{
 // QMessageBox::StandardButton sb;
  //sb = QMessageBox::question(this, "Test", "Quit?",
  //                              QMessageBox::Yes|QMessageBox::No);
  std::cout << "ENTROU AUTENTICACAO \n\n\n\n";
  auth->setUser("weblogic");
  auth->setPassword("weblogic1");
}

 void KEcm::httpFinished(QNetworkReply *reply)
 {
     std::cout << "passou" << QString(reply->readAll()).toStdString();
         return;
     }
     
void KEcm::httpReadyRead(QNetworkReply *reply)
 {
     // this slot gets called every time the QNetworkReply has new data.
     // We read all of its new data and write it into the file.
     // That way we use less RAM than when reading it at the finished()
     // signal of the QNetworkReply
    // if (file)
   // std::cout << reply->readAll();
   std::cout << "passou2";
 }
 
 void KEcm::getResponse(const QtSoapMessage &message)
 {
   
   //std::cout << "\nresponse " << message.toXmlString().toStdString();
     if (message.isFault()) {
       
       std::cout << "\n" << message.faultDetail().toString().toStdString();
	qDebug("Errorssssss: %s", qPrintable(message.faultString().toString()));
    }else {
       /* QString res = message.returnValue().toString();
        QDateTime dt = QDateTime::fromString(res, Qt::ISODate);
        if (dt.isValid())
            res = QLocale::c().toString(dt.date());
*/
       const QtSoapType &docInfo = message.returnValue();
       qDebug() << docInfo[QtSoapQName("dDocName","http://www.stellent.com/DocInfo/")].toString().toLatin1().constData();
        //qDebug("Easter is: %s", docInfo["DocInfoByNameResponse"].value().toString().toLatin1().constData());
       //qDebug("Easter is: %s", docInfo.count());
       std::cout << "\n\n\n\n\n\nTeste ";
       //qDebug() << docInfo["DocInfoByNameResponse"]["DocInfoByNameResult"]["ContentInfo"]["dDocName"].toString().toLatin1().constData();
       //qDebug() << 	"TDDDD" << docInfo[0]["dDocName"].value().toString().toLatin1().constData();
       int docInfoCount = docInfo.count();
       int docInfoCounty = 0;
       for(int x= 0; x < docInfoCount; x++){
	  
	 docInfoCounty = docInfo[x].count();
	 
	 for(int y= 0; y < docInfoCounty; y++){
	    qDebug("Nome: %s \t Value: %s",
	      QString(docInfo[x][y].name().name()).toLatin1().constData(),
	      docInfo[x][y].value().toString().toLatin1().constData());
	  }
	  qDebug("\n\n");
       }
       
       std::cout << "\n\n\n\n\n\nTeste ";
    }
 }
void KEcm::ecmConfigure(){
  
  kEcmConfigure configure(this);
  
}
KEcm::~KEcm()
{
  delete menubar;
}

#include "KEcm.moc"
