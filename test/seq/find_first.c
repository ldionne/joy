/**
 * This file contains unit tests for the seq/find_first header.
 */

#include <joy/seq/find_first.h>

#include <chaos/preprocessor/comparison/equal.h>


#define EQUAL(s, a, b) CHAOS_PP_EQUAL(a, b)

[[[
""JOY_SEQ_FIND_FIRST(EQUAL, CHAOS_PP_SEQ_NIL(), 1) == ""
JOY_SEQ_FIND_FIRST(EQUAL, (1)(2)(3), 1) == 1
JOY_SEQ_FIND_FIRST(EQUAL, (3)(2)(1), 1) == 1
"" JOY_SEQ_FIND_FIRST(EQUAL, (1)(2)(3), 4) == ""
]]]
