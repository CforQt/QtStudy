/*********************************************版本声明*******************************************************************
** 1、本项目所有权归CforQt组织所有;
** 2、所有人可对项目进行下载,做为学习用途;
** 3、所有人可对项目代码进行修改,并提交合并请求;
** 4、贡献代码的开发者拥有组织内成员的同等权益;
** 5、本项目遵循Apache开源协议;
** 6、本项目未经CforQt组织所有成员与代码贡献者同意不得用于商业用途;
**
***********************************************************************************************************************/
#ifndef LOGIN_H
#define LOGIN_H
#include<QWidget>
#include<stdlib.h>
//导入头文件，从编译效率上来讲，头文件放到实现类文件中引入

/***********************************************************************************************************************
 *@说明：声明登录类，继承QWidget基类
 *@作者：zgkAndhxh
 *@日期：2013-11-16
 *@
 **********************************************************************************************************************/
//C++中采用 ： 做为继承标志，区别于Java中的extends
//public 代表公共域，允许所有的类访问
//声明类
class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QDesktopWidget;
class QPalette;
class Login :public QWidget{
    //Qt特有的语法，只有声明了Q_OBJECT才可以使用信号和槽，通过Moc自动生成C++编译识别的代码
    Q_OBJECT
    //声明公共的构造函数
public:
    Login(QWidget *parent = 0);
    ~Login();
    //定义成员变量，处理较验结果
    bool result;

    //声明信息响应事件（槽）
private slots:
    bool do_login();
    //声明私有成员，一般将当前组件声明为私有的，信号也设为私有的
private:
    QLabel *msgLabel;
    QLabel *userLabel;
    QLabel *passLabel;
    QLineEdit *userInput;
    QLineEdit *passInput;
    QPushButton *loginButton;
    QPushButton *cancleButton;
    QHBoxLayout *userLayout;
    QHBoxLayout *passLayout;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QDesktopWidget  *deskTop;
    QPalette background;
};

#endif // LOGIN_H
