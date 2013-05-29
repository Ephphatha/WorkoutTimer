#ifndef WORKOUTTIMER_H
#define WORKOUTTIMER_H

#include <QtWidgets/QMainWindow>
#include "ui_workouttimer.h"

#include <QSignalMapper>
#include <QStandardItemModel>

#include "Interval.h"

class WorkoutTimer : public QMainWindow
{
	Q_OBJECT

public:
	WorkoutTimer(QWidget *parent = 0);
	~WorkoutTimer();

public slots:
	void load();
	void save();

  void activeIntervalChanged(const QModelIndex &current);
  void performAction(const QString &action);

private:
	Ui::WorkoutTimerClass ui;

  QSignalMapper *toolButtonSignalMapper;

  QStandardItemModel routine;

  enum Roles {
    IntervalRole = Qt::UserRole + 1,
  };
};

#endif // WORKOUTTIMER_H
