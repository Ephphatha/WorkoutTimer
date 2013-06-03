/********************************************************************************
** Form generated from reading UI file 'workouttimer.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKOUTTIMER_H
#define UI_WORKOUTTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkoutTimerClass
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *routineGroupBox;
    QVBoxLayout *verticalLayout;
    QListView *routineListView;
    QWidget *toolbarWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *addToolButton;
    QToolButton *removeToolButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *upToolButton;
    QToolButton *downToolButton;
    QWidget *settingsWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *settingsGroupBox;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *intervalTypeLabel;
    QComboBox *intervalTypeComboBox;
    QLabel *setsLabel;
    QSpinBox *setsSpinBox;
    QLabel *timerStyleLabel;
    QComboBox *timerStyleComboBox;
    QLabel *setsAtPeakLabel;
    QSpinBox *setsAtPeakSpinBox;
    QGroupBox *workoutPeriodsGroupBox;
    QFormLayout *formLayout_3;
    QLabel *workoutStartAtLabel;
    QLabel *workoutPeakAtLabel;
    QLabel *workoutEndAtLabel;
    QDoubleSpinBox *workoutStartAtDoubleSpinBox;
    QDoubleSpinBox *workoutPeakAtDoubleSpinBox;
    QDoubleSpinBox *workoutEndAtDoubleSpinBox;
    QGroupBox *restPeriodsGroupBox;
    QFormLayout *formLayout_2;
    QLabel *restStartAtLabel;
    QDoubleSpinBox *restStartAtDoubleSpinBox;
    QLabel *restPeakAtLabel;
    QDoubleSpinBox *restPeakAtDoubleSpinBox;
    QLabel *restEndAtLabel;
    QDoubleSpinBox *restEndAtDoubleSpinBox;
    QSpacerItem *upperVerticalSpacer;
    QPushButton *startButton;
    QSpacerItem *lowerVerticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WorkoutTimerClass)
    {
        if (WorkoutTimerClass->objectName().isEmpty())
            WorkoutTimerClass->setObjectName(QStringLiteral("WorkoutTimerClass"));
        WorkoutTimerClass->resize(600, 562);
        QIcon icon;
        icon.addFile(QStringLiteral("WorkoutTimer.ico"), QSize(), QIcon::Normal, QIcon::Off);
        WorkoutTimerClass->setWindowIcon(icon);
        actionLoad = new QAction(WorkoutTimerClass);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(WorkoutTimerClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(WorkoutTimerClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(WorkoutTimerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 0, 3, 3);
        routineGroupBox = new QGroupBox(centralWidget);
        routineGroupBox->setObjectName(QStringLiteral("routineGroupBox"));
        verticalLayout = new QVBoxLayout(routineGroupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 5, 0);
        routineListView = new QListView(routineGroupBox);
        routineListView->setObjectName(QStringLiteral("routineListView"));
        routineListView->setDragEnabled(true);
        routineListView->setDragDropMode(QAbstractItemView::InternalMove);
        routineListView->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout->addWidget(routineListView);

        toolbarWidget = new QWidget(routineGroupBox);
        toolbarWidget->setObjectName(QStringLiteral("toolbarWidget"));
        horizontalLayout = new QHBoxLayout(toolbarWidget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addToolButton = new QToolButton(toolbarWidget);
        addToolButton->setObjectName(QStringLiteral("addToolButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/WorkoutTimer/Resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addToolButton->setIcon(icon1);

        horizontalLayout->addWidget(addToolButton, 0, Qt::AlignLeft);

        removeToolButton = new QToolButton(toolbarWidget);
        removeToolButton->setObjectName(QStringLiteral("removeToolButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/WorkoutTimer/Resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeToolButton->setIcon(icon2);

        horizontalLayout->addWidget(removeToolButton, 0, Qt::AlignLeft);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        upToolButton = new QToolButton(toolbarWidget);
        upToolButton->setObjectName(QStringLiteral("upToolButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/WorkoutTimer/Resources/arrow_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upToolButton->setIcon(icon3);
        upToolButton->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(upToolButton);

        downToolButton = new QToolButton(toolbarWidget);
        downToolButton->setObjectName(QStringLiteral("downToolButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/WorkoutTimer/Resources/arrow_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        downToolButton->setIcon(icon4);
        downToolButton->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(downToolButton);


        verticalLayout->addWidget(toolbarWidget);


        horizontalLayout_2->addWidget(routineGroupBox);

        settingsWidget = new QWidget(centralWidget);
        settingsWidget->setObjectName(QStringLiteral("settingsWidget"));
        verticalLayout_2 = new QVBoxLayout(settingsWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 5);
        settingsGroupBox = new QGroupBox(settingsWidget);
        settingsGroupBox->setObjectName(QStringLiteral("settingsGroupBox"));
        formLayout = new QFormLayout(settingsGroupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nameLabel = new QLabel(settingsGroupBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(settingsGroupBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        intervalTypeLabel = new QLabel(settingsGroupBox);
        intervalTypeLabel->setObjectName(QStringLiteral("intervalTypeLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, intervalTypeLabel);

        intervalTypeComboBox = new QComboBox(settingsGroupBox);
        intervalTypeComboBox->setObjectName(QStringLiteral("intervalTypeComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, intervalTypeComboBox);

        setsLabel = new QLabel(settingsGroupBox);
        setsLabel->setObjectName(QStringLiteral("setsLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, setsLabel);

        setsSpinBox = new QSpinBox(settingsGroupBox);
        setsSpinBox->setObjectName(QStringLiteral("setsSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, setsSpinBox);

        timerStyleLabel = new QLabel(settingsGroupBox);
        timerStyleLabel->setObjectName(QStringLiteral("timerStyleLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, timerStyleLabel);

        timerStyleComboBox = new QComboBox(settingsGroupBox);
        timerStyleComboBox->setObjectName(QStringLiteral("timerStyleComboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, timerStyleComboBox);

        setsAtPeakLabel = new QLabel(settingsGroupBox);
        setsAtPeakLabel->setObjectName(QStringLiteral("setsAtPeakLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, setsAtPeakLabel);

        setsAtPeakSpinBox = new QSpinBox(settingsGroupBox);
        setsAtPeakSpinBox->setObjectName(QStringLiteral("setsAtPeakSpinBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, setsAtPeakSpinBox);


        verticalLayout_2->addWidget(settingsGroupBox, 0, Qt::AlignTop);

        workoutPeriodsGroupBox = new QGroupBox(settingsWidget);
        workoutPeriodsGroupBox->setObjectName(QStringLiteral("workoutPeriodsGroupBox"));
        formLayout_3 = new QFormLayout(workoutPeriodsGroupBox);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        workoutStartAtLabel = new QLabel(workoutPeriodsGroupBox);
        workoutStartAtLabel->setObjectName(QStringLiteral("workoutStartAtLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, workoutStartAtLabel);

        workoutPeakAtLabel = new QLabel(workoutPeriodsGroupBox);
        workoutPeakAtLabel->setObjectName(QStringLiteral("workoutPeakAtLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, workoutPeakAtLabel);

        workoutEndAtLabel = new QLabel(workoutPeriodsGroupBox);
        workoutEndAtLabel->setObjectName(QStringLiteral("workoutEndAtLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, workoutEndAtLabel);

        workoutStartAtDoubleSpinBox = new QDoubleSpinBox(workoutPeriodsGroupBox);
        workoutStartAtDoubleSpinBox->setObjectName(QStringLiteral("workoutStartAtDoubleSpinBox"));
        workoutStartAtDoubleSpinBox->setDecimals(0);
        workoutStartAtDoubleSpinBox->setMinimum(1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, workoutStartAtDoubleSpinBox);

        workoutPeakAtDoubleSpinBox = new QDoubleSpinBox(workoutPeriodsGroupBox);
        workoutPeakAtDoubleSpinBox->setObjectName(QStringLiteral("workoutPeakAtDoubleSpinBox"));
        workoutPeakAtDoubleSpinBox->setDecimals(0);
        workoutPeakAtDoubleSpinBox->setMinimum(1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, workoutPeakAtDoubleSpinBox);

        workoutEndAtDoubleSpinBox = new QDoubleSpinBox(workoutPeriodsGroupBox);
        workoutEndAtDoubleSpinBox->setObjectName(QStringLiteral("workoutEndAtDoubleSpinBox"));
        workoutEndAtDoubleSpinBox->setDecimals(0);
        workoutEndAtDoubleSpinBox->setMinimum(1);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, workoutEndAtDoubleSpinBox);


        verticalLayout_2->addWidget(workoutPeriodsGroupBox, 0, Qt::AlignTop);

        restPeriodsGroupBox = new QGroupBox(settingsWidget);
        restPeriodsGroupBox->setObjectName(QStringLiteral("restPeriodsGroupBox"));
        formLayout_2 = new QFormLayout(restPeriodsGroupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        restStartAtLabel = new QLabel(restPeriodsGroupBox);
        restStartAtLabel->setObjectName(QStringLiteral("restStartAtLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, restStartAtLabel);

        restStartAtDoubleSpinBox = new QDoubleSpinBox(restPeriodsGroupBox);
        restStartAtDoubleSpinBox->setObjectName(QStringLiteral("restStartAtDoubleSpinBox"));
        restStartAtDoubleSpinBox->setDecimals(0);
        restStartAtDoubleSpinBox->setMinimum(1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, restStartAtDoubleSpinBox);

        restPeakAtLabel = new QLabel(restPeriodsGroupBox);
        restPeakAtLabel->setObjectName(QStringLiteral("restPeakAtLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, restPeakAtLabel);

        restPeakAtDoubleSpinBox = new QDoubleSpinBox(restPeriodsGroupBox);
        restPeakAtDoubleSpinBox->setObjectName(QStringLiteral("restPeakAtDoubleSpinBox"));
        restPeakAtDoubleSpinBox->setDecimals(0);
        restPeakAtDoubleSpinBox->setMinimum(1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, restPeakAtDoubleSpinBox);

        restEndAtLabel = new QLabel(restPeriodsGroupBox);
        restEndAtLabel->setObjectName(QStringLiteral("restEndAtLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, restEndAtLabel);

        restEndAtDoubleSpinBox = new QDoubleSpinBox(restPeriodsGroupBox);
        restEndAtDoubleSpinBox->setObjectName(QStringLiteral("restEndAtDoubleSpinBox"));
        restEndAtDoubleSpinBox->setDecimals(0);
        restEndAtDoubleSpinBox->setMinimum(1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, restEndAtDoubleSpinBox);


        verticalLayout_2->addWidget(restPeriodsGroupBox, 0, Qt::AlignTop);

        upperVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(upperVerticalSpacer);

        startButton = new QPushButton(settingsWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout_2->addWidget(startButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        lowerVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(lowerVerticalSpacer);


        horizontalLayout_2->addWidget(settingsWidget, 0, Qt::AlignRight);

        WorkoutTimerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WorkoutTimerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        WorkoutTimerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(WorkoutTimerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WorkoutTimerClass->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        nameLabel->setBuddy(nameLineEdit);
        intervalTypeLabel->setBuddy(intervalTypeComboBox);
        setsLabel->setBuddy(setsSpinBox);
        timerStyleLabel->setBuddy(timerStyleComboBox);
        workoutStartAtLabel->setBuddy(workoutStartAtDoubleSpinBox);
        workoutPeakAtLabel->setBuddy(workoutPeakAtDoubleSpinBox);
        workoutEndAtLabel->setBuddy(workoutEndAtDoubleSpinBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(nameLineEdit, intervalTypeComboBox);
        QWidget::setTabOrder(intervalTypeComboBox, setsSpinBox);
        QWidget::setTabOrder(setsSpinBox, timerStyleComboBox);
        QWidget::setTabOrder(timerStyleComboBox, addToolButton);
        QWidget::setTabOrder(addToolButton, removeToolButton);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(WorkoutTimerClass);
        QObject::connect(actionExit, SIGNAL(triggered()), WorkoutTimerClass, SLOT(close()));
        QObject::connect(actionLoad, SIGNAL(triggered()), WorkoutTimerClass, SLOT(load()));
        QObject::connect(actionSave, SIGNAL(triggered()), WorkoutTimerClass, SLOT(save()));
        QObject::connect(routineListView, SIGNAL(indexesMoved(QModelIndexList)), WorkoutTimerClass, SLOT(routinesMoved(QModelIndexList)));

        QMetaObject::connectSlotsByName(WorkoutTimerClass);
    } // setupUi

    void retranslateUi(QMainWindow *WorkoutTimerClass)
    {
        WorkoutTimerClass->setWindowTitle(QApplication::translate("WorkoutTimerClass", "WorkoutTimer", 0));
        actionLoad->setText(QApplication::translate("WorkoutTimerClass", "Load", 0));
        actionSave->setText(QApplication::translate("WorkoutTimerClass", "Save", 0));
        actionExit->setText(QApplication::translate("WorkoutTimerClass", "Exit", 0));
        routineGroupBox->setTitle(QApplication::translate("WorkoutTimerClass", "Routine", 0));
        addToolButton->setText(QApplication::translate("WorkoutTimerClass", "Add", 0));
        removeToolButton->setText(QApplication::translate("WorkoutTimerClass", "Remove", 0));
        upToolButton->setText(QApplication::translate("WorkoutTimerClass", "Up", 0));
        downToolButton->setText(QApplication::translate("WorkoutTimerClass", "Down", 0));
        settingsGroupBox->setTitle(QApplication::translate("WorkoutTimerClass", "Interval Settings", 0));
        nameLabel->setText(QApplication::translate("WorkoutTimerClass", "Name:", 0));
        intervalTypeLabel->setText(QApplication::translate("WorkoutTimerClass", "Interval Type:", 0));
        intervalTypeComboBox->clear();
        intervalTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("WorkoutTimerClass", "Ladder", 0)
         << QApplication::translate("WorkoutTimerClass", "Pyramid", 0)
         << QApplication::translate("WorkoutTimerClass", "Plateau", 0)
         << QApplication::translate("WorkoutTimerClass", "Constant", 0)
        );
        setsLabel->setText(QApplication::translate("WorkoutTimerClass", "Sets:", 0));
        timerStyleLabel->setText(QApplication::translate("WorkoutTimerClass", "Timer:", 0));
        timerStyleComboBox->clear();
        timerStyleComboBox->insertItems(0, QStringList()
         << QApplication::translate("WorkoutTimerClass", "Countdown", 0)
         << QApplication::translate("WorkoutTimerClass", "Count up", 0)
        );
        setsAtPeakLabel->setText(QApplication::translate("WorkoutTimerClass", "Sets at Peak:", 0));
        workoutPeriodsGroupBox->setTitle(QApplication::translate("WorkoutTimerClass", "Workout Periods", 0));
        workoutStartAtLabel->setText(QApplication::translate("WorkoutTimerClass", "Start at:", 0));
        workoutPeakAtLabel->setText(QApplication::translate("WorkoutTimerClass", "Peak at:", 0));
        workoutEndAtLabel->setText(QApplication::translate("WorkoutTimerClass", "End at:", 0));
        workoutStartAtDoubleSpinBox->setSuffix(QApplication::translate("WorkoutTimerClass", " seconds", 0));
        workoutPeakAtDoubleSpinBox->setSuffix(QApplication::translate("WorkoutTimerClass", " seconds", 0));
        workoutEndAtDoubleSpinBox->setSuffix(QApplication::translate("WorkoutTimerClass", " seconds", 0));
        restPeriodsGroupBox->setTitle(QApplication::translate("WorkoutTimerClass", "Rest Periods", 0));
        restStartAtLabel->setText(QApplication::translate("WorkoutTimerClass", "Start at:", 0));
        restStartAtDoubleSpinBox->setSuffix(QApplication::translate("WorkoutTimerClass", " seconds", 0));
        restPeakAtLabel->setText(QApplication::translate("WorkoutTimerClass", "Peak at:", 0));
        restPeakAtDoubleSpinBox->setSuffix(QApplication::translate("WorkoutTimerClass", " seconds", 0));
        restEndAtLabel->setText(QApplication::translate("WorkoutTimerClass", "End at:", 0));
        restEndAtDoubleSpinBox->setSuffix(QApplication::translate("WorkoutTimerClass", " seconds", 0));
        startButton->setText(QApplication::translate("WorkoutTimerClass", "Start Routine", 0));
        menuFile->setTitle(QApplication::translate("WorkoutTimerClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class WorkoutTimerClass: public Ui_WorkoutTimerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKOUTTIMER_H
