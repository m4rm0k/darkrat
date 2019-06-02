#include "loginUI.h"
#include "DarkRatCrypterUI.h"
#include <QtNetwork/QNetworkAccessManager>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <QtWidgets\QMessageBox>
#include "DarkRequest.h"
#include <tchar.h>
#include <QtCore\QSettings>



void Request(LPSTR data);
login::login(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
}




void login::on_btn_login_clicked()
{




	QString encryptedPass = QString(QCryptographicHash::hash((ui.password->text().toUtf8()), QCryptographicHash::Md5).toHex());
	std::string post = "user="+ui.username->text().toStdString() +"&pass="+ encryptedPass.toStdString();


	if (ui.keep_me->isChecked()) {
		std::ofstream config;
		config.open("config.ini");
		config << post;
		config.close();
		//TODO

	}


	std::string accessbool = postRequest(post);
	if (accessbool == "access") {
		//this->hide();
		DarkRatCrypterUI* builder;
		//builder = new DarkRatCrypterUI(this);
		builder = new DarkRatCrypterUI();
		builder->show();
		

	}
	else {

		QMessageBox msgBox;
		msgBox.setText("DarkRat License");
		msgBox.setInformativeText("You account Looks not Existing or Banned");
		msgBox.setStandardButtons(QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Cancel);
		int ret = msgBox.exec();
	}

	
}



