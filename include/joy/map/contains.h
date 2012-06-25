/*!
 * This file defines a macro to check whether a map contains an element with
 * a given key.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_CONTAINS_H
#define JOY_MAP_CONTAINS_H

#include <joy/map/core.h>
#include <joy/set/contains.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return whether a map contains the specified key.
 */
#define JOY_MAP_CONTAINS(map, key) \
    JOY_MAP_CONTAINS_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_CONTAINS_S(s, map, key) \
    JOY_SET_CONTAINS_S(s, JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~))

#endif /* !JOY_MAP_CONTAINS_H */
