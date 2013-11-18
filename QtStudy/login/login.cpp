/*********************************************版本声明*******************************************************************
** 1、本项目所有权归CforQt组织所有;
** 2、所有人可对项目进行下载,做为学习用途;
** 3、所有人可对项目代码进行修改,并提交合并请求;
** 4、贡献代码的开发者拥有组织内成员的同等权益;
** 5、本项目遵循Apache开源协议;
** 6、本项目未经CforQt组织所有成员与代码贡献者同意不得用于商业用途;
**
***********************************************************************************************************************/
//导入头文件
#include "login.h"
#include <QtGui>
#include <QtWidgets>
#include <QDesktopWidget>
#include <QFile>
/**********************************************************************************************************************
 *@说明：实现Login类的构造函数，需要注意的时在实现过程，去掉了作用域的声明，这是因为在头文件中已经声明了作用域
 *@作者：zgkAndhxh
 *@日期：2013-11-16
 **********************************************************************************************************************/
Login::Login(QWidget *parent): QWidget(parent)
{
    //设置用户名输入框
    userLabel = new QLabel(QStringLiteral("用户名："));
    userLabel->setFixedWidth (80);
    userLabel->setAlignment (Qt::AlignRight);
    userInput  = new QLineEdit();
    userInput->setFixedWidth (180);
    userLabel->setBuddy (userInput);
    userLayout = new QHBoxLayout();
    userLayout->addWidget (userLabel);
    userLayout->addWidget (userInput);
    userLayout->setAlignment (Qt::AlignCenter);
    //userLayout->setStretch (1,Qt::StretchTile);
    //设置密码输入框
    passLabel = new QLabel(QStringLiteral("密  码："));
    passLabel->setFixedWidth (80);
    passLabel->setAlignment (Qt::AlignRight);
    passInput = new QLineEdit();
    passInput->setEchoMode (QLineEdit::Password);
    passInput->setFixedWidth (180);
    passLabel->setBuddy (passInput);

    passLayout = new QHBoxLayout;
    passLayout->addWidget (passLabel);
    passLayout->addWidget (passInput);
    passLayout->setAlignment (Qt::AlignCenter);


    //设置按钮对话框
    loginButton = new QPushButton(QStringLiteral("登录"));
    cancleButton = new QPushButton(QStringLiteral("取消"));
    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget (loginButton);
    buttonLayout->addWidget (cancleButton);
    buttonLayout->setAlignment (Qt::AlignCenter);

    //define the signal
    QObject::connect (loginButton,SIGNAL(clicked()),this,SLOT(do_login()));
    QObject::connect (cancleButton,SIGNAL(clicked()),this,SLOT(close()));



    mainLayout = new QVBoxLayout;
    mainLayout->addStretch (10);
    mainLayout->addLayout (userLayout);
    mainLayout->addLayout (passLayout);
    mainLayout->addLayout (buttonLayout);
    mainLayout->addStretch (10);
    mainLayout->setAlignment (Qt::AlignHorizontal_Mask);


    //设置当前窗口的属性
    //设置窗口在屏幕正中显示
    deskTop = QApplication::desktop ();
    move((deskTop->width ()-this->width ())/2,(deskTop->height ()-this->height ())/2);
    //设置窗口布局与大小
    this->setLayout (mainLayout);
    this->setMaximumSize (360,240);
    this->setMinimumSize (360,240);
    // this->adjustSize ();

    //设置背景图片
    this->setAutoFillBackground (true);
    //background
    background.setBrush (QPalette::Background,QBrush(QPixmap(":/img/ui/background")));
    this->setPalette (background);
    this->setWindowTitle ("");
    //this->setWindowFlags (Qt::FramelessWindowHint);
    this->setVisible (true);
}
/**********************************************************************************************************************
 *@说明：析构函数主要用于释放内存,注意内存释放时要理清依赖关系
 *@作者：zgkAndhxh
 *@日期：2013-11-16
 **********************************************************************************************************************/

Login::~Login(){
    delete cancleButton;
    delete loginButton;
    delete passInput;
    delete passLabel;
    delete userInput;
    delete userLabel;
    delete passLayout;
    delete userLayout;
    delete buttonLayout;
    delete mainLayout;
}
/**********************************************************************************************************************
 *@说明：点击登录按钮时触发的事件
 *@作者：zgkAndhxh
 *@日期：2013-11-16
 **********************************************************************************************************************/
bool Login::do_login (){
  //read the username and password from the file:userinfo.cfg
    QFile  file(":/resources/config/userinfo.cfg");
    if(!file.open (QIODevice::ReadOnly)){
        //file read failed
    }
    QString str="";
    int i = 0;
    while(!file.atEnd() && i <= 1){
      str+= file.readLine ();
      i++;

    }
    QString username = str.split ("\r\n")[0].split ("=")[1];
    QString pass = str.split ("\r\n")[1].split ("=")[1];
    userInput->setText (username);
    passInput->setText (pass);
    return false;
}

