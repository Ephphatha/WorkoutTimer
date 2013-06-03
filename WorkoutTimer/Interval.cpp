#include "Interval.h"

#include <sstream>

#include <QMetaEnum>

Interval::SetParameters::SetParameters(
  double startAt,
  double peakAt,
  double endAt)
{
  this->Initialise(startAt, peakAt, endAt);
}


Interval::SetParameters::SetParameters(const Interval::SetParameters &rhs)
{
  this->Initialise(rhs.StartAt(), rhs.PeakAt(), rhs.EndAt());
}


Interval::SetParameters::SetParameters(const QJsonObject &json)
{
  this->Initialise();

  QJsonValue val = json[this->startAt.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->StartAt(static_cast<int>(val.toDouble()));
  }

  val = json[this->peakAt.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->PeakAt(static_cast<int>(val.toDouble()));
  }

  val = json[this->endAt.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->EndAt(static_cast<int>(val.toDouble()));
  }
}


Interval::SetParameters::~SetParameters(void)
{
}


Interval::SetParameters::operator QJsonObject() const
{
  QJsonObject obj;

  if (this->StartAt() > 0)
  {
    obj[this->startAt.first] = this->StartAt();
  }
  if (this->PeakAt() > 0)
  {
    obj[this->peakAt.first] = this->PeakAt();
  }
  if (this->EndAt() > 0)
  {
    obj[this->endAt.first] = this->EndAt();
  }

  return obj;
}


Interval::SetParameters::operator QJsonValue() const
{
  return QJsonObject(*this);
}


double Interval::SetParameters::StartAt() const
{
  return this->startAt.second;
}

double Interval::SetParameters::PeakAt() const
{
  return this->peakAt.second;
}

double Interval::SetParameters::EndAt() const
{
  return this->endAt.second;
}

void Interval::SetParameters::StartAt(double seconds)
{
  this->startAt.second = seconds;
}

void Interval::SetParameters::PeakAt(double seconds)
{
  this->peakAt.second = seconds;
}

void Interval::SetParameters::EndAt(double seconds)
{
  this->endAt.second = seconds;
}

Interval::Interval(
  const QString &name,
  const Interval::Type &type,
  int sets,
  const Interval::SetParameters &workoutParameters,
  const Interval::SetParameters &restParameters,
  int setsAtPeak,
  const Interval::Direction &countDirection)
{
  this->Initialise(name, type, sets, workoutParameters, restParameters, setsAtPeak, countDirection);
}

Interval::Interval(const Interval &rhs)
{
  this->Initialise(rhs.Name(), rhs.GetType(), rhs.Sets(), rhs.WorkoutParameters(), rhs.RestParameters(), rhs.SetsAtPeak(), rhs.CountDirection());
}

Interval::Interval(const QJsonObject &json)
{
  this->Initialise();

  QJsonValue val = json[this->name.first];

  if (!val.isUndefined() && val.isString())
  {
    this->Name(val.toString());
  }

  val = json[this->type.first];

  if (!val.isUndefined() && val.isString())
  {
    bool success;
    int enumVal = Interval::staticMetaObject.enumerator(Interval::staticMetaObject.indexOfEnumerator("Type")).keyToValue(val.toString().toStdString().c_str(), &success);
    if (success)
    {
      this->ChangeType(static_cast<Interval::Type>(enumVal));
    }
  }

  val = json[this->countDirection.first];

  if (!val.isUndefined() && val.isString())
  {
    bool success;
    int enumVal = Interval::staticMetaObject.enumerator(Interval::staticMetaObject.indexOfEnumerator("Direction")).keyToValue(val.toString().toStdString().c_str(), &success);
    if (success)
    {
      this->CountDirection(static_cast<Interval::Direction>(enumVal));
    }
  }

  val = json[this->sets.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->Sets(static_cast<int>(val.toDouble()));
  }

  val = json[this->workoutParameters.first];

  if (!val.isUndefined() && val.isObject())
  {
    this->SetWorkoutParameters(val.toObject());
  }

  val = json[this->restParameters.first];

  if (!val.isUndefined() && val.isObject())
  {
    this->SetRestParameters(val.toObject());
  }

  val = json[this->setsAtPeak.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->SetsAtPeak(static_cast<int>(val.toDouble()));
  }
}

Interval::~Interval(void)
{
}

void Interval::Initialise(
  const QString &name,
  const Type &type,
  int sets,
  const Interval::SetParameters &workoutParameters,
  const Interval::SetParameters &restParameters,
  int setsAtPeak,
  const Direction &countDirection)
{
  this->name = std::pair<QString, QString>("Name", name);
  this->type = std::pair<QString, Interval::Type>("Interval Type", type);

  this->sets = std::pair<QString, int>("Sets", sets);

  this->workoutParameters = std::pair<QString, Interval::SetParameters>("Workout Parameters", workoutParameters);

  this->restParameters = std::pair<QString, Interval::SetParameters>("Workout Parameters", restParameters);

  this->setsAtPeak = std::pair<QString, int>("Steps at Peak", 0);
  this->SetsAtPeak(setsAtPeak);

  this->countDirection = std::pair<QString, Interval::Direction>("Count Direction", countDirection);
}

Interval::operator QJsonObject() const
{
  QJsonObject obj;

  obj[this->name.first] = this->Name();
  obj[this->type.first] = QString(Interval::staticMetaObject.enumerator(Interval::staticMetaObject.indexOfEnumerator("Type")).valueToKey(this->GetType()));
  obj[this->countDirection.first] = QString(Interval::staticMetaObject.enumerator(Interval::staticMetaObject.indexOfEnumerator("Direction")).valueToKey(this->CountDirection()));

  obj[this->sets.first] = this->Sets();

  obj[this->workoutParameters.first] = this->WorkoutParameters();

  obj[this->restParameters.first] = this->RestParameters();

  if (this->SetsAtPeak() > 0)
  {
    obj[this->setsAtPeak.first] = this->SetsAtPeak();
  }

  return obj;
}

Interval::operator QJsonValue() const
{
  return QJsonObject(*this);
}

void Interval::Name(const QString &name)
{
  this->name.second = name;
}

void Interval::ChangeType(const Interval::Type &type)
{
  this->type.second = type;
  switch(this->type.second)
  {
  case Interval::Type::LADDER:
    this->setsAtPeak.second = 0;
    this->WorkoutParameters().PeakAt(0);
    this->RestParameters().PeakAt(0);
    break;

  case Interval::Type::PYRAMID:
    this->setsAtPeak.second = 0;
    break;

  case Interval::Type::PLATEAU:
    break;

  case Interval::Type::CONSTANT:
    this->WorkoutParameters().StartAt(0);
    this->WorkoutParameters().EndAt(0);
    this->RestParameters().StartAt(0);
    this->RestParameters().EndAt(0);
    break;
  }
}

void Interval::Sets(int sets)
{
  if (sets > 0) {
    this->sets.second = sets;
  }
}

void Interval::WorkoutPeriodStartAt(double startAt)
{
  if (startAt > 0 && this->type.second != Interval::Type::CONSTANT) {
    this->WorkoutParameters().StartAt(startAt);
  }
}

void Interval::WorkoutPeriodPeakAt(double peakAt)
{
  if (peakAt > 0 && this->type.second != Interval::Type::LADDER) {
    this->WorkoutParameters().PeakAt(peakAt);
  }
}

void Interval::WorkoutPeriodEndAt(double endAt)
{
  if (endAt > 0 && this->type.second != Interval::Type::CONSTANT) {
    this->WorkoutParameters().EndAt(endAt);
  }
}


void Interval::RestPeriodStartAt(double startAt)
{
  if (startAt > 0 && this->type.second != Interval::Type::CONSTANT) {
    this->RestParameters().StartAt(startAt);
  }
}

void Interval::RestPeriodPeakAt(double peakAt)
{
  if (peakAt > 0 && this->type.second != Interval::Type::LADDER) {
    this->RestParameters().PeakAt(peakAt);
  }
}

void Interval::RestPeriodEndAt(double endAt)
{
  if (endAt > 0 && this->type.second != Interval::Type::CONSTANT) {
    this->RestParameters().EndAt(endAt);
  }
}

void Interval::SetsAtPeak(int setsAtPeak)
{
  if (setsAtPeak > 0 && this->type.second != Interval::Type::LADDER && this->type.second != Interval::Type::PYRAMID) {
    this->setsAtPeak.second = setsAtPeak;
  }
}

void Interval::CountDirection(const Interval::Direction& countDirection)
{
  this->countDirection.second = countDirection;
}


const QString& Interval::Name() const
{
  return this->name.second;
}

const Interval::Type& Interval::GetType() const
{
  return this->type.second;
}

int Interval::Sets() const
{
  return this->sets.second;
}

double Interval::WorkoutPeriodStartAt() const
{
  return this->WorkoutParameters().StartAt();
}

double Interval::WorkoutPeriodPeakAt() const
{
  return this->WorkoutParameters().PeakAt();
}

double Interval::WorkoutPeriodEndAt() const
{
  return this->WorkoutParameters().EndAt();
}

double Interval::RestPeriodStartAt() const
{
  return this->RestParameters().StartAt();
}

double Interval::RestPeriodPeakAt() const
{
  return this->RestParameters().PeakAt();
}

double Interval::RestPeriodEndAt() const
{
  return this->RestParameters().EndAt();
}

int Interval::SetsAtPeak() const
{
  return this->setsAtPeak.second;
}

const Interval::Direction& Interval::CountDirection() const
{
  return this->countDirection.second;
}

const Interval::SetParameters &Interval::WorkoutParameters() const
{
  return this->workoutParameters.second;
}

Interval::SetParameters &Interval::WorkoutParameters()
{
  return this->workoutParameters.second;
}

const Interval::SetParameters &Interval::RestParameters() const
{
  return this->restParameters.second;
}

Interval::SetParameters &Interval::RestParameters()
{
  return this->restParameters.second;
}

void Interval::SetWorkoutParameters(const Interval::SetParameters &parameters)
{
  this->workoutParameters.second = parameters;
}

void Interval::SetRestParameters(const Interval::SetParameters &parameters)
{
  this->restParameters.second = parameters;
}

void Interval::SetParameters::Initialise(
  double startAt,
  double peakAt,
  double endAt)
{
  this->startAt = std::pair<QString, double>("Start At", startAt);
  this->peakAt = std::pair<QString, double>("Peak At", peakAt);
  this->endAt = std::pair<QString, double>("End At", endAt);
}
