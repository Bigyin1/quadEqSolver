/** @file */

#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include "quadEqSolver/solver.hpp"
#include "testUtils/testUtils.hpp"


const testCase tests[] = {
  {"linearNoRoot", {.a = 0.0, .b = 0.0, .c = 3.1234}, {.x1 = NAN, .x2 = NAN, .x = NAN, .anyX = false, .hasSolution = false} },
  {"linearHasRoot", {.a = 0.0, .b = -1.98423, .c = -0.07854}, {.x1 = NAN, .x2 = NAN, .x = -0.039582105, .anyX = false, .hasSolution = true} },
  {"linearAnyRoot", {.a = 0.0, .b = 0.0, .c = 0.0}, {.x1 = NAN, .x2 = NAN, .x = NAN, .anyX = true, .hasSolution = true} },
  {"squareNoRoots", {.a = 1.0, .b = 2.0, .c = 1.012}, {.x1 = NAN, .x2 = NAN, .x = NAN, .anyX = false, .hasSolution = false} },
  {"squareTwoEqualRoots", {.a = 1.0, .b = 2.0, .c = 1.0}, {.x1 = -1.0, .x2 = -1.0, .x = NAN, .anyX = false, .hasSolution = true} },
  {"squareTwoRoots", {.a = 167.188, .b = 1234.6876, .c = -44.1234}, {.x1 = 0.0355652122, .x2 = -7.4205904533, .x = NAN, .anyX = false, .hasSolution = true} },
  {"squareTwoRootsSmall", {.a = 0.0018, .b = 0.06876, .c = 0.000678}, {.x1 = -0.0098629305, .x2 = -38.1901370695, .x = NAN, .anyX = false, .hasSolution = true} },
  {"squareTwoRootsBig", {.a = 55.345343645e7, .b = 59.345343896123e8, .c = 500.789}, {.x1 = -8.44e-8, .x2 = -10.7227346549, .x = NAN, .anyX = false, .hasSolution = true} },
  {"wrongCoeffs", {.a = NAN, .b = INFINITY, .c = 0.000678}, {.x1 = NAN, .x2 = NAN, .x = NAN, .anyX = false, .hasSolution = false} },
};


static void runTests () {
  bool ok = true;

  for (uint i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
    testCase test = tests[i];

    printf("%s: ", test.label);

    eqSolution s = solveQuadEq (test.eq);
    if (cmpSolutions(s, test.s)) {
      printf("%s\n", "PASS");
    } else {
      printf("%s\n", "FAIL");
      ok = false;
    }
  }
  ok ? printf("%s\n", "OK") : printf("%s\n", "FAILED");
}


static void interactive () {

  double a, b, c;
  int read;

  printf("Enter 3 coefficients:\n");

  while ((read = scanf("%lf %lf %lf", &a, &b, &c)) != EOF) {
    if (read != 3) {
      printf("Wrong input\n");
      while (getchar() != '\n'){}
      continue;
    }

    quadEquation eq = {.a = a, .b = b, .c = c};
    eqSolution s = solveQuadEq (eq);

    printf("Solved %lfx^2 %lfx %lf : ", a, b, c);
    if (!s.hasSolution) {
      printf("No solutions\n");
      continue;
    }
    if (s.anyX) {
      printf("Infinite number of solutions\n");
      continue;
    }
    if (!isnan(s.x)) {
      printf("One solution:\tx = %lf\n", s.x);
      continue;
    }

    printf("Two solutions:\tx1 = %lf\tx2 = %lf\n", s.x1, s.x2);
  }
}


/**
 *  @brief Entrypoint
 */
int main (int argc, char **) {
  if (argc > 1) {
    runTests();
    return 0;
  }
  interactive();
  return 0;
}
