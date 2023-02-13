#pragma once

#ifndef HISTOGRAMBASE_H

#define HISTOGRAMBASE_H

#include "Log.h"
#include <memory>
#include <vector>


namespace Hist
{
  enum EInteger: int
  {
    Min = -1,
    Zero = 0,
    One = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Max = 5
  };

  class RandomEintegerGeneratorBase
  {
  public:
    // Returns a pseudo-random EInteger value
    virtual EInteger operator()() = 0;
  };

  class RandomEintegerGenerator : public RandomEintegerGeneratorBase
  {
  public:
    RandomEintegerGenerator();
    EInteger operator()() override;
  };

  class HistogramBase
  {
  public:

    HistogramBase() = delete;
    HistogramBase(std::unique_ptr<Logger>);
    HistogramBase(const HistogramBase&);
    HistogramBase(HistogramBase&&);

    virtual ~HistogramBase(){};

    virtual void add(EInteger) = 0;

    // Return the value that occurrs most often in the data set (I.e. there exists no other value that occurs more often than the return value)
    virtual EInteger getMode() const = 0;

    // Return the smallest value in the data set, according to default ordering relation of integer numbers
    virtual EInteger getMinValue() const = 0;

    // Return the largest value in the data set
    virtual EInteger getMaxValue() const = 0;

  protected:
    std::unique_ptr<Logger> m_log;
  };

  class Histogram : public HistogramBase
  {
  public:
    Histogram();
    void add(EInteger) override;
    EInteger getMode() const override;
    EInteger getMinValue() const override;
    EInteger getMaxValue() const override;

  private:
    std::vector<EInteger> mEints;
  };
}
#endif