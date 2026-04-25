/********************************************************************************
** Form generated from reading UI file 'protree.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTREE_H
#define UI_PROTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <protreewidget.h>

QT_BEGIN_NAMESPACE

class Ui_ProTree
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_pro;
    ProTreeWidget *treeWidget;

    void setupUi(QWidget *ProTree)
    {
        if (ProTree->objectName().isEmpty())
            ProTree->setObjectName("ProTree");
        ProTree->resize(378, 363);
        ProTree->setMinimumSize(QSize(378, 0));
        ProTree->setMaximumSize(QSize(378, 16777215));
        ProTree->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(ProTree);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_pro = new QLabel(ProTree);
        label_pro->setObjectName("label_pro");

        verticalLayout->addWidget(label_pro);

        treeWidget = new ProTreeWidget(ProTree);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setHeaderHidden(true);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);

        verticalLayout_4->addLayout(verticalLayout);


        retranslateUi(ProTree);

        QMetaObject::connectSlotsByName(ProTree);
    } // setupUi

    void retranslateUi(QWidget *ProTree)
    {
        ProTree->setWindowTitle(QCoreApplication::translate("ProTree", "Form", nullptr));
        label_pro->setText(QCoreApplication::translate("ProTree", "\351\241\271\347\233\256\345\210\227\350\241\250:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProTree: public Ui_ProTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTREE_H
