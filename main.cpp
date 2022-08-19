/** @file */

#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "quadEqSolver/solver.hpp"
#include "testUtils/testUtils.hpp"
#include "testdata.hpp"


static void readOutTermInputQueue() {
  while (getchar() != '\n'){}
}

static void printQuadEquation(const quadEquation *eq) {
  assert(eq != NULL);
  printf("Solved  %lf(x^2)", eq->a);
  printf(" %c %lf(x)",eq->b >= 0 ? '+' : '-', fabs(eq->b));
  printf(" %c %lf(x)",eq->c >= 0 ? '+' : '-', fabs(eq->c));
  printf(" = 0\t");
}


static void interactive () {

  double a = NAN, b = NAN, c = NAN;
  int read = 0;

  printf("Enter 3 real coefficients for quadratic equation:\n");

  while ((read = scanf("%lf %lf %lf", &a, &b, &c)) != EOF) {
    if (read != 3) {
      printf("Wrong input\n");
      readOutTermInputQueue();
      continue;
    }

    quadEquation eq = {.a = a, .b = b, .c = c};
    eqSolution s = {.x1 = NAN, .x2 = NAN, .state = NO_ROOTS};
    solveQuadEq (&eq, &s);

    printQuadEquation(&eq);
    switch (s.state) {
      case NO_ROOTS:
        printf("No solutions\n");
        break;
      case INF_ROOTS:
        printf("Infinite number of solutions\n");
        break;
      case ONE_ROOT:
        printf("One solution:\tx = %lf\n", s.x1);
        break;
      case TWO_ROOTS:
        printf("Two solutions:\tx1 = %lf\tx2 = %lf\n", s.x1, s.x2);
        break;
      default:
        fprintf(stderr, "undefined eqSolution state\n");
        exit(EXIT_FAILURE);
    }
  }
}


/**
 *  @brief Entrypoint
 */
int main (int argc, char **) {
  if (argc > 1) {
    runTests(tests, sizeof(tests)/sizeof(tests[0]));
    return 0;
  }
  interactive();
  return 0;
}
