// Copyright 2013 Steve Gribble.

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "./AsciiColumnChart.h"

// Maximum column name before we truncate.
static unsigned int kMaxColName = 10;

// The max number of stars to draw.
static unsigned int kStarWidth = 50;

// The max amount of chars inside the annotation [].
static unsigned int kAnnotationInsideChars = 10;

void AsciiColumnChart::AddColumn(std::string name, double height) {
  if (height < 0) {
    std::cerr << "AsciiColumnChart::AddColumn() -- please only add "
	      << "positive heights [" << name << ", " << height
	      << "]" << std::endl;
    exit(EXIT_FAILURE);
  }
  columns_.push_back(std::make_pair(name, height));
}

std::list<std::string> AsciiColumnChart::GenerateColumns(void) const {
  // First, figure out the max column name and column heights.
  unsigned int max_colname = 0;
  double max_colheight = 0;
  for (const auto &col : columns_) {
    if (col.first.size() > max_colname) {
      max_colname = col.first.size();
    }
    if (col.second > max_colheight) {
      max_colheight = col.second;
    }
  }

  // We'll truncate column names that are longer than 10 chars.
  if (max_colname > kMaxColName) {
    max_colname = kMaxColName;
  }

  // Figure out how big a "*" is, assuming we want at most kStarWidth *'s.
  double star_width = 0.0;
  if (max_colheight > 0.0) {
    star_width = max_colheight / kStarWidth;
  }

  // Generate the list of columns.
  std::list<std::string> retlist;
  for (const auto &col : columns_) {
    // We're doing the hacky, slower way of string concatenation. :(
    std::string colstring = "";

    // If there is at least one column name, prepend col names to the
    // chart.
    if (max_colname != 0) {
      for (auto i = 0U; i < kMaxColName; ++i) {
	if (i < col.first.size()) {
	  colstring += col.first[i];
	} else {
	  colstring += ' ';
	}
      }
      colstring += " : ";
    }

    // Add the stars to the chart.
    unsigned int num_stars = 0;
    if (star_width != 0.0) {
      num_stars = ceil(col.second / star_width);
      for (auto i = 0U; i < num_stars; ++i) {
	colstring += '*';
      }
    }

    // Add the annotation to the end of the chart.
    if (num_stars != 0) {
      colstring += " ";
    }
    char annotation[1 + kAnnotationInsideChars];
    snprintf(annotation, sizeof(annotation), "%g", col.second);
    colstring += "[" + std::string(annotation) + "]";

    retlist.push_back(colstring);
  }

  return retlist;
}

std::string AsciiColumnChart::GenerateChart(void) const {
  std::list<std::string> cols = GenerateColumns();
  std::string retstring;

  for (const auto &col : cols) {
    retstring += col + "\n";
  }
  return retstring;
}
