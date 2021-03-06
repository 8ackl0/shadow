// =====================================================================================
// 
//	   Filename:  ScreenShotDialog.cpp
//
//	Description:  屏幕捕获对话框实现文件
//
//		Version:  1.0
//		Created:  2013年03月08日 21时15分20秒
//	   Revision:  none
//	   Compiler:  cl
//
//		 Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//		Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "ScreenShotDialog.h"

ScreenShotDialog::ScreenShotDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);

	originalPixmap = QPixmap();
	label->setPixmap(QPixmap(":/res/images/desktop.png"));

	connect(startButton, SIGNAL(clicked()), this, SLOT(ScreenShotNative()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(saveScreenShot()));

	setWindowIcon(QIcon(":/res/images/screenshot.png"));
}

ScreenShotDialog::~ScreenShotDialog()
{

}

void ScreenShotDialog::newScreenShot()
{
	
}

void ScreenShotDialog::ScreenShotNative()
{
	originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
	label->setPixmap(originalPixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void ScreenShotDialog::saveScreenShot()
{
	QString format = "png";
	QString initialPath = QDir::currentPath() + tr("/untitled.") + format;

	QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"),
													initialPath,
													tr("%1 文件 (*.%2);;所有文件 (*)")
													.arg(format.toUpper())
													.arg(format));
	if (!fileName.isEmpty()) {
		originalPixmap.save(fileName, format.toAscii());
	}
}
