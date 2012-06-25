/*!
 * This file defines a macro to remove an element from a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_REMOVE_H
#define JOY_MAP_REMOVE_H

#include <joy/map/core.h>
#include <joy/set/remove.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Remove a key:value pair from a map and return the map thus created.
 *
 * If the key is not in the map, a preprocessor error is triggered.
 */
#define JOY_MAP_REMOVE(map, key) \
    JOY_MAP_REMOVE_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_REMOVE_S(s, map, key)                                          \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_REMOVE_S(s,                                                    \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~)                         \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_MAP_REMOVE_H */
