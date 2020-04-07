#include "widget.h"
#include "ui_widget.h"
#include <sys/types.h>
#include <fstream>
#include <QString>
#include <phonon/AudioOutput>
#include "sstream"


using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
//----------------------------初始化ui----------------------------
    ui->setupUi(this);
    this->setWindowTitle(tr("Music Player"));
    playrow=0;
    playtime=0;
    firstflag=true;

//----------------------------加载歌曲清单-------------------------
    system("ls /home/liugang/Desktop/music/ > /home/liugang/Desktop/music_list");
    fstream fin("/home/liugang/Desktop/music_list");
    std::string buffer;
    int music_number=0;
    while(getline(fin,buffer))
    {
        const char* music=buffer.c_str();
        ui->ui_music_list->addItem(tr(music));
        music_number++;
    }
//----------------------------初始化进度条--------------------------
    ui->ui_music_list->setCurrentRow(0);
    ui->horizontalSlider_2->setMinimum(0);
    ui->horizontalSlider_2->setMaximum(100);
    ui->horizontalSlider_2->setValue(90);
    system("amixer -q sset PCM 90%");
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(180);
//----------------------------定时器连接函数--------------------------
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(start_counting()));

}

//---------------------------ui析构函数-----------------------------
Widget::~Widget()
{
    delete ui;
    system("killall -KILL madplay");
}

//--------------------------播放时间转换成字符串-----------------------
QString caltime(int playtime)
{
    QString qplaytime=QString("%1").arg(playtime);
    if(playtime<60)
    {
        if(playtime<10)
            qplaytime="00:0"+qplaytime;
        else
            qplaytime="00:"+qplaytime;

    }
    else
    {
        QString secondtime=QString("%1").arg(playtime%60);
        QString minutime=QString("%1").arg(playtime/60);
        QString second;
        QString minu;
        if((playtime%60)<10)
        {
            second=":0"+secondtime;
        }
        else     second=":"+secondtime;

        if((playtime/60)<10)
        {
            minu="0"+minutime;
        }
        else   minu=minutime;
        qplaytime=minu+second;

    }
    return qplaytime;
}

//-----------------int to string -----------------------
string intToString(int i)
{
    stringstream ss;
    ss << i;
    string s1 = ss.str();
    return s1;
}

//---------------slots------------

//-----------------------------定时器槽函数------------------------------
void Widget::start_counting()
{
    playtime++;

//--------------start-time-----------
   QString qplaytime=caltime(playtime);
    ui->start_time->setText(qplaytime);

//--------------horizontalSlider-----------------
    ui->horizontalSlider->setValue(playtime);
    int music_row=ui->ui_music_list->currentRow();
    if(playtime%3==0&&playtime>=15&&music_row==0){
        ui->music_lrc->setCurrentRow((playtime-16)/3);

    }

}

//------------------------------单击play按钮--------------------------------
void Widget::on_pushButton_3_clicked()
{
    if(!firstflag) system("killall -KILL madplay ");
    int curMusicRow=ui->ui_music_list->currentRow();
    if(curMusicRow==0)
    {
        ui->end_time->setText("03:28");
        fstream finj("/home/liugang/Desktop/lrc/JoelHanson-TravelingLight");
        std::string buffer;
        while(getline(finj,buffer))
        {
            const char* musiclrc=buffer.c_str();
            ui->music_lrc->addItem(tr(musiclrc));
        }
    }
    if(curMusicRow==1)
    {
        ui->end_time->setText("03:44");
        ui->music_lrc->deleteLater();
    }
    if(curMusicRow==2)
    {
        ui->end_time->setText("04:18");
        ui->music_lrc->deleteLater();
    }
    QString currentMusic=ui->ui_music_list->currentItem()->text();
    ui->show1->setText(currentMusic);
    string com="madplay /home/liugang/Desktop/music/"+currentMusic.toStdString()+" < /dev/null > /dev/null 2>1&";
    const char* command=com.c_str();
    system(command);
    firstflag=false;
    timer->start(1000);

}

//-----------------------------单击下一首按钮-------------------------------
void Widget::on_pushButton_4_clicked()
{
    system("killall -KILL madplay");
    int currentMusicRow=ui->ui_music_list->currentRow();
    int nextMusicRow=++currentMusicRow;
    if(nextMusicRow>=ui->ui_music_list->count())    nextMusicRow=0;
    ui->ui_music_list->setCurrentRow(nextMusicRow);
    QString currentMusic=ui->ui_music_list->currentItem()->text();
    ui->show1->setText(currentMusic);
    string com="madplay /home/liugang/Desktop/music/"+currentMusic.toStdString()+" < /dev/null > /dev/null 2>1&";
    const char* command=com.c_str();
    system(command);
    int curMusicRow=ui->ui_music_list->currentRow();
    if(curMusicRow==0) ui->end_time->setText("03:28");
    if(curMusicRow==1) ui->end_time->setText("03:44");
    if(curMusicRow==2) ui->end_time->setText("04:18");
    playtime=0;
    timer->start();
}

//-----------------------------单击上一首按钮---------------------------------
void Widget::on_pushButton_2_clicked()
{
    system("killall -KILL madplay");
    int currentMusicRow=ui->ui_music_list->currentRow();
    int preMusicRow=--currentMusicRow;
    if(preMusicRow<0) preMusicRow=ui->ui_music_list->count()-1;
    ui->ui_music_list->setCurrentRow(preMusicRow);

    QString currentMusic=ui->ui_music_list->currentItem()->text();
    ui->show1->setText(currentMusic);
    string com="madplay /home/liugang/Desktop/music/"+currentMusic.toStdString()+" < /dev/null > /dev/null 2>1&";
    const char* command=com.c_str();
    system(command);
    int curMusicRow=ui->ui_music_list->currentRow();
    if(curMusicRow==0) ui->end_time->setText("03:28");
    if(curMusicRow==1) ui->end_time->setText("03:44");
    if(curMusicRow==2) ui->end_time->setText("04:18");
    playtime=0;
    timer->start();
}

//-----------------------------单击countine按钮-------------------------------
void Widget::on_pushButton_clicked()
{
    system("killall -CONT madplay");
    timer->start();
}

//------------------------------单击暂停按钮-----------------------------------
void Widget::on_pushButton_5_clicked()
{
    system("killall -STOP madplay");
    timer->stop();
}

//------------------------------单击stop按钮----------------------------------
void Widget::on_pushButton_8_clicked()
{
    system("killall -KILL madplay");
    playtime=0;
    timer->stop();
    ui->start_time->setText("00:00");
    ui->end_time->setText("00:00");
    ui->show1->setText(" ");
    ui->horizontalSlider->setValue(0);
    firstflag=true;

}

//-------------------------------歌曲清单双击播放-------------------------------
void Widget::on_ui_music_list_doubleClicked()
{
    system("killall -KILL madplay ");
    QString currentMusic=ui->ui_music_list->currentItem()->text();
    ui->show1->setText(currentMusic);
    string com="madplay /home/liugang/Desktop/music/"+currentMusic.toStdString()+" < /dev/null > /dev/null 2>1&";
    const char* command=com.c_str();
    system(command);
    playtime=0;
    timer->start(1000);
}

//-------------------------------音量活动slider-----------------------------------
void Widget::on_horizontalSlider_2_valueChanged(int value)
{

    QString voice_value=QString("%1").arg(value);
    ui->voice->setText(voice_value);
    string svoice_value=intToString(value);
    string linux_voice_com="amixer -q sset PCM "+svoice_value+"%";
    const char* linux_voice_command=linux_voice_com.c_str();
    system(linux_voice_command);
}

//------------------------------单击音量 - 按钮------------------------------------
void Widget::on_pushButton_7_clicked()
{
    QString current_voice=ui->voice->text();
    int sub_voice=current_voice.toInt()-1;
    ui->horizontalSlider_2->setValue(sub_voice);
    QString voice_value=QString("%1").arg(sub_voice);
    ui->voice->setText(voice_value);
    string svoice_value=intToString(sub_voice);
    string linux_voice_com="amixer -q sset PCM "+svoice_value+"%";
    const char* linux_voice_command=linux_voice_com.c_str();
    system(linux_voice_command);
}

//------------------------------单击音量 + 按钮------------------------------------
void Widget::on_pushButton_6_clicked()
{
    QString current_voice=ui->voice->text();
    int add_voice=current_voice.toInt()+1;
    ui->horizontalSlider_2->setValue(add_voice);
    QString voice_value=QString("%1").arg(add_voice);
    ui->voice->setText(voice_value);
    string svoice_value=intToString(add_voice);
    string linux_voice_com="amixer -q sset PCM "+svoice_value+"%";
    const char* linux_voice_command=linux_voice_com.c_str();
    system(linux_voice_command);
}

//------------------------------歌曲进度条------------------------------------------
void Widget::on_horizontalSlider_sliderReleased()
{
    system("killall -KILL madplay ");
    QString currentMusic=ui->ui_music_list->currentItem()->text();
    int slidertime=ui->horizontalSlider->value();
    playtime=slidertime;
    QString qplaytime=caltime(playtime);

    string com="madplay /home/liugang/Desktop/music/"+currentMusic.toStdString()+" -s "+qplaytime.toStdString()+" < /dev/null > /dev/null 2>1&";
    const char* command=com.c_str();
    system(command);
    timer->start();
}
