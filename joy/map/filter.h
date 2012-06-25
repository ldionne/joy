/*!
 * This file defines a macro to filter out elements from a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_FILTER_H
#define JOY_MAP_FILTER_H

#include <joy/map/core.h>
#include <joy/set/filter.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Filter elements of a map according to a predicate.
 *
 * @param predicate A macro(key, auxiliary_data) to determine
 *                  whether to keep an element.
 * @param data Auxiliary data passed to the predicate.
 */
#define JOY_MAP_FILTER(map, predicate, data) \
    JOY_MAP_FILTER_S(CHAOS_PP_STATE(), map, predicate, data)

#define JOY_MAP_FILTER_S(s, map, predicate, data)                              \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_FILTER_S(s, JOY_I_MAP_SET(map), predicate, data)               \
    )                                                                          \
/**/

#endif /* !JOY_MAP_FILTER_H */
