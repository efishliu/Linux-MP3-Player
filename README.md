## 概述
Linux-MP3-Player是在Linux环境下运行的一个图形化界面的MP3播放器，主要功能包括：播放、暂停、继续、停止、循环播放、上一曲、下一曲、退出、歌曲显示等功能。  
本项目分为两个部分：  
1.编写字符界面模式的音乐播放器并移植到ARM。([字符界面程序与ARM移植](https://github.com/efishliu/Linux-MP3-Player/tree/master/arm))  
2.在Linux平台（Redhat或Ubuntu）环境下配置QT环境，设计一个基于图形化界面的MP3播放器。  
以下主要介绍基于图形化界面的MP3播放器。  

## 工具与环境
ubuntu-16.04qt-4.7.3,Qt-Creator,madplay库  

## 图形化MP3播放器的实现
* **主程序流程图**  
<div align=center>
<img src="https://github.com/efishliu/Linux-MP3-Player/blob/master/image/flow-chart.png" width = 50% height = 50% />
</div>  

* **MP3播放器的Qt实现**  

| 代码 | 描述 |
|:----: |:----: |
| [main.cpp]() | MP3播放器主入口  |
| [widget.cpp]() | 槽函数的实现，包括定时器，进度条，歌词，播放等功能的实现  |
| [widget.h]() |  槽函数的声明 |
| [widget.ui]() | MP3播放器的UI界面设计  |
| [music2.qss]() | UI界面的美化  |

* **MP3播放器的运行界面**  
<div align=center>
<img src="https://github.com/efishliu/Linux-MP3-Player/blob/master/image/mp3-player.png" width = 50% height = 50% />
</div>  
