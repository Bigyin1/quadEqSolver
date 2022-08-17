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
  quadEquation testCoeffs; /**< Input equation  */
  eqSolution refSolution; /**< Input equation solution for comparison */
} testCase;


/**
 *  @brief Compares quadratic equations solutions
 *  @details
 *    Uses combined tolerance test(http://realtimecollisiondetection.net/blog/?p=89) to compare roots
 *    epsilon = 1.0e-8;  threshold = 1.0
 *  @param s1 solution to be tested
 *  @param s2 reference solution
 *  @return true if tolerance test passes
 *
 */
bool cmpSolutions (const eqSolution *s1, const eqSolution *s2);

#endif
