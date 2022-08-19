/** @file */

#include <float.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "testUtils.hpp"


#define GREEN "\x1b[92m"
#define RED "\x1b[91m"
#define RESET_COLOUR "\x1b[0m"


void printQuadEquation(const quadEquation *eq) {
  assert(eq != NULL);

  printf("%lf(x^2)", eq->a);
  printf(" %c %lf(x)",eq->b >= 0 ? '+' : '-', fabs(eq->b));
  printf(" %c %lf",eq->c >= 0 ? '+' : '-', fabs(eq->c));
  printf(" = 0");
}


bool cmpSolutions(const eqSolution *s1, const eqSolution *s2) {
  assert(s1 != NULL && s2 != NULL && s1 != s2);

  if (s1->state != s2->state) {
    return false;
  }

  if (!isEqual(s1->x1, s2->x1) || !isEqual(s1->x2, s2->x2)) {
    return false;
  }

  return true;
}


void runTests(const testCase tests[], const size_t testsCount) {
  uint passed = 0;

  for (uint i = 0; i < testsCount; ++i) {
    testCase test = tests[i];

    printf("Test №%u:\t\t%s: ", i+1, test.label);
    eqSolution s = {.x1 = NAN, .x2 = NAN, .state = NO_ROOTS};
    solveQuadEq (&test.testEquation, &s);
    if (cmpSolutions(&s, &test.refSolution)) {
      ++passed;
      printf("" GREEN "PASS" RESET_COLOUR "\n");
    } else {
      printf("" RED "FAIL" RESET_COLOUR "\t");
      printQuadEquation(&test.testEquation);
      putchar('\n');
    }
  }
  printf("" GREEN "PASSED:" RESET_COLOUR " %u\t" \
   RED "FAILED:" RESET_COLOUR " %lu\n", passed, testsCount - passed);
}
