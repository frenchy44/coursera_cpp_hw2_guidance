// Copyright 2013 Steve Gribble.

#include <cstdlib>
#include <iostream>
#include <string.h>

#include "./IntervalList.h"
#include "./SteveAssert.h"

void IL_AdditionalTests() {
  IntervalList test_iv;

  // Make sure our boundary cases are OK.
  test_iv.AddInterval(IntervalList::Interval(1.0, 2.0));
  SteveAssert(1 == test_iv.Find(1.0).size());
  SteveAssert(1 == test_iv.Find(2.0).size());
  SteveAssert(0 == test_iv.Find(0.99999).size());

  // Make sure we can add, then delete, overlapping intervals.
  test_iv.AddInterval(IntervalList::Interval(1.0, 2.0));
  SteveAssert(2 == test_iv.size());
  SteveAssert(2 == test_iv.Find(1.0).size());
  SteveAssert(true ==
              test_iv.RemoveInterval(IntervalList::Interval(1.0, 2.0)));
  SteveAssert(true ==
              test_iv.RemoveInterval(IntervalList::Interval(1.0, 2.0)));
  SteveAssert(false ==
              test_iv.RemoveInterval(IntervalList::Interval(1.0, 2.0)));
}

void IL_SimpleTest() {
  IntervalList test_iv;

  // Make sure the empty IntervalList is sensible.
  std::cout << "Empty IntervalList: " << test_iv << std::endl;
  SteveAssert(0 == test_iv.size());
  SteveAssert(0 == test_iv.Find(10.0).size());
  SteveAssert(false ==
              test_iv.RemoveInterval(IntervalList::Interval(1.0, 2.0)));

  // Add an interval to the list.
  test_iv.AddInterval(IntervalList::Interval(1.0, 2.0));
  std::cout << "One-element IntervalList: " << test_iv << std::endl;
  SteveAssert(1 == test_iv.size());
  SteveAssert(0 == test_iv.Find(10.0).size());
  SteveAssert(1 == test_iv.Find(1.5).size());
  SteveAssert(IntervalList::Interval(1.0, 2.0) ==
              *(test_iv.Find(1.5).begin()));
  SteveAssert(false ==
              test_iv.RemoveInterval(IntervalList::Interval(1.0, 10.0)));

  // Add another interval to the list.
  test_iv.AddInterval(IntervalList::Interval(1.5, 3.0));
  std::cout << "Two-element IntervalList: " << test_iv << std::endl;
  SteveAssert(2 == test_iv.size());
  SteveAssert(0 == test_iv.Find(10.0).size());
  SteveAssert(1 == test_iv.Find(1.25).size());
  SteveAssert(2 == test_iv.Find(1.75).size());
  SteveAssert(1 == test_iv.Find(2.75).size());

  // Remove an interval.
  SteveAssert(true ==
              test_iv.RemoveInterval(IntervalList::Interval(1.5, 3.0)));
  std::cout << "One-element IntervalList: " << test_iv << std::endl;
  SteveAssert(1 == test_iv.size());
  SteveAssert(1 == test_iv.Find(1.75).size());
}

int main(int argc, char **argv) {
  IL_SimpleTest();
  IL_AdditionalTests();
  return EXIT_SUCCESS;
}
