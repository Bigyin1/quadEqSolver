/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testUtils/testUtils.hpp"
#include "interactive/interactive.hpp"
#include "testdata.hpp"


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
