#include "Interval.h"

#include <sstream>

QList<QString> Interval::Type::types;
QList<QString> Interval::Direction::directions;

Interval::Type::Type(int value) : value(value)
{
  if (this->value < 0 || this->value >= Interval::Type::Types().size())
  {
    std::stringstream errorMessageStream;

    errorMessageStream << "Value must be in the range [0," << Interval::Type::Types().size() << ").";

    throw std::out_of_range(errorMessageStream.str());
  }
}

Interval::Type::Type(const QString &name) : value(-1)
{
  for (int i = 0; i < Interval::Type::Types().size(); ++i)
  {
    if (name == Interval::Type::Types()[i])
    {
      this->value = i;
      break;
    }
  }

  if (this->value < 0 || this->value >= Interval::Type::Types().size())
  {
    std::stringstream errorMessageStream;

    errorMessageStream << "Valid types are one of ";

    for (int i = 0; i < Interval::Type::Types().size(); ++i)
    {
      if (i > 0)
      {
        errorMessageStream << ",";
      }
      errorMessageStream << "\"" << Interval::Type::Types()[i].toStdString() << "\"";
    }

    errorMessageStream << ".";

    throw std::invalid_argument(errorMessageStream.str());
  }
}

const QList<QString>& Interval::Type::Types()
{
  if (Interval::Type::types.isEmpty())
  {
    Interval::Type::InitialiseStaticData();
  }

  return Interval::Type::types;
}

void Interval::Type::InitialiseStaticData()
{
  Interval::Type::types << "Ladder" << "Pyramid" << "Plateau" << "Constant";
}

Interval::Type::operator QString() const
{
  return Interval::Type::Types()[this->value];
}

int Interval::Type::Value() const
{
  return this->value;
}

bool Interval::Type::operator==(const Interval::Type &rhs) const
{
  return this->value == rhs.value;
}

bool Interval::Type::operator!=(const Interval::Type &rhs) const
{
  return !(*this == rhs);
}

Interval::Direction::Direction(int value) : value(value)
{
  if (this->value < 0 || this->value >= Interval::Direction::Directions().size())
  {
    std::stringstream errorMessageStream;

    errorMessageStream << "Value must be in the range [0," << Interval::Direction::Directions().size() << ").";

    throw std::out_of_range(errorMessageStream.str());
  }
}

Interval::Direction::Direction(const QString &name) : value(-1)
{
  for (int i = 0; i < Interval::Direction::Directions().size(); ++i)
  {
    if (name == Interval::Direction::Directions()[i])
    {
      this->value = i;
      break;
    }
  }

  if (this->value < 0 || this->value >= Interval::Direction::Directions().size())
  {
    std::stringstream errorMessageStream;

    errorMessageStream << "Valid directions are one of ";

    for (int i = 0; i < Interval::Direction::Directions().size(); ++i)
    {
      if (i > 0)
      {
        errorMessageStream << ",";
      }
      errorMessageStream << "\"" << Interval::Direction::Directions()[i].toStdString() << "\"";
    }

    errorMessageStream << ".";

    throw std::invalid_argument(errorMessageStream.str());
  }
}

const QList<QString>& Interval::Direction::Directions()
{
  if (Interval::Direction::directions.isEmpty())
  {
    Interval::Direction::InitialiseStaticData();
  }
  return Interval::Direction::directions;
}

void Interval::Direction::InitialiseStaticData()
{
  Interval::Direction::directions << "Down" << "Up";
}

Interval::Direction::operator QString() const
{
  return Interval::Direction::Directions()[this->value];
}

int Interval::Direction::Value() const
{
  return this->value;
}

bool Interval::Direction::operator==(const Interval::Direction &rhs) const
{
  return this->value == rhs.value;
}

bool Interval::Direction::operator!=(const Interval::Direction &rhs) const
{
  return !(*this == rhs);
}

Interval::Interval(
  const QString &name,
  const Interval::Type &type,
  double timeStep,
  double startMultiplier,
  double peakMultiplier,
  double endMultiplier,
  double stepsAtPeak,
  const Interval::Direction &countDirection)
{
  this->Initialise(name, type, timeStep, startMultiplier, peakMultiplier, endMultiplier, stepsAtPeak, countDirection);
}

Interval::Interval(const Interval &rhs)
{
  this->Initialise(rhs.Name(), rhs.GetType(), rhs.TimeStep(), rhs.StartMultiplier(), rhs.PeakMultiplier(), rhs.EndMultiplier(), rhs.StepsAtPeak(), rhs.CountDirection());
}

Interval::Interval(const QJsonObject &json)
{
  this->Initialise();

  QJsonValue val = json[this->Name()];

  if (!val.isUndefined() && val.isString())
  {
    this->SetName(val.toString());
  }

  val = json[this->GetType()];

  if (!val.isUndefined() && val.isString())
  {
    try
    {
      this->ChangeType(Interval::Type(val.toString()));
    }
    catch (std::invalid_argument)
    {
      // Malformed JSON, ignore and use default value.
    }
  }

  val = json[this->CountDirection()];

  if (!val.isUndefined() && val.isString())
  {
    try
    {
      this->SetCountDirection(Interval::Direction(val.toString()));
    }
    catch (std::invalid_argument)
    {
      // Malformed JSON, ignore and use default value.
    }
  }

  val = json[this->timeStep.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->SetTimeStep(val.toDouble());
  }

  val = json[this->startMultiplier.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->SetStartMultiplier(val.toDouble());
  }

  val = json[this->peakMultiplier.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->SetPeakMultiplier(val.toDouble());
  }

  val = json[this->endMultiplier.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->SetEndMultiplier(val.toDouble());
  }

  val = json[this->stepsAtPeak.first];

  if (!val.isUndefined() && val.isDouble())
  {
    this->SetStepsAtPeak(val.toDouble());
  }
}

Interval::~Interval(void)
{
}

void Interval::Initialise(
  const QString &name,
  const Type &type,
  double timeStep,
  double startMultiplier,
  double peakMultiplier,
  double endMultiplier,
  double stepsAtPeak,
  const Direction &countDirection)
{
  this->name = std::pair<QString, QString>("Name", name);
  this->type = std::pair<QString, Interval::Type>("Interval Type", type);

  this->timeStep = std::pair<QString, double>("Time Step", 0);
  this->SetTimeStep(timeStep);

  this->startMultiplier = std::pair<QString, double>("Starting Multiplier", 0);
  this->SetStartMultiplier(startMultiplier);

  this->peakMultiplier = std::pair<QString, double>("Peak Multiplier", 0);
  this->SetPeakMultiplier(peakMultiplier);

  this->endMultiplier = std::pair<QString, double>("Ending Multiplier", 0);
  this->SetEndMultiplier(endMultiplier);

  this->stepsAtPeak = std::pair<QString, double>("Steps at Peak", 0);
  this->SetStepsAtPeak(stepsAtPeak);

  this->countDirection = std::pair<QString, Interval::Direction>("Count Direction", countDirection);
}

Interval::operator QJsonObject() const
{
  QJsonObject obj;

  obj[this->name.first] = this->name.second;
  obj[this->type.first] = QString(this->type.second);
  obj[this->countDirection.first] = QString(this->countDirection.second);

  obj[this->timeStep.first] = this->timeStep.second;

  if (this->startMultiplier.second > 0)
  {
    obj[this->startMultiplier.first] = this->startMultiplier.second;
  }
  if (this->peakMultiplier.second > 0)
  {
    obj[this->peakMultiplier.first] = this->peakMultiplier.second;
  }
  if (this->endMultiplier.second > 0)
  {
    obj[this->endMultiplier.first] = this->endMultiplier.second;
  }
  if (this->stepsAtPeak.second > 0)
  {
    obj[this->stepsAtPeak.first] = this->stepsAtPeak.second;
  }

  return obj;
}

Interval::operator QJsonValue() const
{
  return QJsonObject(*this);
}

void Interval::SetName(const QString &name)
{
  this->name.second = name;
}

void Interval::ChangeType(const Interval::Type &type)
{
  this->type.second = type;
  if (this->type.second == Interval::Type("Ladder"))
  {
    this->peakMultiplier.second = 0;
    this->stepsAtPeak.second = 0;
  }
  else if (this->type.second == Interval::Type("Pyramid"))
  {
    this->stepsAtPeak.second = 0;
  }
  else if (this->type.second == Interval::Type("Plateau"))
  {
  }
  else if (this->type.second == Interval::Type("Constant"))
  {
    this->startMultiplier.second = 0;
    this->endMultiplier.second = 0;
  }
}

void Interval::SetTimeStep(double timeStep)
{
  if (timeStep > 0) {
    this->timeStep.second = timeStep;
  }
}
void Interval::SetStartMultiplier(double startMultiplier)
{
  if (startMultiplier > 0 && this->type.second != Interval::Type("Constant")) {
    this->startMultiplier.second = startMultiplier;
  }
}

void Interval::SetPeakMultiplier(double peakMultiplier)
{
  if (peakMultiplier > 0 && this->type.second != Interval::Type("Ladder")) {
    this->peakMultiplier.second = peakMultiplier;
  }
}

void Interval::SetEndMultiplier(double endMultiplier)
{
  if (endMultiplier > 0 && this->type.second != Interval::Type("Constant")) {
    this->endMultiplier.second = endMultiplier;
  }
}

void Interval::SetStepsAtPeak(double stepsAtPeak)
{
  if (stepsAtPeak > 0 && this->type.second != Interval::Type("Ladder") && this->type.second != Interval::Type("Pyramid")) {
    this->stepsAtPeak.second = stepsAtPeak;
  }
}

void Interval::SetCountDirection(const Interval::Direction& countDirection)
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

double Interval::TimeStep() const
{
  return this->timeStep.second;
}

double Interval::StartMultiplier() const
{
  return this->startMultiplier.second;
}

double Interval::PeakMultiplier() const
{
  return this->peakMultiplier.second;
}

double Interval::EndMultiplier() const
{
  return this->endMultiplier.second;
}

double Interval::StepsAtPeak() const
{
  return this->stepsAtPeak.second;
}

const Interval::Direction& Interval::CountDirection() const
{
  return this->countDirection.second;
}
