/*!
 * This file defines a macro to compute the intersection between two maps.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_INTERSECTION_H
#define JOY_MAP_INTERSECTION_H

#include <joy/map/core.h>
#include <joy/set/intersection.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the intersection of two maps as a new map.
 */
#define JOY_MAP_INTERSECTION(a, b) \
    JOY_MAP_INTERSECTION_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_INTERSECTION_S(s, a, b) \
    JOY_I_MAP_SET_SET(a, JOY_SET_INTERSECTION_S(s, a, b))

#endif /* !JOY_MAP_INTERSECTION_H */
