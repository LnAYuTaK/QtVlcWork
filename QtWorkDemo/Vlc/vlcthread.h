#ifndef VLCTHREAD_H
#define VLCTHREAD_H

#include <QThread>
#include <QDebug>
#include <libvlc.h>
#include <libvlc_renderer_discoverer.h>
#include <libvlc_media.h>
#include <libvlc_media_player.h>
#include <libvlc_media_list.h>
#include <libvlc_media_list_player.h>
#include <libvlc_media_library.h>
#include <libvlc_media_discoverer.h>
#include <libvlc_events.h>
#include <libvlc_dialog.h>
#include <libvlc_vlm.h>
#include <deprecated.h>
#include <QtGui>
class VlcThread : public QThread
{
public:
    explicit VlcThread(QObject *parent = nullptr);
    bool Playflag;
    bool Stopflag;
    void virtual run();
    void SetUrl(QString Url);
    void SetOption(QString option);
    void Play();
    void Stop();
    void Close();
    bool Init();
    bool Free();
private:
    QString Url; //视频流地址
    QStringList Option;
    libvlc_instance_t *vlcInst;         //载体对象
    libvlc_media_t *vlcMedia;           //媒体对象
    libvlc_media_player_t *vlcPlayer;   //播放对象
signals:
    //收到图片信号
    void receiveImage(const QImage &image);
public slots:
};

#endif // VLCTHREAD_H
