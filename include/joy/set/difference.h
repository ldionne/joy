/*!
 * This file defines a macro to compute the difference between two sets.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_DIFFERENCE_H
#define JOY_SET_DIFFERENCE_H

#include <joy/set/contains.h>
#include <joy/set/filter.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/logical/not.h>


/*!
 * Return the difference of two sets as a new set.
 *
 * (i.e. all elements that are in this set but not the other.)
 */
#define JOY_SET_DIFFERENCE(a, b) \
    JOY_SET_DIFFERENCE_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_DIFFERENCE_S(s, a, b) \
    JOY_SET_FILTER_S(s, a, JOY_I_SET_DIFFERENCE, b)

#define JOY_I_SET_DIFFERENCE(s, element, other) \
    CHAOS_PP_NOT(JOY_SET_CONTAINS_S(s, other, element))

#endif /* !JOY_SET_DIFFERENCE_H */
