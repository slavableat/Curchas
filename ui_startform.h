/********************************************************************************
** Form generated from reading UI file 'startform.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTFORM_H
#define UI_STARTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartForm
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *StartForm)
    {
        if (StartForm->objectName().isEmpty())
            StartForm->setObjectName(QString::fromUtf8("StartForm"));
        StartForm->resize(302, 319);
        QFont font;
        font.setFamilies({QString::fromUtf8("Mongolian Baiti")});
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        StartForm->setFont(font);
        StartForm->setCursor(QCursor(Qt::ArrowCursor));
        StartForm->setMouseTracking(false);
        StartForm->setAutoFillBackground(false);
        StartForm->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 202, 230);"));
        pushButton = new QPushButton(StartForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 40, 241, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Mongolian Baiti")});
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 203, 200);"));
        pushButton_2 = new QPushButton(StartForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 110, 241, 61));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 203, 200);"));
        pushButton_3 = new QPushButton(StartForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 180, 241, 61));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 203, 200);"));

        retranslateUi(StartForm);

        QMetaObject::connectSlotsByName(StartForm);
    } // setupUi

    void retranslateUi(QWidget *StartForm)
    {
        StartForm->setWindowTitle(QCoreApplication::translate("StartForm", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("StartForm", "Start ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartForm", "Graph creator", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StartForm", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartForm: public Ui_StartForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTFORM_H
