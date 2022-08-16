/** @file */
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "solver.hpp"


static eqSolution solveLinear (const double b, const double c) {
    eqSolution s = {.x1 = NAN, .x2 = NAN, .x = NAN};

    if (fpclassify(b) == FP_ZERO && fpclassify(c) == FP_ZERO) {
        s.anyX = true;
        s.hasSolution = true;
        return s;
    }
    if (fpclassify(b) == FP_ZERO) {
        s.anyX = false;
        s.hasSolution = false;
        return s;
    }

    s.anyX = false;
    s.hasSolution = true;

    s.x = -c / b;
    return s;
}


static double evalRoot (const quadEquation eq, const char sign) {

    if (sign != 1 && sign != -1) {
        assert("fool");
    }

    double descriminant = pow(eq.b, 2.0) - 4.0 * eq.a * eq.c;
    return (-eq.b + sign * sqrt(descriminant)) / (2.0 * eq.a);
}


static bool assertCoefficient (const double coeff) {

    int type = fpclassify(coeff);
    if (type != FP_ZERO && type != FP_NORMAL) {
        return false;
    }
    return true;
}


eqSolution solveQuadEq (const quadEquation eq) {
    eqSolution s = {.x1 = NAN, .x2 = NAN, .x = NAN};
    if (!assertCoefficient(eq.a) || !assertCoefficient(eq.b) || !assertCoefficient(eq.c)) {
        s.anyX = false;
        s.hasSolution = false;
        return s;
    }


    if (fpclassify(eq.a) == FP_ZERO) {
        return solveLinear (eq.b, eq.c);
    }

    s.anyX = false;


    const char plus = 1;
    const char minus = -1;
    if (isnan(s.x1 = evalRoot(eq, plus))) {
        s.hasSolution = false;
        return s;
    }

    if (isnan(s.x2 = evalRoot(eq, minus))) {
        s.hasSolution = false;
        return s;
    }

    s.hasSolution = true;
    return s;
}
