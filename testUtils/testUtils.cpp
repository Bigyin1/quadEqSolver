/** @file */

#include <float.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "testUtils.hpp"


const char *green = "\x1b[92m";
const char *red = "\x1b[91m";
const char *resetColour = "\x1b[0m";


void printQuadEquation(const quadEquation *eq) {
  assert(eq != NULL);

  printf("%lf(x^2) ", eq->a);
  printf("%c %lf(x) ", eq->b >= 0 ? '+' : '-', fabs(eq->b));
  printf("%c %lf", eq->c >= 0 ? '+' : '-', fabs(eq->c));
  printf(" = 0");
}

static void reportFailedTest(const quadEquation *eq) {
  assert(eq != NULL);

  printf("%sFAIL%s\n", red, resetColour);
  printQuadEquation(eq);
  putchar('\n');
}


bool cmpSolutions(const eqSolution *s1, const eqSolution *s2) {
  assert(s1 != NULL && s2 != NULL && s1 != s2);

  if (s1->state != s2->state) {
    return false;
  }

  return  ((isEqual(s1->x1, s2->x1) && isEqual(s1->x2, s2->x2)) ||
        (isEqual(s1->x1, s2->x2) && isEqual(s1->x2, s2->x1)));
}


void runTests(const testCase tests[], const size_t testsCount) {
  long unsigned passed = 0;

  for (long unsigned i = 0; i < testsCount; ++i) {
    testCase test = tests[i];

    printf("Test №%lu:\t\t%s: ", i + 1, test.label);
    eqSolution s = {.x1 = NAN, .x2 = NAN, .state = NO_ROOTS};
    solveQuadEq (&test.testEquation, &s);
    if (cmpSolutions(&s, &test.refSolution)) {
      ++passed;
      printf("%sPASS%s\n", green, resetColour);
    } else {
      reportFailedTest(&test.testEquation);
    }
  }
  printf("%sPASSED:%s %lu\t%sFAILED:%s %lu\n", green, resetColour,
   passed, red, resetColour, testsCount - passed);
}
