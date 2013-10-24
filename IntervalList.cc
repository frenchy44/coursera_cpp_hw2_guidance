// Copyright 2013 Steve Gribble.

#include "./IntervalList.h"

bool IntervalList::Interval::operator==(
  const IntervalList::Interval &rhs) const {
  // XXX -- to be implemented
  return false;
}

int IntervalList::size(void) const {
  // XXX -- to be implemented
  return 0;
}

void IntervalList::AddInterval(const Interval &add_me) {
  // XXX -- to be implemented
}

bool IntervalList::RemoveInterval(const Interval &remove_me) {
  // XXX -- to be implemented
  return false;
}

std::list<IntervalList::Interval> IntervalList::Find(double find_me) const {
  // XXX -- to be implemented
  std::list<IntervalList::Interval> retlist;
  return retlist;
}

// We overload the std::ostream's "<<" operator so that we can
// prettyprint an IntervalList and an Interval to streams
std::ostream& operator<<(std::ostream &os,
                         const IntervalList::Interval &ival) {
  // XXX -- to be implemented
  return os;
}

std::ostream& operator<<(std::ostream &os, const IntervalList &ilist) {
  // XXX -- to be implemented
  return os;
}
