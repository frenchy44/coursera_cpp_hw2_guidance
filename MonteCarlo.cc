// Copyright 2013 Steve Gribble.

#include "./IntervalList.h"
#include "./MonteCarlo.h"

std::map<double, double> MonteCarlo::RunExperiment(void) const {
  std::map<double, double> results;

  // Do the 'num_trials_' experiments, summing up the number of
  // covering intervals into results.
  for (auto i = 0U; i < num_trials_; ++i) {
    IntervalList ilist =
      IntervalList::GenerateRandom(num_intervals_, range_start_, range_end_);
    for (auto point : points_) {
      results[point] += ilist.Find(point).size();
    }
  }

  // Complete the averaging and return the results.
  for (auto point : points_) {
    results[point] /= num_trials_;
  }
  return results;
}
