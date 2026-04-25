/********************************************************************************
** Form generated from reading UI file 'picshow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICSHOW_H
#define UI_PICSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "picbutton.h"

QT_BEGIN_NAMESPACE

class Ui_PicShow
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    PicButton *previousBtn;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    PicButton *nextBtn;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PicShow)
    {
        if (PicShow->objectName().isEmpty())
            PicShow->setObjectName("PicShow");
        PicShow->resize(400, 300);
        PicShow->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(PicShow);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        label = new QLabel(PicShow);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        widget = new QWidget(PicShow);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(80, 0));
        widget->setMaximumSize(QSize(80, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        previousBtn = new PicButton(widget);
        previousBtn->setObjectName("previousBtn");
        previousBtn->setStyleSheet(QString::fromUtf8(""));
        previousBtn->setIconSize(QSize(64, 64));

        verticalLayout_2->addWidget(previousBtn);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(PicShow);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(80, 0));
        widget_2->setMaximumSize(QSize(80, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        nextBtn = new PicButton(widget_2);
        nextBtn->setObjectName("nextBtn");
        nextBtn->setIconSize(QSize(64, 64));

        verticalLayout_3->addWidget(nextBtn);


        gridLayout->addWidget(widget_2, 1, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(PicShow);

        QMetaObject::connectSlotsByName(PicShow);
    } // setupUi

    void retranslateUi(QDialog *PicShow)
    {
        PicShow->setWindowTitle(QCoreApplication::translate("PicShow", "Dialog", nullptr));
        label->setText(QString());
        previousBtn->setText(QString());
        nextBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PicShow: public Ui_PicShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICSHOW_H
