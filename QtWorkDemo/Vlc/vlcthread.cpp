#include "vlcthread.h"
#include "vlcwidget.h"
VlcThread::VlcThread(QObject *parent) : QThread(parent)
{
    setObjectName("VlcThread");

    Stopflag =false;//状态位置位
    Playflag =false;
    this->vlcInst=nullptr;// 初始化指针
    this->vlcMedia=nullptr;
    this->vlcPlayer=nullptr;
    qDebug() << "Init Vlc OK Version::" << " "<<libvlc_get_version();

}

void VlcThread::SetOption(QString option)
{
    if (vlcMedia != nullptr) {
        QByteArray data = option.toUtf8();
        const char *arg = data.constData();
        libvlc_media_add_option(vlcMedia, arg);
    }
}
bool VlcThread::Init()
{
    const char *tempArg="";
    const char *VlcArgs[9] ={"-I",
                             "dummy",
                             "--no-osd",
                             "--no-stats",
                             "--ignore-config",
                             "--no-video-on-top",
                             "--no-video-title-show",
                             "--no-snapshot-preview",
                             tempArg};
    vlcInst = libvlc_new(sizeof(VlcArgs)/sizeof(VlcArgs[0]),VlcArgs);
    if (vlcInst == nullptr){
            return false;
    }
    vlcMedia =libvlc_media_new_location(vlcInst,this->Url.toUtf8().constData());
    vlcPlayer = libvlc_media_player_new_from_media(vlcMedia);
    if (vlcPlayer == nullptr){
           return false;
    }
    VlcWidget *w = (VlcWidget *)this->parent();
    libvlc_media_player_set_xwindow(vlcPlayer, w->winId());
    //设置硬件加速 none auto any d3d11va dxva2
    SetOption(QString(":avcodec-hw=%1").arg("none"));
    //设置通信协议 tcp udp
    SetOption(QString(":rtsp-%1").arg("tcp"));
    //设置缓存时间 默认500毫秒
    SetOption(QString(":network-caching=%1").arg(300));
    libvlc_media_player_play(vlcPlayer);
}

void VlcThread::SetUrl(QString Url)
{
    this->Url = Url;
}

void VlcThread::Play()
{
    Playflag =true;
    this->Init();
}

bool VlcThread::Free()
{
    if (vlcInst != nullptr) {
        libvlc_release(vlcInst);
        vlcInst = nullptr;
    }

    if (vlcMedia != nullptr) {
        libvlc_media_release(vlcMedia);
        vlcMedia = nullptr;
    }

    if (vlcPlayer != nullptr) {
        libvlc_media_player_release(vlcPlayer);
        vlcPlayer = nullptr;
    }
}

void VlcThread::Stop()
{
    Stopflag = true;
}

void VlcThread::Close()
{
    if (this->isRunning()) {
          this->Stop();
          this->quit();
          this->wait(3000);
      }
 QTimer::singleShot(5, this, SLOT(clear()));

}

void VlcThread::run()
{
   while(!Stopflag) {
       msleep(1);
   }
   Free();
   Stopflag = false;
   Playflag = false;
}

