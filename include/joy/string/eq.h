/*!
 * This file defines a macro to test whether two preprocessor strings are equal.
 *
 * @author Louis Dionne
 */

#ifndef JOY_STRING_EQ_H
#define JOY_STRING_EQ_H

#include <joy/string/cmp.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/comparison/equal.h>


#define JOY_STRING_EQ(s1, s2) \
    JOY_STRING_EQ_S(CHAOS_PP_STATE(), s1, s2)

#define JOY_STRING_EQ_S(s, s1, s2)                                             \
    CHAOS_PP_EQUAL(                                                            \
        JOY_STRING_CMP_S(s, s1, s2),                                           \
        JOY_STRING_CMP_EQUAL                                                   \
    )                                                                          \
/**/

#endif /* !JOY_STRING_EQ_H */
