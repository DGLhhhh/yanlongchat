/********************************************************************************
** Form generated from reading UI file 'slideshowdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDESHOWDLG_H
#define UI_SLIDESHOWDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "picanimationwid.h"
#include "picbutton.h"
#include "picstatebtn.h"
#include "prelistwid.h"

QT_BEGIN_NAMESPACE

class Ui_SlideShowDlg
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *slideShow;
    QGridLayout *gridLayout;
    QWidget *slideprewid;
    QVBoxLayout *verticalLayout_2;
    PicButton *slidpreBtn;
    QWidget *slidenextwid;
    QVBoxLayout *verticalLayout_3;
    PicButton *slidenextBtn;
    PicAnimationWid *picAnimation;
    QHBoxLayout *horizontalLayout_4;
    PicStateBtn *playBtn;
    PicButton *closeBtn;
    QWidget *preShow;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    PreListWid *preListWidget;

    void setupUi(QDialog *SlideShowDlg)
    {
        if (SlideShowDlg->objectName().isEmpty())
            SlideShowDlg->setObjectName("SlideShowDlg");
        SlideShowDlg->resize(441, 311);
        verticalLayout = new QVBoxLayout(SlideShowDlg);
        verticalLayout->setObjectName("verticalLayout");
        slideShow = new QWidget(SlideShowDlg);
        slideShow->setObjectName("slideShow");
        slideShow->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(slideShow);
        gridLayout->setObjectName("gridLayout");
        slideprewid = new QWidget(slideShow);
        slideprewid->setObjectName("slideprewid");
        slideprewid->setMinimumSize(QSize(80, 0));
        slideprewid->setMaximumSize(QSize(80, 16777215));
        verticalLayout_2 = new QVBoxLayout(slideprewid);
        verticalLayout_2->setObjectName("verticalLayout_2");
        slidpreBtn = new PicButton(slideprewid);
        slidpreBtn->setObjectName("slidpreBtn");
        slidpreBtn->setIconSize(QSize(64, 64));

        verticalLayout_2->addWidget(slidpreBtn);


        gridLayout->addWidget(slideprewid, 2, 0, 1, 1);

        slidenextwid = new QWidget(slideShow);
        slidenextwid->setObjectName("slidenextwid");
        slidenextwid->setMinimumSize(QSize(80, 0));
        slidenextwid->setMaximumSize(QSize(80, 16777215));
        verticalLayout_3 = new QVBoxLayout(slidenextwid);
        verticalLayout_3->setObjectName("verticalLayout_3");
        slidenextBtn = new PicButton(slidenextwid);
        slidenextBtn->setObjectName("slidenextBtn");
        slidenextBtn->setIconSize(QSize(64, 64));

        verticalLayout_3->addWidget(slidenextBtn);


        gridLayout->addWidget(slidenextwid, 2, 2, 1, 1);

        picAnimation = new PicAnimationWid(slideShow);
        picAnimation->setObjectName("picAnimation");

        gridLayout->addWidget(picAnimation, 2, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        playBtn = new PicStateBtn(slideShow);
        playBtn->setObjectName("playBtn");

        horizontalLayout_4->addWidget(playBtn);

        closeBtn = new PicButton(slideShow);
        closeBtn->setObjectName("closeBtn");

        horizontalLayout_4->addWidget(closeBtn);


        gridLayout->addLayout(horizontalLayout_4, 1, 2, 1, 1);


        verticalLayout->addWidget(slideShow);

        preShow = new QWidget(SlideShowDlg);
        preShow->setObjectName("preShow");
        horizontalLayout = new QHBoxLayout(preShow);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(preShow);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 120));
        widget->setMaximumSize(QSize(16777215, 120));
        preListWidget = new PreListWid(widget);
        preListWidget->setObjectName("preListWidget");
        preListWidget->setGeometry(QRect(10, 10, 16777215, 110));
        preListWidget->setMinimumSize(QSize(0, 110));
        preListWidget->setMaximumSize(QSize(16777215, 110));
        preListWidget->setFlow(QListView::LeftToRight);

        horizontalLayout->addWidget(widget);


        verticalLayout->addWidget(preShow);

        verticalLayout->setStretch(0, 7);
        verticalLayout->setStretch(1, 1);

        retranslateUi(SlideShowDlg);

        QMetaObject::connectSlotsByName(SlideShowDlg);
    } // setupUi

    void retranslateUi(QDialog *SlideShowDlg)
    {
        SlideShowDlg->setWindowTitle(QCoreApplication::translate("SlideShowDlg", "Dialog", nullptr));
        slidpreBtn->setText(QString());
        slidenextBtn->setText(QString());
        playBtn->setText(QString());
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SlideShowDlg: public Ui_SlideShowDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDESHOWDLG_H
