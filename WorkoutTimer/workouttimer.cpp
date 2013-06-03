#include "workouttimer.h"

#include <QFileDialog>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include <QMetaEnum>

#include <QSettings>

WorkoutTimer::WorkoutTimer(QWidget *parent)
  : QMainWindow(parent)
{
	this->ui.setupUi(this);

  {
    QMetaEnum enumerator = Interval::staticMetaObject.enumerator(Interval::staticMetaObject.indexOfEnumerator("Type"));
    this->ui.intervalTypeComboBox->clear();
    for (int i = 0; i < enumerator.keyCount(); ++i)
    {
      this->ui.intervalTypeComboBox->addItem(enumerator.key(i));
    }

    enumerator = Interval::staticMetaObject.enumerator(Interval::staticMetaObject.indexOfEnumerator("Direction"));
    this->ui.timerStyleComboBox->clear();
    for (int i = 0; i < enumerator.keyCount(); ++i)
    {
      this->ui.timerStyleComboBox->addItem(enumerator.key(i));
    }
  }

  this->toolButtonSignalMapper = new QSignalMapper(this);
  this->toolButtonSignalMapper->setMapping(this->ui.addToolButton, this->ui.addToolButton->text());
  this->toolButtonSignalMapper->setMapping(this->ui.removeToolButton, this->ui.removeToolButton->text());
  this->toolButtonSignalMapper->setMapping(this->ui.upToolButton, this->ui.upToolButton->text());
  this->toolButtonSignalMapper->setMapping(this->ui.downToolButton, this->ui.downToolButton->text());

  QObject::connect(this->ui.addToolButton, SIGNAL(clicked()), this->toolButtonSignalMapper, SLOT(map()));
  QObject::connect(this->ui.removeToolButton, SIGNAL(clicked()), this->toolButtonSignalMapper, SLOT(map()));
  QObject::connect(this->ui.upToolButton, SIGNAL(clicked()), this->toolButtonSignalMapper, SLOT(map()));
  QObject::connect(this->ui.downToolButton, SIGNAL(clicked()), this->toolButtonSignalMapper, SLOT(map()));

  QObject::connect(this->toolButtonSignalMapper, SIGNAL(mapped(QString)), this, SLOT(performAction(QString)));

  this->routine.setHorizontalHeaderLabels(QStringList("Interval Name"));

  this->ui.routineListView->setModel(&(this->routine));

  QObject::connect(this->ui.routineListView->selectionModel(), SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
    this, SLOT(activeIntervalChanged(const QModelIndex &)));
}

WorkoutTimer::~WorkoutTimer()
{

}

void WorkoutTimer::load()
{
	QSettings settings;

	QString fileName = QFileDialog::getOpenFileName(
		this,
		tr("Load Routine"),
		settings.value(
			"routineDirectory",
			QApplication::applicationDirPath()).toString(),
		tr("Routine files (*.json)"));

	QFile file(fileName);
  QFileInfo fileDetails(file);

  settings.setValue("routineDirectory", fileDetails.path());

	if (file.open(QIODevice::ReadOnly))
	{
    QJsonDocument in;

    in.fromJson(file.readAll());

    if (in.isObject())
    {
      QJsonObject root = in.object();

      QJsonValue val = root["Routine"];
      if (val.isArray())
      {
        QJsonArray routine = val.toArray();

        for each (QJsonValue intervalJson in routine)
        {
          if (intervalJson.isObject())
          {
            Interval interval(intervalJson.toObject());
            QStandardItem *intervalWrapper = new QStandardItem(interval.Name());
            intervalWrapper->setData(QVariant::fromValue(interval), IntervalRole);
            this->routine.appendRow(intervalWrapper);
          }
        }
      }
    }

		file.close();
	}
}

void WorkoutTimer::save()
{
  QSettings settings;

	QString fileName = QFileDialog::getSaveFileName(
    this,
    tr("Save Routine"),
		settings.value(
			"routineDirectory",
			QApplication::applicationDirPath()).toString(),
    tr("Routine files (*.json)"));

	QFile file(fileName);
  QFileInfo fileDetails(file);

  settings.setValue("routineDirectory", fileDetails.path());

	if (file.open(QIODevice::WriteOnly))
	{
    QJsonArray routine;

    for (int i = 0; i < this->routine.rowCount(); ++i)
    {
      routine.append(this->routine.item(i)->data(IntervalRole).value<Interval>());
    }

    QJsonObject root;
    root["Routine"] = routine;
		
    QJsonDocument out(root);

    file.write(out.toJson());

		file.close();
	}
}

void WorkoutTimer::activeIntervalChanged(const QModelIndex &current)
{
  if (QStandardItem* intervalWrapper = this->routine.itemFromIndex(current))
  {
    const Interval &interval = intervalWrapper->data(IntervalRole).value<Interval>();
  
    this->ui.nameLineEdit->setText(interval.Name());
    this->ui.intervalTypeComboBox->setCurrentIndex(interval.GetType());
    this->ui.setsSpinBox->setValue(interval.Sets());
    this->ui.setsAtPeakSpinBox->setValue(interval.SetsAtPeak());
    this->ui.timerStyleComboBox->setCurrentIndex(interval.CountDirection());

    this->ui.workoutStartAtDoubleSpinBox->setValue(interval.WorkoutPeriodStartAt());
    this->ui.workoutPeakAtDoubleSpinBox->setValue(interval.WorkoutPeriodPeakAt());
    this->ui.workoutEndAtDoubleSpinBox->setValue(interval.WorkoutPeriodEndAt());

    this->ui.restStartAtDoubleSpinBox->setValue(interval.RestPeriodStartAt());
    this->ui.restPeakAtDoubleSpinBox->setValue(interval.RestPeriodStartAt());
    this->ui.restEndAtDoubleSpinBox->setValue(interval.RestPeriodStartAt());
    
    this->ui.nameLineEdit->setEnabled(true);
    this->ui.intervalTypeComboBox->setEnabled(true);
    this->ui.timerStyleComboBox->setEnabled(true);

    switch (interval.GetType())
    {
    case Interval::Type::LADDER:
      this->ui.setsSpinBox->setEnabled(true);
      this->ui.setsAtPeakSpinBox->setEnabled(false);

      this->ui.workoutStartAtDoubleSpinBox->setEnabled(true);
      this->ui.workoutPeakAtDoubleSpinBox->setEnabled(false);
      this->ui.workoutEndAtDoubleSpinBox->setEnabled(true);
      
      this->ui.restStartAtDoubleSpinBox->setEnabled(true);
      this->ui.restPeakAtDoubleSpinBox->setEnabled(false);
      this->ui.restEndAtDoubleSpinBox->setEnabled(true);
      break;


    case Interval::Type::PYRAMID:
      this->ui.setsSpinBox->setEnabled(true);
      this->ui.setsAtPeakSpinBox->setEnabled(false);

      this->ui.workoutStartAtDoubleSpinBox->setEnabled(true);
      this->ui.workoutPeakAtDoubleSpinBox->setEnabled(true);
      this->ui.workoutEndAtDoubleSpinBox->setEnabled(true);
      
      this->ui.restStartAtDoubleSpinBox->setEnabled(true);
      this->ui.restPeakAtDoubleSpinBox->setEnabled(true);
      this->ui.restEndAtDoubleSpinBox->setEnabled(true);
      break;

    case Interval::Type::PLATEAU:
      this->ui.setsSpinBox->setEnabled(true);
      this->ui.setsAtPeakSpinBox->setEnabled(true);

      this->ui.workoutStartAtDoubleSpinBox->setEnabled(true);
      this->ui.workoutPeakAtDoubleSpinBox->setEnabled(true);
      this->ui.workoutEndAtDoubleSpinBox->setEnabled(true);
      
      this->ui.restStartAtDoubleSpinBox->setEnabled(true);
      this->ui.restPeakAtDoubleSpinBox->setEnabled(true);
      this->ui.restEndAtDoubleSpinBox->setEnabled(true);
      break;

    case Interval::Type::CONSTANT:
      this->ui.setsSpinBox->setEnabled(true);
      this->ui.setsAtPeakSpinBox->setEnabled(false);

      this->ui.workoutStartAtDoubleSpinBox->setEnabled(false);
      this->ui.workoutPeakAtDoubleSpinBox->setEnabled(true);
      this->ui.workoutEndAtDoubleSpinBox->setEnabled(false);
      
      this->ui.restStartAtDoubleSpinBox->setEnabled(false);
      this->ui.restPeakAtDoubleSpinBox->setEnabled(true);
      this->ui.restEndAtDoubleSpinBox->setEnabled(false);
      break;
    }
  }
  else
  {
    this->ui.nameLineEdit->setEnabled(false);
    this->ui.intervalTypeComboBox->setEnabled(false);
    this->ui.timerStyleComboBox->setEnabled(false);
    
    this->ui.setsSpinBox->setEnabled(false);
    this->ui.setsAtPeakSpinBox->setEnabled(false);

    this->ui.workoutStartAtDoubleSpinBox->setEnabled(false);
    this->ui.workoutPeakAtDoubleSpinBox->setEnabled(false);
    this->ui.workoutEndAtDoubleSpinBox->setEnabled(false);
      
    this->ui.restStartAtDoubleSpinBox->setEnabled(false);
    this->ui.restPeakAtDoubleSpinBox->setEnabled(false);
    this->ui.restEndAtDoubleSpinBox->setEnabled(false);
  }
}

void WorkoutTimer::performAction(const QString &action)
{
  if (action == this->ui.addToolButton->text())
  {
    Interval interval;
    QStandardItem *intervalWrapper = new QStandardItem(interval.Name());
    intervalWrapper->setData(QVariant::fromValue(interval), IntervalRole);
    this->routine.appendRow(intervalWrapper);
  }
  else if (action == this->ui.removeToolButton->text())
  {
    this->routine.removeRow(this->ui.routineListView->selectionModel()->currentIndex().row());
  }
  else if (action == this->ui.upToolButton->text())
  {
    this->routine.moveRow(
      QModelIndex(),
      this->ui.routineListView->selectionModel()->currentIndex().row(),
      QModelIndex(),
      this->ui.routineListView->selectionModel()->currentIndex().row() - 1);
  }
  else if (action == this->ui.downToolButton->text())
  {
    this->routine.moveRow(
      QModelIndex(),
      this->ui.routineListView->selectionModel()->currentIndex().row(),
      QModelIndex(),
      this->ui.routineListView->selectionModel()->currentIndex().row() + 1);
  }
}
