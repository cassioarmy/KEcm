#include <QtGui/QApplication>
#include "KEcm.h"
#include <iostream>
#include <kapplication.h>
#include <KCmdLineArgs>
#include <KAboutData>
#include <KLocale>
using namespace std;

int main(int argc, char** argv)
{
   KAboutData aboutData( "tutorial2", 0,
      ki18n("Tutorial 2"), "1.0",
      ki18n("A simple text area"),
      KAboutData::License_GPL,
      ki18n("Copyright (c) 2007 Developer") );
    KCmdLineArgs::init( argc, argv, &aboutData);
    
    KApplication app;    
    KEcm foo;
    foo.show();    
    
    return app.exec();
}
