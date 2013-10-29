// Copyright 2013 Steve Gribble.

#include "./IntervalList.h"

bool IntervalList::Interval::operator==(
  const IntervalList::Interval &rhs) const {
  return ((start_ == rhs.start_) && (end_ == rhs.end_));
}

int IntervalList::size(void) const {
  return intervals_.size();
}

void IntervalList::AddInterval(const Interval &add_me) {
  intervals_.push_back(add_me);
}

bool IntervalList::RemoveInterval(const Interval &remove_me) {
  for (auto ival = intervals_.begin(); ival != intervals_.end(); ++ival) {
    if (*ival == remove_me) {
      intervals_.erase(ival);
      return true;
    }
  }
  return false;
}

std::list<IntervalList::Interval> IntervalList::Find(double find_me) const {
  std::list<IntervalList::Interval> retlist;
  for (const auto &ival : intervals_) {
    if ((find_me >= ival.start()) && (find_me <= ival.end())) {
      retlist.push_back(ival);
    }
  }
  return retlist;
}

// We overload the std::ostream's "<<" operator so that we can
// prettyprint an IntervalList and an Interval to streams
std::ostream& operator<<(std::ostream &os,
                         const IntervalList::Interval &ival) {
  os << "(" << ival.start() << "," << ival.end() << ")";
  return os;
}

std::ostream& operator<<(std::ostream &os, const IntervalList &ilist) {
  bool first = true;

  os << "[ ";
  for (const auto &ival : ilist.intervals_) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << ival;
  }
  if (!first) {
    os << " ";
  }
  os << "]";
  return os;
}
