// Copyright 2013 Steve Gribble.

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

#include "./AsciiColumnChart.h"
#include "./SteveAssert.h"

void ACC_SimpleTest() {
  AsciiColumnChart chart;

  // Test a chart with column names.
  chart.AddColumn("column a", 55.123);
  chart.AddColumn("column b", 0.0);
  chart.AddColumn("superlongcolumnname", 0.01);
  chart.AddColumn("", 24.551);
  chart.AddColumn("manyafter.", 25.35434534234345435);

  std::list<std::string> cols = chart.GenerateColumns();
  SteveAssert(5 == cols.size());

  std::string outstring = chart.GenerateChart();
  std::string comparestring = "";
  for (const auto &col : cols) {
    comparestring += col + "\n";
  }
  SteveAssert(outstring == comparestring);

  // Test a chart with no column names.
  AsciiColumnChart emptychart;
  emptychart.AddColumn("", 55.123);
  emptychart.AddColumn("", 0.0);
  emptychart.AddColumn("", 0.01);
  std::string emptycomparestring =
    "************************************************** [55.123]\n"
    "[0]\n"
    "* [0.01]\n";
  SteveAssert(emptycomparestring == emptychart.GenerateChart());
}

int main(int argc, char **argv) {
  ACC_SimpleTest();
  return EXIT_SUCCESS;
}
