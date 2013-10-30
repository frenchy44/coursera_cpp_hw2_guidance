// Copyright 2013 Steve Gribble.

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "./AsciiColumnChart.h"
#include "./MonteCarlo.h"

int main(int argc, char **argv) {
  // Generate the list of points at which we'll test.
  std::list<double> points;
  for (auto i = 0.0; i <= 10.0; i += 0.5) {
    points.push_back(i);
  }

  // Create and run the Monte Carlo experiment.
  MonteCarlo monty(1000, 100000, 0.0, 10.0, points);
  std::map<double, double> result = monty.RunExperiment();

  // Print out the resulting chart.
  AsciiColumnChart chart;
  for (const auto &col : result) {
    chart.AddColumn(std::to_string(col.first), col.second);
  }
  std::cout << chart.GenerateChart();

  return EXIT_SUCCESS;
}
