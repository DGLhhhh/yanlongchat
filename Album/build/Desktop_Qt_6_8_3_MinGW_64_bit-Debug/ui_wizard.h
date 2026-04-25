/********************************************************************************
** Form generated from reading UI file 'wizard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARD_H
#define UI_WIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizard>
#include "confirmpage.h"
#include "prosetpage.h"

QT_BEGIN_NAMESPACE

class Ui_Wizard
{
public:
    ProSetPage *wizardPage1;
    QGridLayout *gridLayout_2;
    ConfirmPage *wizardPage2;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWizard *Wizard)
    {
        if (Wizard->objectName().isEmpty())
            Wizard->setObjectName("Wizard");
        Wizard->resize(512, 310);
        Wizard->setStyleSheet(QString::fromUtf8(""));
        wizardPage1 = new ProSetPage();
        wizardPage1->setObjectName("wizardPage1");
        gridLayout_2 = new QGridLayout(wizardPage1);
        gridLayout_2->setObjectName("gridLayout_2");
        Wizard->addPage(wizardPage1);
        wizardPage2 = new ConfirmPage();
        wizardPage2->setObjectName("wizardPage2");
        verticalLayout_2 = new QVBoxLayout(wizardPage2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        Wizard->addPage(wizardPage2);

        retranslateUi(Wizard);

        QMetaObject::connectSlotsByName(Wizard);
    } // setupUi

    void retranslateUi(QWizard *Wizard)
    {
        Wizard->setWindowTitle(QCoreApplication::translate("Wizard", "Wizard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wizard: public Ui_Wizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARD_H
