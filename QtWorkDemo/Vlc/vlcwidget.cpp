#include "vlcwidget.h"

VlcWidget::VlcWidget(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0, 0, 800, 480);
    vlcthread =new VlcThread(this);
    BtnVlc = new QPushButton("开始网络串流", this);
    //MesBox->setText("请输入正确Url");
    UrlLEdit =new QLineEdit(this);
    BtnVlc->setGeometry(100,350,100,50);
    UrlLEdit->setGeometry(300,350,400,25);
    BtnVlc->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"                                    "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    connect(BtnVlc,SIGNAL(clicked()),this,SLOT(BtnVlc_clicked()));
}
bool VlcWidget::SetVlcUrl(QString Url)
{
    if(this->UrlLEdit->text().isEmpty()){
    QMessageBox::information(this, "error", "invalid url");
    this->BtnVlc->setText("开始网络串流");
    return false;
   }
    this->vlcthread->SetUrl(Url);
}
void VlcWidget::OpenVlc()
{
  this->vlcthread->Play();
  this->vlcthread->start();
}

void VlcWidget::RestaetVlc()
{
    //qDebug() << TIMEMS << "restart video" << objectName();
    close();
    QTimer::singleShot(10, this, SLOT(open()));
}

void VlcWidget::CloseVlc()
{
   this->vlcthread->Close();
}

void VlcWidget::ClearVlc()
{
    update();
}

void VlcWidget::BtnVlc_clicked()
{
   if(this->BtnVlc->text()=="开始网络串流"){
        this->BtnVlc->setText("停止串流");
        QString Url = this->UrlLEdit->text();
        this->SetVlcUrl(Url);
        this->OpenVlc();
   }
   else{
        this->BtnVlc->setText("开始网络串流");
        this->CloseVlc();
   }
}



