/** @file */

#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "quadEqSolver/solver.hpp"
#include "testUtils/testUtils.hpp"
#include "testdata.hpp"


static void readOutTermInputQueue() {
  int c = 0;
  while (1) {
    c = getchar();
    if (c == '\n' || c == EOF)
      return;
  }
}


static void reportEquationResults(quadEquation *eq, eqSolution *s) {
  assert(eq != NULL && s != NULL);

  printf("Solved: ");
  printQuadEquation(eq);
  switch (s->state) {
    case NO_ROOTS:
      printf("\tNo solutions\n");
      break;
    case INF_ROOTS:
      printf("\tInfinite number of solutions\n");
      break;
    case ONE_ROOT:
      printf("\tOne solution:\tx = %lf\n", s->x1);
      break;
    case TWO_ROOTS:
      printf("\tTwo solutions:\tx1 = %lf\tx2 = %lf\n", s->x1, s->x2);
      break;
    default:
      fprintf(stderr, "undefined eqSolution state\n");
      exit(EXIT_FAILURE);
  }
}

static void interactive() {

  double a = NAN, b = NAN, c = NAN;
  int valuesRead = 0;

  printf("Enter 3 real coefficients for quadratic equation:\n");

  while ((valuesRead = scanf("%lf %lf %lf", &a, &b, &c)) != EOF) {
    if (valuesRead != 3) {
      printf("Wrong input\n");
      readOutTermInputQueue();
      continue;
    }

    quadEquation eq = {.a = a, .b = b, .c = c};
    eqSolution s = {.x1 = NAN, .x2 = NAN, .state = NO_ROOTS};
    solveQuadEq(&eq, &s);
    reportEquationResults(&eq, &s);
  }
}


/**
 *  @brief Entrypoint
 */
int main(int argc, char **argv) {

  if (argc > 2) {
    printf("Wrong program arguments count\n");
    return EXIT_FAILURE;
  }
  if (argc == 2) {
    if (strcmp(argv[1], "test") == 0) {
      runTests(tests, sizeof(tests) / sizeof(testCase));
      return EXIT_SUCCESS;
    }
    printf("Wrong program argument: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  interactive();
  return EXIT_SUCCESS;
}
