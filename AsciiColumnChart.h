// Copyright 2013 Steve Gribble.

#ifndef _HW2_ASCIICOLUMNCHART_H_
#define _HW2_ASCIICOLUMNCHART_H_

#include <list>
#include <string>

// This class can be used to generate a string that is a simple ASCII
// representation of a column chart. A column chart is an ordered
// sequence of columns, where each column has a (string) label and a
// (double) height, e.g.:
//
//   col_a : ************ [42.6]
//   col_b : ****         [12.8]
//   col_c : ******       [18.5]
class AsciiColumnChart {
 public:
  // Creates an empty AsciiColumnChart.
  AsciiColumnChart() { }

  virtual ~AsciiColumnChart() { }

  // Adds a column to the set to chart. The order in which you add
  // columns is the order in which they are printed out.
  void AddColumn(std::string name, double height);

  // Generates a list of column strings (without newlines).
  std::list<std::string> GenerateColumns(void) const;

  // Generates the full chart (including newlines) as a string.
  std::string GenerateChart(void) const;

 private:
  std::list<std::pair<std::string, double>> columns_;
};

#endif // _HW2_ASCIICOLUMNCHART_H_
