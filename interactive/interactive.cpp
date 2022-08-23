/** @file */
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../quadEqSolver/solver.hpp"
#include "../testUtils/testUtils.hpp"
#include "interactive.hpp"

/**
 *  @brief Makes terminal input queue empty
 */
static void readOutTermInputQueue() {
  int c = 0;
  while (1) {
    c = getchar();
    if (c == '\n' || c == EOF)
      return;
  }
}

/**
 *  @brief Prints quadratic equation results to user
 *  @param eq equation coefficients
 *  @param s equation results
 */
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

void interactive() {

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
