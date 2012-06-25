/*!
 * This file defines a macro to test whether a preprocessor string is lesser
 * than another.
 *
 * @author Louis Dionne
 */

#ifndef JOY_STRING_LT_H
#define JOY_STRING_LT_H

#include <joy/string/cmp.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/comparison/equal.h>


#define JOY_STRING_LT(s1, s2) \
    JOY_STRING_LT_S(CHAOS_PP_STATE(), s1, s2)

#define JOY_STRING_LT_S(s, s1, s2)                                             \
    CHAOS_PP_EQUAL(                                                            \
        JOY_STRING_COMPARE_S(s, s1, s2),                                       \
        JOY_STRING_CMP_LESSER                                                  \
    )                                                                          \
/**/

#endif /* !JOY_STRING_LT_H */
