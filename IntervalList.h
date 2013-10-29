// Copyright 2013 Steve Gribble.

#ifndef _HW2_INTERVALLIST_H_
#define _HW2_INTERVALLIST_H_

#include <fstream>
#include <list>

// This class represents a list of Intervals, where an Interval is a
// range on the real line.
class IntervalList {
 public:
  // This nested class represents an Interval in an IntervalList. I'm
  // being a little lazy by exposing the 'start' and 'end' instance
  // variables as public, but it's fine for now.
  class Interval {
   public:
    Interval(double s, double e) : start_(s), end_(e) { }

    // Accessors and mutators.
    void set_start(double start) { start_ = start; }
    double start(void) const { return start_; }
    void set_end(double end) { end_ = end; }
    double end(void) const { return end_; }

    // Compares two Intervals for equality.
    bool operator==(const Interval &rhs) const;

   private:
    double start_; // the start of the interval
    double end_;   // the end of the interval
  };

  IntervalList() { }
  virtual ~IntervalList() { }

  // A factory for generating random IntervalLists. Exactly
  // "num_intervals" random intervals are generated, with each
  // interval's endpoints uniformly drawn from the range [range_start,
  // range_end).
  static IntervalList GenerateRandom(unsigned int num_intervals,
                                     double range_start, double range_end);

  // Returns the number of Intervals in the IntervalList.
  int size(void) const;

  // Adds an Interval to the interval list. Note that it's possible to
  // have two identical Intervals in the list at the same time.
  void AddInterval(const Interval &add_me);

  // Removes an Interval from the interval list, if it exists. If
  // there is more than one Interval that matches, this only removes
  // one of them.
  //
  // Returns true if an Interval was removed, false otherwise.
  bool RemoveInterval(const Interval &remove_me);

  // Returns a list of Intervals that overlap find_me. If no intervals
  // match, this will return an empty list.
  std::list<Interval> Find(double find_me) const;

  // So that << can access the intervals_ private member.
  friend std::ostream& operator<<(std::ostream &os,
                                  const IntervalList &ilist);
 private:
  std::list<Interval> intervals_;
};

#endif // _HW2_INTERVALLIST_H_
