#ifndef __Interval
#define __Interval

#pragma once

#include <QString>
#include <QJsonObject>
#include <QMetaType>
#include <QList>

class Interval
{
public:
  class Type;
  class Direction;

  Interval(
    const QString &name = "Interval",
    const Type &type = Type("Ladder"),
    double timeStep = 10,
    double startMultiplier = 1,
    double peakMultiplier = 0,
    double endMultiplier = 10,
    double stepsAtPeak = 0,
    const Direction &countDirection = Direction("Down"));

  Interval(const Interval &rhs);

  Interval(const QJsonObject &json);

  virtual ~Interval(void);

  operator QJsonObject() const;

  operator QJsonValue() const;

  void SetName(const QString &name);
  void ChangeType(const Type &type);
  void SetTimeStep(double timeStep);
  void SetStartMultiplier(double startMultiplier);
  void SetPeakMultiplier(double peakMultiplier);
  void SetEndMultiplier(double endMultiplier);
  void SetStepsAtPeak(double stepsAtPeak);
  void SetCountDirection(const Direction& countDirection);

  const QString& Name() const;
  const Type& GetType() const;
  double TimeStep() const;
  double StartMultiplier() const;
  double PeakMultiplier() const;
  double EndMultiplier() const;
  double StepsAtPeak() const;
  const Direction& CountDirection() const;

  class Type {
  public:
    static const QList<QString>& Types(void);

    Type(int value = 0) throw (std::out_of_range);

    Type(const QString &name) throw (std::invalid_argument);

    operator QString() const;
    
    int Value() const;

    bool operator==(const Type &rhs) const;
    bool operator!=(const Type &rhs) const;

  private:
    static QList<QString> types;

    int value;

    static void InitialiseStaticData();
  };

  class Direction {
  public:
    static const QList<QString>& Directions(void);

    Direction(int value = 0) throw (std::out_of_range);

    Direction(const QString &name) throw (std::invalid_argument);

    operator QString() const;

    int Value() const;

    bool operator==(const Direction &rhs) const;
    bool operator!=(const Direction &rhs) const;

  private:
    static QList<QString> directions;

    int value;

    static void InitialiseStaticData();
  };

protected:
  std::pair<QString, QString> name;

  std::pair<QString, Type> type;

  std::pair<QString, double> timeStep;

  std::pair<QString, double> startMultiplier;
  std::pair<QString, double> peakMultiplier;
  std::pair<QString, double> endMultiplier;

  std::pair<QString, double> stepsAtPeak;

  std::pair<QString, Direction> countDirection;

private:
  void Initialise(
    const QString &name = "",
    const Type &type = Type("Ladder"),
    double timeStep = 10,
    double startMultiplier = 1,
    double peakMultiplier = 0,
    double endMultiplier = 10,
    double stepsAtPeak = 0,
    const Direction &countDirection = Direction("Down"));
};

Q_DECLARE_METATYPE(Interval);

#endif
