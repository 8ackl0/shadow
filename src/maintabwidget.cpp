// =====================================================================================
// 
//       Filename:  MainTabWidget.cpp
//
//    Description:  标签显示管理
//
//        Version:  1.0
//        Created:  2013年03月07日 14时05分08秒
//       Revision:  none
//       Compiler:  cl
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "MainTabWidget.h"
#include "LinkFileWidget.h"
#include "LinkProcessWidget.h"
#include "LinkServerWidget.h"
#include "LinkControlWidget.h"
#include "LinkCmdWidget.h"

MainTabWidget::MainTabWidget()
{
	createMainWeiget();

	this->setTabPosition(QTabWidget::South);	// 设置标签显示在窗口下端
	this->setDocumentMode(false);				// 设置是否显示边框
	
	this->addTab(linkFileWidget, tr("远程文件管理"));
	this->addTab(linkProcessWidget, tr("远程进程管理"));
	this->addTab(linkServerWidget, tr("远程服务管理"));
	this->addTab(linkControlWidget, tr("远程控制命令"));
	this->addTab(linkCmdWidget, tr("远程cmd控制"));
}

MainTabWidget::~MainTabWidget()
{

}

void MainTabWidget::createMainWeiget()
{
	linkFileWidget = new LinkFileWidget();
	linkProcessWidget = new LinkProcessWidget();
	linkServerWidget = new LinkServerWidget();
	linkControlWidget = new LinkControlWidget();
	linkCmdWidget = new LinkCmdWidget();
}
