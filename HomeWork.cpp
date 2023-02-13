// HomeWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "HistogramBase.h"
#include "Log.h"

#include <iostream>
#include <memory>

int main()
{
  Hist::RandomEintegerGenerator reg;
  Hist::Histogram hist;
  hist.add(reg());
  hist.add(reg());
  hist.add(reg());
  Hist::Histogram hist2(hist);
  Hist::EInteger mode2 = hist2.getMode();
  Hist::EInteger maxint = hist2.getMaxValue();
  Hist::EInteger minint = hist2.getMinValue();
}
