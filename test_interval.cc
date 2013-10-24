// Copyright 2013 Steve Gribble.

#include <cstdlib>
#include <iostream>

#include "./IntervalList.h"

int main(int argc, char **argv) {
  IntervalList ilist;
  std::cout << "Size: " << ilist.size() << std::endl;
  return EXIT_SUCCESS;
}
