/** @file  Data for quad equation tests */

const testCase tests[] = {
  {
    "Linear No Root",
    {
      .a = 0.0,
      .b = 0.0,
      .c = 3.1234
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  },
  {
    "Linear Has Root",
    {
      .a = 0.0,
      .b = -1.98423,
      .c = -0.07854
    },
    {
      .x1 = -0.039582105,
      .x2 = NAN,
      .state = ONE_ROOT
    }
  },
  {
    "Linear Any Root",
    {
      .a = 0.0,
      .b = 0.0,
      .c = 0.0
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = INF_ROOTS
    }
  },
  {
    "Square No Roots",
    {
      .a = 1.0,
      .b = 2.0,
      .c = 1.012
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  },
  {
    "Square Two Equal Roots",
    {
      .a = 1.0,
      .b = 2.0,
      .c = 1.0
    },
    {
      .x1 = -1.0,
      .x2 = -1.0,
      .state = TWO_ROOTS
    }
  },
  {
    "Square Two Roots",
    {
      .a = 167.188,
      .b = 1234.6876,
      .c = -44.1234
    },
    {
      .x1 = 0.0355652122,
      .x2 = -7.4205904533,
      .state = TWO_ROOTS
    }
  },
  {
    "Square Two Roots Small",
    {
      .a = 0.0018,
      .b = 0.06876,
      .c = 0.000678
    },
    {
      .x1 = -0.0098629305,
      .x2 = -38.1901370695,
      .state = TWO_ROOTS
    }
  },
  {
    "Square Two Roots Big",
    {
      .a = 55.345343645e7,
      .b = 59.345343896123e8,
      .c = 500.789
    },
    {
      .x1 = -8.44e-8,
      .x2 = -10.7227346549,
      .state = TWO_ROOTS
    }
  },
  {
    "Wrong Coeffs",
    {
      .a = NAN,
      .b = 0.8,
      .c = 0.000678
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  },
  {
    "Wrong Coeffs",
    {
      .a = INFINITY,
      .b = 1.2,
      .c = 0.000678
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  },
  {
    "Wrong Coeffs",
    {
      .a = 0.1,
      .b = INFINITY,
      .c = 0.000678
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  },
  {
    "Wrong Coeffs",
    {
      .a = 0.1,
      .b = NAN,
      .c = 0.2
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  },
  {
    "Wrong Coeffs",
    {
      .a = 0.1,
      .b = 0.3,
      .c = NAN
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  },
  {
    "Wrong Coeffs",
    {
      .a = 0.1,
      .b = 0.3,
      .c = INFINITY
    },
    {
      .x1 = NAN,
      .x2 = NAN,
      .state = NO_ROOTS
    }
  }
};
