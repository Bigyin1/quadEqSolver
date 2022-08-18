/** @file */

#include <float.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "testUtils.hpp"



bool cmpSolutions (const eqSolution *s1, const eqSolution *s2) {
  assert(s1 != NULL && s2 != NULL && s1 != s2);

  if (s1->state != s2->state) {
    return false;
  }

  if (!isEqual(s1->x1, s2->x1) || !isEqual(s1->x2, s2->x2)) {
    return false;
  }

  return true;
}


void runTests (const testCase tests[], const size_t testsCount) {
  uint passed = 0, failed = 0;

  for (uint i = 0; i < testsCount; ++i) {
    testCase test = tests[i];

    printf("%s: ", test.label);
    eqSolution s = {.x1 = NAN, .x2 = NAN, .state = NO_ROOTS};
    solveQuadEq (&test.testCoeffs, &s);
    if (cmpSolutions(&s, &test.refSolution)) {
      ++passed;
      printf("PASS\n");
    } else {
      ++failed;
      printf("FAIL\n");
    }
  }
  printf("PASSED: %u\tFAILED: %u\n", passed, failed);
}
