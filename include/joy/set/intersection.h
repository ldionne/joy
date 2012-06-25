/*!
 * This file defines a macro to compute the intersection of two sets.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_INTERSECTION_H
#define JOY_SET_INTERSECTION_H

#include <joy/set/contains.h>
#include <joy/set/filter.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the intersection of two sets as a new set.
 *
 * (i.e. all elements that are in both sets.)
 */
#define JOY_SET_INTERSECTION(a, b) \
    JOY_SET_INTERSECTION_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_INTERSECTION_S(s, a, b) \
    JOY_SET_FILTER_S(s, a, JOY_I_SET_INTERSECTION, b)

#define JOY_I_SET_INTERSECTION(s, element, other) \
    JOY_SET_CONTAINS_S(s, other, element)

#endif /* !JOY_SET_INTERSECTION_H */
