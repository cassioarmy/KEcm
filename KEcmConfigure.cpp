/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright 2014  Cassio Sousa <email>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "KEcmConfigure.h"
#include <KConfigSkeleton>
#include "KEcmAuthentication.h"
#include <KPageWidgetItem>
#include <KXmlGuiWindow>
#include <KIcon>


class Conexao : public QWidget{
  
  Q_OBJECT
  
public:
  Conexao(QWidget *parent) 
      : QWidget(parent)
  {
   
  }
};

kEcmConfigure::kEcmConfigure()
{

}

kEcmConfigure::kEcmConfigure(KMainWindow  *parent)
{
 
  if (KConfigDialog::showDialog("settings")) {
      return;
  }
  
   KConfigDialog* pDialog = new KConfigDialog(parent, "settings", KEcmSettings::self());
   pDialog->setFaceType(KPageDialog::List);
   
  // KEcmSettingsHelper *conexao = new KEcmSettingsHelper(0,"Conexao"); 
  // KPageWidgetItem *itemConexao = new KPageWidgetItem(new QWidget(this),QString("Conexão"));
   //itemConexao->setIcon(KIcon("configure"));
   
   //pDialog->addPage( itemConexao,QString("Conexão"));
 //  pDialog->show();
   
}



kEcmConfigure::~kEcmConfigure()
{

}
