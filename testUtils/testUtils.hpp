/** @file */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <stdbool.h>
#include "../quadEqSolver/solver.hpp"


/**
 * @brief Holds test cases data.
 */
typedef struct testCase {
  const char *label; /**< Test name */
  quadEquation testEquation; /**< Input equation  */
  eqSolution refSolution; /**< Input equation solution for comparison */
} testCase;


/**
 *  @brief Prints quad equation w/o newline
 *  @param eq equation coefficients
 *
 */
void printQuadEquation(const quadEquation *eq);

/**
 *  @brief Compares quadratic equations solutions
 *  @details
 *    Uses tolerance test to compare roots
 *    epsilon = 1.0e-8
 *  @param s1 solution to be tested
 *  @param s2 reference solution
 *  @return true if tolerance test passes
 *
 */
bool cmpSolutions(const eqSolution *s1, const eqSolution *s2);


/**
 *  @brief Runs tests
 *  @param tests array
 *
 */
void runTests(const testCase tests[], size_t testsCount);

#endif
