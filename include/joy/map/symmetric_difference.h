/*!
 * This file defines a macro to compute the symmetric difference between
 * two maps.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_SYMMETRIC_DIFFERENCE_H
#define JOY_MAP_SYMMETRIC_DIFFERENCE_H

#include <joy/map/core.h>
#include <joy/set/symmetric_difference.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the symmetric difference of two maps as a new map.
 */
#define JOY_MAP_SYMMETRIC_DIFFERENCE(a, b) \
    JOY_MAP_SYMMETRIC_DIFFERENCE_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_SYMMETRIC_DIFFERENCE_S(s, a, b) \
    JOY_I_MAP_SET_SET(a, JOY_SET_SYMMETRIC_DIFFERENCE_S(s, a, b))

#endif /* !JOY_MAP_SYMMETRIC_DIFFERENCE_H */
