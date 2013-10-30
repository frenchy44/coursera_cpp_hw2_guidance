// Copyright 2013 Steve Gribble.

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>

#include "./MonteCarlo.h"
#include "./SteveAssert.h"

// The comparison threshold for declaring the test successful. This
// basically accounts for the variance we expect due to the
// randomization inherent in Monte Carlo.
const double kThresh = 15.0;

// Using a correct implementation, I found that the following results
// should be expected:
//
// 1000 trials, 10000 intervals, range = (0.0,10.0]:
//
//   (0.0, 0) (0.5, 948.987) (1.0, 1798.56) (1.5, 2548.68)
//   (2.0, 3199.2) (2.5, 3749.98) (3.0, 4199.49) (3.5, 4550.36)
//   (4.0, 4799.59) (4.5, 4949.78) (5.0, 4998.39) (5.5, 4946.42)
//   (6.0, 4797.76) (6.5, 4547.4) (7.0, 4198.85) (7.5, 3748.72)
//   (8.0, 3197.08) (8.5, 2546.97) (9.0, 1797.31) (9.5, 949.556)
//   (10.0, 0.0)
void MC_SimpleTest(void) {
  std::list<double> points;
  for (auto i = 0.0; i <= 10.0; i += 0.5) {
    points.push_back(i);
  }

 MonteCarlo mc(1000, 10000, 0.0, 10.0, points);
 auto result = mc.RunExperiment();
 std::map<double, double> expected = {
   {0.0, 0.0}, {0.5, 948.987}, {1.0, 1798.56}, {1.5, 2548.68},
   {2.0, 3199.2}, {2.5, 3749.98}, {3.0, 4199.49}, {3.5, 4550.36},
   {4.0, 4799.59}, {4.5, 4949.78}, {5.0, 4998.39}, {5.5, 4946.42},
   {6.0, 4797.76}, {6.5, 4547.4}, {7.0, 4198.85}, {7.5, 3748.72},
   {8.0, 3197.08}, {8.5, 2546.97}, {9.0, 1797.31}, {9.5, 949.556},
   {10.0, 0.0}
 };

 for (const auto &e : expected) {
   SteveAssert(std::abs(e.second - result[e.first]) < kThresh);
 }
}

int main(int argc, char **argv) {
  MC_SimpleTest();
  return EXIT_SUCCESS;
}
