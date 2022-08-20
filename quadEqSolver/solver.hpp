/** @file */
#ifndef QUAD_EQ_SOLVER_HPP
#define QUAD_EQ_SOLVER_HPP


/**
 * @brief Holds equation coefficients.
 */
struct quadEquation
{
    double a; /**< x^2 coefficient */
    double b; /**< x^1 coefficient */
    double c; /**< x^0 coefficient */
};

typedef struct quadEquation quadEquation;


/**
 * @brief Holds equation's solutin state.
 */
enum solutionState
{
    NO_ROOTS, /**< if equation has no roots*/
    ONE_ROOT, /**< if equation has one root*/
    TWO_ROOTS, /**< if equation has two roots*/
    INF_ROOTS, /**< if equation has infinite number of solutions*/
};

typedef enum solutionState solutionState;


/**
 * @brief Holds equation solutions and additional information.
 */
struct eqSolution
{
    double x1; /**< first solution; holds NAN if equation has zero or inf solutions */
    double x2; /**< second solution; holds NAN if equation has zero, one or inf solutions */
    solutionState state; /**< roots number*/
};

typedef struct eqSolution eqSolution;

/**
 *  @brief Solves quadratic equation
 *  @param eq   Pointer to equation coefficients structure
 *  @param s    Pointer to equation solution structure
 */
void solveQuadEq(const quadEquation *eq,  eqSolution *s);

/**
 *  @brief Solves linear equation
 *  @param s  pointer to solution structure
 *  @param b  x coefficient
 *  @param c  free coefficient
 *  @return Equation solution structure
 */
void solveLinearEq(eqSolution *s, const double b, const double c);


/**
 *  @brief Compares floats
 *  @details
 *    Uses tolerance test to compare roots
 *    epsilon = 1.0e-8
 *  @param d1 float to be tested
 *  @param d2 reference flost
 *  @return true if tolerance test passes
 */
bool isEqual(double d1, double d2);


/**
 *  @brief Prints quad equation w/o newline
 *  @param eq equation coefficients
 *
 */
void printQuadEquation(const quadEquation *eq);

#endif
