/********************************************************************************
** Form generated from reading UI file 'PID_uppermonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PID_UPPERMONITOR_H
#define UI_PID_UPPERMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PID_uppermonitorClass
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_0;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_freshen;
    QFrame *line_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_outloopWrite;
    QFrame *line;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_inloopWrite;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_outlooptime;
    QDoubleSpinBox *doubleSpinBox_outloopP;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_outloopI;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_outloopD;
    QFrame *line_2;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *doubleSpinBox_inloopP;
    QLabel *label_7;
    QSpinBox *spinBox_inlooptime;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_inloopI;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_inloopD;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_Charts;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_portName;
    QComboBox *comboBox_portName;
    QLabel *Label_baudRate;
    QComboBox *comboBox_baudRate;
    QPushButton *pushButton_switch;

    void setupUi(QWidget *PID_uppermonitorClass)
    {
        if (PID_uppermonitorClass->objectName().isEmpty())
            PID_uppermonitorClass->setObjectName(QStringLiteral("PID_uppermonitorClass"));
        PID_uppermonitorClass->resize(937, 712);
        verticalLayout = new QVBoxLayout(PID_uppermonitorClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        line_8 = new QFrame(PID_uppermonitorClass);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_0 = new QRadioButton(PID_uppermonitorClass);
        radioButton_0->setObjectName(QStringLiteral("radioButton_0"));

        verticalLayout_3->addWidget(radioButton_0);

        radioButton_1 = new QRadioButton(PID_uppermonitorClass);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));

        verticalLayout_3->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(PID_uppermonitorClass);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(PID_uppermonitorClass);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        radioButton_4 = new QRadioButton(PID_uppermonitorClass);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_4->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(PID_uppermonitorClass);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_4->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(PID_uppermonitorClass);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout_4->addWidget(radioButton_6);

        radioButton_7 = new QRadioButton(PID_uppermonitorClass);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));

        verticalLayout_4->addWidget(radioButton_7);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_freshen = new QPushButton(PID_uppermonitorClass);
        pushButton_freshen->setObjectName(QStringLiteral("pushButton_freshen"));
        pushButton_freshen->setMinimumSize(QSize(90, 90));
        pushButton_freshen->setMaximumSize(QSize(90, 90));

        horizontalLayout_2->addWidget(pushButton_freshen);


        verticalLayout->addLayout(horizontalLayout_2);

        line_7 = new QFrame(PID_uppermonitorClass);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(PID_uppermonitorClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 40));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_outloopWrite = new QPushButton(PID_uppermonitorClass);
        pushButton_outloopWrite->setObjectName(QStringLiteral("pushButton_outloopWrite"));

        horizontalLayout_3->addWidget(pushButton_outloopWrite);

        line = new QFrame(PID_uppermonitorClass);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        label = new QLabel(PID_uppermonitorClass);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(16777215, 40));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButton_inloopWrite = new QPushButton(PID_uppermonitorClass);
        pushButton_inloopWrite->setObjectName(QStringLiteral("pushButton_inloopWrite"));

        horizontalLayout_3->addWidget(pushButton_inloopWrite);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(PID_uppermonitorClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        spinBox_outlooptime = new QSpinBox(PID_uppermonitorClass);
        spinBox_outlooptime->setObjectName(QStringLiteral("spinBox_outlooptime"));
        spinBox_outlooptime->setMaximum(300);

        gridLayout_2->addWidget(spinBox_outlooptime, 0, 1, 1, 1);

        doubleSpinBox_outloopP = new QDoubleSpinBox(PID_uppermonitorClass);
        doubleSpinBox_outloopP->setObjectName(QStringLiteral("doubleSpinBox_outloopP"));

        gridLayout_2->addWidget(doubleSpinBox_outloopP, 0, 3, 1, 1);

        label_4 = new QLabel(PID_uppermonitorClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(PID_uppermonitorClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        doubleSpinBox_outloopI = new QDoubleSpinBox(PID_uppermonitorClass);
        doubleSpinBox_outloopI->setObjectName(QStringLiteral("doubleSpinBox_outloopI"));

        gridLayout_2->addWidget(doubleSpinBox_outloopI, 1, 1, 1, 1);

        label_6 = new QLabel(PID_uppermonitorClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 1, 2, 1, 1);

        doubleSpinBox_outloopD = new QDoubleSpinBox(PID_uppermonitorClass);
        doubleSpinBox_outloopD->setObjectName(QStringLiteral("doubleSpinBox_outloopD"));

        gridLayout_2->addWidget(doubleSpinBox_outloopD, 1, 3, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_2);

        line_2 = new QFrame(PID_uppermonitorClass);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        doubleSpinBox_inloopP = new QDoubleSpinBox(PID_uppermonitorClass);
        doubleSpinBox_inloopP->setObjectName(QStringLiteral("doubleSpinBox_inloopP"));

        gridLayout_3->addWidget(doubleSpinBox_inloopP, 0, 3, 1, 1);

        label_7 = new QLabel(PID_uppermonitorClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        spinBox_inlooptime = new QSpinBox(PID_uppermonitorClass);
        spinBox_inlooptime->setObjectName(QStringLiteral("spinBox_inlooptime"));
        spinBox_inlooptime->setMaximum(300);

        gridLayout_3->addWidget(spinBox_inlooptime, 0, 1, 1, 1);

        label_8 = new QLabel(PID_uppermonitorClass);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 0, 2, 1, 1);

        label_9 = new QLabel(PID_uppermonitorClass);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        doubleSpinBox_inloopI = new QDoubleSpinBox(PID_uppermonitorClass);
        doubleSpinBox_inloopI->setObjectName(QStringLiteral("doubleSpinBox_inloopI"));

        gridLayout_3->addWidget(doubleSpinBox_inloopI, 1, 1, 1, 1);

        label_10 = new QLabel(PID_uppermonitorClass);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 1, 2, 1, 1);

        doubleSpinBox_inloopD = new QDoubleSpinBox(PID_uppermonitorClass);
        doubleSpinBox_inloopD->setObjectName(QStringLiteral("doubleSpinBox_inloopD"));

        gridLayout_3->addWidget(doubleSpinBox_inloopD, 1, 3, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(verticalLayout_2);

        line_3 = new QFrame(PID_uppermonitorClass);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        horizontalLayout_Charts = new QHBoxLayout();
        horizontalLayout_Charts->setSpacing(6);
        horizontalLayout_Charts->setObjectName(QStringLiteral("horizontalLayout_Charts"));

        verticalLayout->addLayout(horizontalLayout_Charts);

        line_9 = new QFrame(PID_uppermonitorClass);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_portName = new QLabel(PID_uppermonitorClass);
        label_portName->setObjectName(QStringLiteral("label_portName"));
        label_portName->setMaximumSize(QSize(60, 20));
        label_portName->setBaseSize(QSize(60, 20));

        horizontalLayout->addWidget(label_portName);

        comboBox_portName = new QComboBox(PID_uppermonitorClass);
        comboBox_portName->setObjectName(QStringLiteral("comboBox_portName"));

        horizontalLayout->addWidget(comboBox_portName);

        Label_baudRate = new QLabel(PID_uppermonitorClass);
        Label_baudRate->setObjectName(QStringLiteral("Label_baudRate"));
        Label_baudRate->setEnabled(true);
        Label_baudRate->setMaximumSize(QSize(60, 20));
        Label_baudRate->setSizeIncrement(QSize(50, 20));
        Label_baudRate->setBaseSize(QSize(50, 20));

        horizontalLayout->addWidget(Label_baudRate);

        comboBox_baudRate = new QComboBox(PID_uppermonitorClass);
        comboBox_baudRate->setObjectName(QStringLiteral("comboBox_baudRate"));

        horizontalLayout->addWidget(comboBox_baudRate);

        pushButton_switch = new QPushButton(PID_uppermonitorClass);
        pushButton_switch->setObjectName(QStringLiteral("pushButton_switch"));

        horizontalLayout->addWidget(pushButton_switch);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PID_uppermonitorClass);

        QMetaObject::connectSlotsByName(PID_uppermonitorClass);
    } // setupUi

    void retranslateUi(QWidget *PID_uppermonitorClass)
    {
        PID_uppermonitorClass->setWindowTitle(QApplication::translate("PID_uppermonitorClass", "PID\350\260\203\345\217\202\350\275\257\344\273\266\342\200\224\342\200\224SLDX", Q_NULLPTR));
        radioButton_0->setText(QApplication::translate("PID_uppermonitorClass", "#0(\345\272\225\347\233\230\347\224\265\346\234\2721)", Q_NULLPTR));
        radioButton_1->setText(QApplication::translate("PID_uppermonitorClass", "#1(\345\272\225\347\233\230\347\224\265\346\234\2722)", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("PID_uppermonitorClass", "#2(\345\272\225\347\233\230\347\224\265\346\234\2723)", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("PID_uppermonitorClass", "#3(\345\272\225\347\233\230\347\224\265\346\234\2724)", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("PID_uppermonitorClass", "#4(\344\272\221\345\217\260yaw)", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("PID_uppermonitorClass", "#5(\344\272\221\345\217\260pitch)", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("PID_uppermonitorClass", "#6(\345\244\207\347\224\250)", Q_NULLPTR));
        radioButton_7->setText(QApplication::translate("PID_uppermonitorClass", "#7(\345\244\207\347\224\250)", Q_NULLPTR));
        pushButton_freshen->setText(QApplication::translate("PID_uppermonitorClass", "\345\210\267\346\226\260\n"
"\347\212\266\346\200\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("PID_uppermonitorClass", "\345\244\226\347\216\257PID:", Q_NULLPTR));
        pushButton_outloopWrite->setText(QApplication::translate("PID_uppermonitorClass", "\345\206\231\345\205\245", Q_NULLPTR));
        label->setText(QApplication::translate("PID_uppermonitorClass", "\345\206\205\347\216\257PID:", Q_NULLPTR));
        pushButton_inloopWrite->setText(QApplication::translate("PID_uppermonitorClass", "\345\206\231\345\205\245", Q_NULLPTR));
        label_3->setText(QApplication::translate("PID_uppermonitorClass", "\351\207\207\346\240\267\346\227\266\351\227\264:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PID_uppermonitorClass", "P\345\217\202\346\225\260:", Q_NULLPTR));
        label_5->setText(QApplication::translate("PID_uppermonitorClass", "I\345\217\202\346\225\260:", Q_NULLPTR));
        label_6->setText(QApplication::translate("PID_uppermonitorClass", "D\345\217\202\346\225\260:", Q_NULLPTR));
        label_7->setText(QApplication::translate("PID_uppermonitorClass", "\351\207\207\346\240\267\346\227\266\351\227\264:", Q_NULLPTR));
        label_8->setText(QApplication::translate("PID_uppermonitorClass", "P\345\217\202\346\225\260:", Q_NULLPTR));
        label_9->setText(QApplication::translate("PID_uppermonitorClass", "I\345\217\202\346\225\260:", Q_NULLPTR));
        label_10->setText(QApplication::translate("PID_uppermonitorClass", "D\345\217\202\346\225\260:", Q_NULLPTR));
        label_portName->setText(QApplication::translate("PID_uppermonitorClass", " \344\270\262\345\217\243\345\217\267:", Q_NULLPTR));
        Label_baudRate->setText(QApplication::translate("PID_uppermonitorClass", " \346\263\242\347\211\271\347\216\207:", Q_NULLPTR));
        comboBox_baudRate->clear();
        comboBox_baudRate->insertItems(0, QStringList()
         << QApplication::translate("PID_uppermonitorClass", "9600", Q_NULLPTR)
         << QApplication::translate("PID_uppermonitorClass", "115200", Q_NULLPTR)
        );
        pushButton_switch->setText(QApplication::translate("PID_uppermonitorClass", "\350\277\236\346\216\245\350\256\276\345\244\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PID_uppermonitorClass: public Ui_PID_uppermonitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PID_UPPERMONITOR_H
