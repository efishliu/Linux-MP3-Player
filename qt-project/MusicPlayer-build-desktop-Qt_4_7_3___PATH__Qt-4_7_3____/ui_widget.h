/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Thu Jul 5 19:01:06 2018
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QListWidget *ui_music_list;
    QListWidget *music_lrc;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *show1;
    QPushButton *pushButton_8;
    QSlider *horizontalSlider_2;
    QLabel *label_4;
    QLabel *voice;
    QLabel *start_time;
    QLabel *end_time;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(649, 494);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 20, 151, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 370, 411, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 420, 51, 26));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 420, 61, 26));
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 420, 61, 26));
        pushButton_3->setFont(font1);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(290, 420, 61, 26));
        pushButton_4->setFont(font1);
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(370, 420, 61, 26));
        pushButton_5->setFont(font1);
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(570, 430, 31, 20));
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(541, 430, 20, 20));
        ui_music_list = new QListWidget(Widget);
        ui_music_list->setObjectName(QString::fromUtf8("ui_music_list"));
        ui_music_list->setGeometry(QRect(60, 80, 191, 221));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        ui_music_list->setFont(font2);
        music_lrc = new QListWidget(Widget);
        music_lrc->setObjectName(QString::fromUtf8("music_lrc"));
        music_lrc->setGeometry(QRect(285, 80, 271, 221));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 60, 71, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 60, 81, 16));
        label_3->setFont(font1);
        show1 = new QLabel(Widget);
        show1->setObjectName(QString::fromUtf8("show1"));
        show1->setGeometry(QRect(120, 330, 381, 16));
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(50, 420, 61, 26));
        pushButton_8->setFont(font1);
        horizontalSlider_2 = new QSlider(Widget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(550, 400, 81, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(550, 330, 81, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        voice = new QLabel(Widget);
        voice->setObjectName(QString::fromUtf8("voice"));
        voice->setGeometry(QRect(580, 360, 21, 16));
        QFont font4;
        font4.setPointSize(10);
        voice->setFont(font4);
        start_time = new QLabel(Widget);
        start_time->setObjectName(QString::fromUtf8("start_time"));
        start_time->setGeometry(QRect(30, 370, 31, 16));
        end_time = new QLabel(Widget);
        end_time->setObjectName(QString::fromUtf8("end_time"));
        end_time->setGeometry(QRect(490, 370, 31, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "MUSIC PLAYER", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "countine", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "<<|", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Widget", "|>", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Widget", ">>|", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Widget", "||", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Widget", "             +", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Widget", "-", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "music_list", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "music_lrc", 0, QApplication::UnicodeUTF8));
        show1->setText(QString());
        pushButton_8->setText(QApplication::translate("Widget", "stop", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "voice value", 0, QApplication::UnicodeUTF8));
        voice->setText(QApplication::translate("Widget", "50", 0, QApplication::UnicodeUTF8));
        start_time->setText(QApplication::translate("Widget", "00:00", 0, QApplication::UnicodeUTF8));
        end_time->setText(QApplication::translate("Widget", "00:00", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
