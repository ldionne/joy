/*!
 * This file defines a macro to compute the symmetric difference between
 * two sets.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_SYMMETRIC_DIFFERENCE_H
#define JOY_SET_SYMMETRIC_DIFFERENCE_H

#include <joy/set/union.h>
#include <joy/set/difference.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the symmetric difference of two sets as a new set.
 *
 * (i.e. all elements that are in exactly one of the sets.)
 */
#define JOY_SET_SYMMETRIC_DIFFERENCE(a, b) \
    JOY_SET_SYMMETRIC_DIFFERENCE_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_SYMMETRIC_DIFFERENCE_S(s, a, b)                                \
    JOY_SET_UNION_S(s,                                                         \
        JOY_SET_DIFFERENCE_S(s, a, b), JOY_SET_DIFFERENCE_S(s, b, a)           \
    )                                                                          \
/**/

#endif /* !JOY_SET_SYMMETRIC_DIFFERENCE_H */
