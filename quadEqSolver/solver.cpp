/** @file */
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "solver.hpp"


void printQuadEquation(const quadEquation *eq) {
  assert(eq != NULL);

  printf("%lf(x^2) ", eq->a);
  printf("%c %lf(x) ", eq->b >= 0 ? '+' : '-', fabs(eq->b));
  printf("%c %lf", eq->c >= 0 ? '+' : '-', fabs(eq->c));
  printf(" = 0");
}


bool isEqual(double d1, double d2) {

  if (fpclassify(d1) != fpclassify(d2)) {
    return false;
  }

  double diff = fabs(d1 - d2);
  if (isnan(diff)) {
    return true;
  }

  const double eps = 1.0e-8;
  if (diff <= eps) {
    return true;
  }

  return false;
}


static bool isZero(double d) {
  return isEqual(d, 0);
}


void solveLinearEq(eqSolution *s, const double b, const double c) {
    assert(s != NULL);

    if (isZero(b) && isZero(c)) {
        s->state = INF_ROOTS;
        return;
    }
    if (isZero(b)) {
        s->state = NO_ROOTS;
        return;
    }

    s->state = ONE_ROOT;
    s->x1 = -c / b;
}


void solveQuadEq(const quadEquation *eq,  eqSolution *s) {
    assert(eq != NULL && s != NULL);

    s->x1 = NAN;
    s->x2 = NAN;

    if (!isfinite(eq->a) || !isfinite(eq->b) || !isfinite(eq->c)) {
        s->state = NO_ROOTS;
        return;
    }

    if (isZero(eq->a)) {
        solveLinearEq(s, eq->b, eq->c);
        return;
    }

    double descriminantRoot = sqrt(pow(eq->b, 2) - 4 * eq->a * eq->c);
    if (isnan(descriminantRoot)) {
        s->state = NO_ROOTS;
        return;
    }
    s->x1 = (-eq->b + descriminantRoot) / (2 * eq->a);
    s->x2 = (-eq->b - descriminantRoot) / (2 * eq->a);

    s->state = TWO_ROOTS;
}
