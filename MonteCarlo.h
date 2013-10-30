// Copyright 2013 Steve Gribble.

#ifndef _HW2_MONTECARLO_H_
#define _HW2_MONTECARLO_H_

#include <list>
#include <map>

// This class represents a Monte Carlo experiment over the
// IntervalList class defined in IntervalList.h. A MonteCarlo
// experiment generates a sequence of randomly generated IntervalList
// structures, and computes the average number of Intervals that cover
// a prescribed sequence of points.
class MonteCarlo {
 public:
  // Creates a MonteCarlo experiment instance, but doesn't yet run
  // the experiment. The parameters are as follows:
  //
  //   num_trials: the number of random trials to run
  //
  //   num_intervals: the number of intervals per randomly generated
  //   IntervalList
  //
  //   range_start, range_end: the range over which Intervals are
  //   randomly generated
  //
  //   points: the ordered sequence of points at which to calculate
  //   the average number of covering Intervals
  MonteCarlo(unsigned int num_trials, unsigned int num_intervals,
	     double range_start, double range_end,
	     const std::list<double> &points)
    : num_trials_(num_trials), num_intervals_(num_intervals),
      range_start_(range_start), range_end_(range_end),
      points_(points) { }

  virtual ~MonteCarlo() { }

  // Runs a MonteCarlo experiment using the parameters passed to the
  // constructor. Returns a map from (point) --> (average number of
  // Intervals covering that point).
  std::map<double, double> RunExperiment(void) const;

 private:
  unsigned int num_trials_;
  unsigned int num_intervals_;
  double range_start_;
  double range_end_;
  std::list<double> points_;
};

#endif // _HW2_MONTECARLO_H_
