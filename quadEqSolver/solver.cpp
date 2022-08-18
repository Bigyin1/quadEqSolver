/** @file */
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "solver.hpp"


bool isEqualFloats (double d1, double d2) {

  if (fpclassify(d1) != fpclassify(d2)) {
    return false;
  }

  double diff = fabs(d1 - d2);
  if (isnan(diff)) {
    return true;
  }

  const double eps = 1.0e-8;
  const double threshold = 1.0;

  d1 = fabs(d1);
  d2 = fabs(d2);
  double largest = (d2 > d1) ? d2 : d1;
  largest = (largest < threshold) ? threshold : largest;

  if (diff <= largest * eps) {
    return true;
  }

  return false;
}


void solveLinear (eqSolution *s, const double b, const double c) {
    assert(s != NULL);

    if (isEqualFloats(b, 0) && isEqualFloats(c, 0)) {
        s->state = INF_ROOTS;
        return;
    }
    if (isEqualFloats(b, 0)) {
        s->state = NO_ROOTS;
        return;
    }

    s->state = ONE_ROOT;
    s->x1 = -c / b;
}


static double evalRoot (const quadEquation *eq, const double descriminantRootSigned) {
    assert(eq != NULL);

    return (-eq->b + descriminantRootSigned) / (2.0 * eq->a);
}


void solveQuadEq (const quadEquation *eq,  eqSolution *s) {
    assert(eq != NULL && s != NULL);

    s->x1 = NAN;
    s->x2 = NAN;

    if (!isfinite(eq->a) || !isfinite(eq->b) || !isfinite(eq->c)) {
        s->state = NO_ROOTS;
        return;
    }

    if (isEqualFloats(eq->a, 0)) {
        solveLinear (s, eq->b, eq->c);
        return;
    }

    double descriminantRoot = sqrt(pow(eq->b, 2.0) - 4.0 * eq->a * eq->c);
    if (isnan(descriminantRoot)) {
        s->state = NO_ROOTS;
        return;
    }
    s->x1 = evalRoot(eq, descriminantRoot);
    s->x2 = evalRoot(eq, -descriminantRoot);

    s->state = TWO_ROOTS;
}
