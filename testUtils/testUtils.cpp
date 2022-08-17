/** @file */

#include <float.h>
#include <math.h>
#include <assert.h>
#include "testUtils.hpp"



bool cmpSolutions (const eqSolution *s1, const eqSolution *s2) {
  assert(s1 != NULL && s2 != NULL);

  if (s1->state != s2->state) {
    return false;
  }

  if (!cmpFloats(s1->x1, s2->x1) || !cmpFloats(s1->x2, s2->x2)) {
    return false;
  }

  return true;
}
