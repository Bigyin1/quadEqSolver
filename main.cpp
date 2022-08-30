/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testUtils/testUtils.hpp"
#include "input/input.hpp"
#include "testdata.hpp"


/**
 *  @brief Entrypoint
 */
int main(int argc, char **argv) {

  if (argc == 3 || argc > 4) {
    printf("Wrong program arguments count\n");
    return EXIT_FAILURE;
  }

  if (argc == 4) {
    cmdArgs(argv + 1);
    return EXIT_SUCCESS;
  }

  if (argc == 2) {

    if (strcmp(argv[1], "--test") == 0) {
      runTests(tests, sizeof(tests) / sizeof(tests[0]));
      return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-i") == 0) {
      interactive();
      return EXIT_SUCCESS;
    }
  }

  printf("Wrong program argument: %s\n", argv[1]);
  return EXIT_FAILURE;
}
