/*********************************************************
* @说明：程序主文件类                                       *
* @日期：2013-11-15                                       *
* @作者：zgkAndhxh                                        *
**********************************************************/
//引入头文件
#include <login/login.h>
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>

/*********程序主入口*********/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /***********程序启动画面开始****************/
    QSplashScreen screen;
    //设置启动图片，此处采用资源文件别名
    screen.setPixmap (QPixmap(":/img/ui/splash"));
    //正常显示，可选择最大化，最小化、默认
    screen.showNormal ();
    //显示信息
    screen.showMessage (QObject::tr ("启动画面显示"),Qt::AlignBottom,Qt::red);
    //显示登录窗口
    Login login;
    login.show();
    screen.finish (login.parentWidget());
    /***********程序启动画面开始****************/
    return a.exec();
}
