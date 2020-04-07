#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
#define N 512


void display()
{
    cout<<"      1.Play"<<endl;
    cout<<"      2.Pause"<<endl;
    cout<<"      3.Continue"<<endl;
    cout<<"      4.MoveNext"<<endl;
    cout<<"      5.MovePrivious"<<endl;
    cout<<"      6.Exit"<<endl;
    cout<<"Please input the choose:";
}

const char* produce_command(string music_list[],int music_number,int current_number=0)
{
    string com="madplay";
    for(int i=current_number;i<music_number;i++)
    {
        com=com+" "+"/home/liugang/Desktop/music/"+music_list[i];
    }
    com=com+"  < /dev/null > /dev/null 2>1& ";
    const char *command=com.c_str();
    return command;
}

int main()
{
    system("ls /home/liugang/Desktop/music/ > /home/liugang/Desktop/music_list");
    string buffer;
    string music_list[N];
    fstream fin("/home/liugang/Desktop/music_list");
    int music_number=0;

    while(getline(fin,buffer))
    {
        music_list[music_number]=buffer;
        music_number++;
    }
    const char *command=produce_command(music_list,music_number);
    bool flag=true;
    bool start=true;
    int current_number=0;
    while(flag)
    {
        int select;
        display();
        cin>>select;
        if(select==1)
        {
            if(start==false)    system("killall -KILL madplay");
            system(command);
            start=false;
            cout<<music_list[current_number]<<"  is playing---"<<endl;
            
        }
        else if(select==2)
        {
            system("killall -STOP madplay");
            cout<<music_list[current_number]<<"  is puase---"<<endl;
        }
        else if(select==3)
        {
            system("killall -CONT madplay");
            cout<<music_list[current_number]<<"  is replaying---"<<endl;
        }
        else if(select==4)
        {
            system("killall -KILL madplay");
            current_number++;
            if(current_number>=music_number)    current_number=0;
            const char *nextcommand=produce_command(music_list,music_number,current_number);
            system(nextcommand);
            cout<<music_list[current_number]<<"  is playing---"<<endl;
        }
        else if(select==5)
        {
            system("killall -KILL madplay");
            current_number--;
            if(current_number<0)    current_number=music_number-1;
            const char *precommand=produce_command(music_list,music_number,current_number);
            system(precommand);
            cout<<music_list[current_number]<<"  is playing---"<<endl;
        }
        else 
        {
            flag=false;
            system("killall -KILL madplay");
        }
    }
    cout<<"--------play end---------"<<endl;
   

    
    return 0;
}
