/** @file */
#ifndef QUAD_EQ_SOLVER_HPP
#define QUAD_EQ_SOLVER_HPP


/**
 * @brief Holds equation coefficients.
 */
struct quadEquation
{
    double a; /**< x^2 coefficient */
    double b; /**< x coefficient */
    double c; /**< free coefficient */
};

typedef struct quadEquation quadEquation;

/**
 * @brief Holds equation solutions and additional information.
 */
struct eqSolution
{
    double x1; /**< first solution; holds NAN if equation has <=1 solutions */
    double x2; /**< second solution; holds NAN if equation has <=1 solutions */
    double x; /**< solution; holds NAN if equation has >1 or 0 solutions */
    bool anyX; /**< true if equation has infinite number of solutions*/
    bool hasSolution; /**< true if equation has >0 solutions*/
};

typedef struct eqSolution eqSolution;

/**
 *  @brief Solves quadratic equation
 *  @param eq  Equation coefficients structure
 *  @return Equation solution structure
 */
eqSolution solveQuadEq (const quadEquation eq);

#endif
