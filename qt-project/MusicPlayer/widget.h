#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    int playtime;
    int playrow;
    bool firstflag;
    QTimer *timer=new QTimer();
    ~Widget();
    


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_ui_music_list_doubleClicked();

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void start_counting();

    void on_horizontalSlider_sliderReleased();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
