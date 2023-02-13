#include "HistogramBase.h"

#include <stdlib.h>
#include <time.h>
#include <unordered_map>

namespace Hist
{
  /**
  * Constructor of RandomEintegerGenerator
  */
  RandomEintegerGenerator::RandomEintegerGenerator(): RandomEintegerGeneratorBase()
  {
    //initialize random seed
    srand((unsigned)time(NULL));
  }

  /**
  * Function call operator
  * @return Random Einteger
  */
  EInteger RandomEintegerGenerator::operator()()
  {
    EInteger RandomEInteger = static_cast<EInteger>(rand() % EInteger::Max);
    return RandomEInteger;
  }

  /**
  * Constructor of Histogram
  */
  Histogram::Histogram(): HistogramBase(std::make_unique<Logger>())
  {
  }

  /**
  * Add eInteger to Histogram
  * @param eInt EInteger to be added
  */
  void Histogram::add(EInteger eInt)
  {
    mEints.push_back(eInt);
  }

  /**
  * Get most frequent value of histogram
  * @return Mode
  */
  Hist::EInteger Histogram::getMode() const
  {
    std::unordered_map<EInteger,int> counts;
    for(auto eint: mEints)
    {
      ++counts[eint];
    }
    int maxCount = 0;
    EInteger maxEint = EInteger::Min;
    for(auto& count : counts) {
      if(maxCount < count.second) {
        maxEint = count.first;
        maxCount = count.second;
      }
    }
    return maxEint;
  }

  /**
  * Get minimum value of histogram
  * @return Minimum value. If histogram is empty then EInteger::Max
  */
  Hist::EInteger Histogram::getMinValue() const
  {
    EInteger minInt = EInteger::Max; 
    for (auto eInt : mEints)
    {
      if (eInt < minInt)
      {
        minInt = eInt;
      }
    }
    return minInt;
  }

  /**
  * Get maximum value of histogram
  * @return Maximum value. If histogram is empty then EInteger::Min
  */
  Hist::EInteger Histogram::getMaxValue() const
  {
    EInteger maxInt = EInteger::Min;
    for(auto eInt : mEints)
    {
      if(eInt > maxInt)
      {
        maxInt = eInt;
      }
    }
    return maxInt;
  }

  /**
  * Constructor of HistogramBase
  * @param Logger
  */
  HistogramBase::HistogramBase(std::unique_ptr<Logger> logger): m_log(std::move(logger))
  {
  }
  /**
  * Copy Constructor of HistogramBase
  */
  HistogramBase::HistogramBase(const HistogramBase& histBase)
  {
    m_log.reset( new Logger( *histBase.m_log ) );
  }

  /**
  * Move Constructor of HistogramBase
  */
  HistogramBase::HistogramBase(HistogramBase&& histBase): m_log(std::move(histBase.m_log))
  {
  }
}
