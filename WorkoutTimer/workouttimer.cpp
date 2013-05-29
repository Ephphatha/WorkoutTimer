#include "workouttimer.h"

#include <QFileDialog>
#include <QSettings>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

WorkoutTimer::WorkoutTimer(QWidget *parent)
  : QMainWindow(parent)
{
	this->ui.setupUi(this);

  if (this->ui.intervalTypeComboBox->count() == Interval::Type::Types().size())
  {
    for (int i = 0; i < Interval::Type::Types().size(); ++i)
    {
      if (this->ui.intervalTypeComboBox->itemText(i) != Interval::Type::Types()[i])
      {
        this->ui.intervalTypeComboBox->setItemText(i, Interval::Type::Types()[i]);
      }
    }
  }
  else
  {
    this->ui.intervalTypeComboBox->clear();
    this->ui.intervalTypeComboBox->addItems(Interval::Type::Types());
  }
  
  if (this->ui.timerStyleComboBox->count() == Interval::Direction::Directions().size())
  {
    for (int i = 0; i < Interval::Direction::Directions().size(); ++i)
    {
      if (this->ui.timerStyleComboBox->itemText(i) != Interval::Direction::Directions()[i])
      {
        this->ui.timerStyleComboBox->setItemText(i, Interval::Direction::Directions()[i]);
      }
    }
  }
  else
  {
    this->ui.timerStyleComboBox->clear();
    this->ui.timerStyleComboBox->addItems(Interval::Direction::Directions());
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
    this->ui.intervalTypeComboBox->setCurrentIndex(interval.GetType().Value());
    this->ui.timeStepSpinBox->setValue(static_cast<int>(interval.TimeStep()));
    this->ui.startingMultiplierSpinBox->setValue(static_cast<int>(interval.StartMultiplier()));
    this->ui.peakMultiplierSpinBox->setValue(static_cast<int>(interval.PeakMultiplier()));
    this->ui.endingMultiplierSpinBox->setValue(static_cast<int>(interval.EndMultiplier()));
    this->ui.stepsAtPeakSpinBox->setValue(static_cast<int>(interval.StepsAtPeak()));
    this->ui.timerStyleComboBox->setCurrentIndex(interval.CountDirection().Value());
    
    this->ui.nameLineEdit->setEnabled(true);
    this->ui.intervalTypeComboBox->setEnabled(true);
    this->ui.timerStyleComboBox->setEnabled(true);

    if (interval.GetType() == "Ladder")
    {
      this->ui.timeStepSpinBox->setEnabled(true);
      this->ui.startingMultiplierSpinBox->setEnabled(true);
      this->ui.endingMultiplierSpinBox->setEnabled(true);

      this->ui.peakMultiplierSpinBox->setEnabled(false);
      this->ui.stepsAtPeakSpinBox->setEnabled(false);
    }
    else if (interval.GetType() == "Pyramid")
    {
      this->ui.timeStepSpinBox->setEnabled(true);
      this->ui.startingMultiplierSpinBox->setEnabled(true);
      this->ui.endingMultiplierSpinBox->setEnabled(true);
      this->ui.peakMultiplierSpinBox->setEnabled(true);

      this->ui.stepsAtPeakSpinBox->setEnabled(false);
    }
    else if (interval.GetType() == "Plateau")
    {
      this->ui.timeStepSpinBox->setEnabled(true);
      this->ui.startingMultiplierSpinBox->setEnabled(true);
      this->ui.endingMultiplierSpinBox->setEnabled(true);
      this->ui.peakMultiplierSpinBox->setEnabled(true);
      this->ui.stepsAtPeakSpinBox->setEnabled(true);
    }
    else if (interval.GetType() == "Constant")
    {
      this->ui.timeStepSpinBox->setEnabled(true);
      this->ui.peakMultiplierSpinBox->setEnabled(true);
      this->ui.stepsAtPeakSpinBox->setEnabled(true);

      this->ui.startingMultiplierSpinBox->setEnabled(false);
      this->ui.endingMultiplierSpinBox->setEnabled(false);
    }
  }
  else
  {
    this->ui.nameLineEdit->setEnabled(false);
    this->ui.intervalTypeComboBox->setEnabled(false);
    this->ui.timerStyleComboBox->setEnabled(false);

    this->ui.timeStepSpinBox->setEnabled(false);
    this->ui.startingMultiplierSpinBox->setEnabled(false);
    this->ui.endingMultiplierSpinBox->setEnabled(false);
    this->ui.peakMultiplierSpinBox->setEnabled(false);
    this->ui.stepsAtPeakSpinBox->setEnabled(false);
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
