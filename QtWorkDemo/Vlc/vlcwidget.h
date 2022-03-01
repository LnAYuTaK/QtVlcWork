#ifndef VLCWIDGET_H
#define VLCWIDGET_H

#include <QWidget>
#include "vlcthread.h"
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
class VlcWidget : public QWidget
{
    Q_OBJECT
public:
    QLineEdit *UrlLEdit; //Url输入LineEdit
    VlcThread *vlcthread;//Vlc线程
    QPushButton * BtnVlc;//串流按键
   // QMessageBox * MesBox;//提示Box
    explicit VlcWidget(QWidget *parent = nullptr);
signals:
public slots:
    void BtnVlc_clicked();
public:
    void OpenVlc();//开始网络串流
    void SetVlcOption(QStringList Args);//设置VLc参数
    bool SetVlcUrl(QString Url);//设置视频流地址
    void PauseVlc();//暂停vlc播放
    void NextVlc();//继续vlc播放
    void CloseVlc();//关闭vlc播放
    void RestaetVlc();//重启vlc
    void ClearVlc();//清空

};

#endif // VLCWIDGET_H
