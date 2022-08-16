/** @file */

#include <float.h>
#include <math.h>
#include "testUtils.hpp"


static bool cmpRoots (double d1, double d2) {

  if (fpclassify(d1) != fpclassify(d2)) {
    return false;
  }

  double diff = fabs(d1 - d2);
  if (isnan(diff)) {
    return true;
  }

  const double epsilon = 1.0e-8;
  const double threshold = 1.0;

  d1 = fabs(d1);
  d2 = fabs(d2);
  double largest = (d2 > d1) ? d2 : d1;
  largest = (largest < threshold) ? threshold : largest;

  if (diff <= largest * epsilon) {
    return true;
  }

  return false;
}


bool cmpSolutions (const eqSolution s1, const eqSolution s2) {

  if (s1.anyX != s2.anyX || s1.hasSolution != s2.hasSolution) {
    return false;
  }

  if (!cmpRoots(s1.x1, s2.x1) || !cmpRoots(s1.x2, s2.x2) || !cmpRoots(s1.x, s2.x)) {
    return false;
  }

  return true;
}
