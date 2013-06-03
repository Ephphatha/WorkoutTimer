#ifndef __Interval
#define __Interval

#pragma once

#include <QObject>

#include <QString>
#include <QJsonObject>
#include <QMetaType>
#include <QList>

class Interval : public QObject
{
  Q_OBJECT;

public:
  enum Type;
  enum Direction;

  class SetParameters {
  public:
    SetParameters(
      double startAt = 1,
      double peakAt = 1,
      double endAt = 1);
    
    SetParameters(const SetParameters &rhs);

    SetParameters(const QJsonObject &json);

    virtual ~SetParameters(void);

    operator QJsonObject() const;

    operator QJsonValue() const;

    double StartAt() const;
    double PeakAt() const;
    double EndAt() const;

    void StartAt(double seconds);
    void PeakAt(double seconds);
    void EndAt(double seconds);

  private:
    void Initialise(
      double startAt = 1,
      double peakAt = 1,
      double endAt = 1);

    std::pair<QString, double> startAt;
    std::pair<QString, double> peakAt;
    std::pair<QString, double> endAt;
  };

  Interval(
    const QString &name = "Interval",
    const Type &type = LADDER,
    int sets = 10,
    const SetParameters &workoutParameters = SetParameters(),
    const SetParameters &restParameters = SetParameters(),
    int setsAtPeak = 1,
    const Direction &countDirection = DOWN);

  Interval(const Interval &rhs);

  Interval(const QJsonObject &json);

  virtual ~Interval(void);

  operator QJsonObject() const;

  operator QJsonValue() const;

  void Name(const QString &name);
  void ChangeType(const Type &type);
  void Sets(int sets);
  void WorkoutPeriodStartAt(double startAt);
  void WorkoutPeriodPeakAt(double peakAt);
  void WorkoutPeriodEndAt(double endAt);
  void RestPeriodStartAt(double startAt);
  void RestPeriodPeakAt(double peakAt);
  void RestPeriodEndAt(double endAt);
  void SetsAtPeak(int setsAtPeak);
  void CountDirection(const Direction& countDirection);

  const QString& Name() const;
  const Type& GetType() const;
  int Sets() const;
  double WorkoutPeriodStartAt() const;
  double WorkoutPeriodPeakAt() const;
  double WorkoutPeriodEndAt() const;
  double RestPeriodStartAt() const;
  double RestPeriodPeakAt() const;
  double RestPeriodEndAt() const;
  int SetsAtPeak() const;
  const Direction& CountDirection() const;

  enum Type {
    LADDER,
    PYRAMID,
    PLATEAU,
    CONSTANT,
  };

  enum Direction {
    DOWN,
    UP,
  };

  Q_ENUMS(Type Direction);

protected:
  const SetParameters &WorkoutParameters() const;
  SetParameters &WorkoutParameters();
  const SetParameters &RestParameters() const;
  SetParameters &RestParameters();

  void SetWorkoutParameters(const SetParameters &parameters);
  void SetRestParameters(const SetParameters &parameters);

  std::pair<QString, QString> name;

  std::pair<QString, Type> type;
  std::pair<QString, int> sets;
  std::pair<QString, int> setsAtPeak;
  std::pair<QString, Direction> countDirection;

  std::pair<QString, SetParameters> workoutParameters;
  std::pair<QString, SetParameters> restParameters;

private:
  void Initialise(
    const QString &name = "",
    const Type &type = LADDER,
    int sets = 10,
    const SetParameters &workoutParameters = SetParameters(),
    const SetParameters &restParameters = SetParameters(),
    int setsAtPeak = 1,
    const Direction &countDirection = DOWN);
};

Q_DECLARE_METATYPE(Interval);

#endif
