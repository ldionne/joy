/*!
 * This file defines a macro to compute the union of two maps.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_UNION_H
#define JOY_MAP_UNION_H

#include <joy/map/core.h>
#include <joy/set/union.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the union of two maps as a new map.
 */
#define JOY_MAP_UNION(a, b) \
    JOY_MAP_UNION_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_UNION_S(s, a, b) \
    JOY_I_MAP_SET_SET(a, JOY_SET_UNION_S(s, a, b))

#endif /* !JOY_MAP_UNION_H */
