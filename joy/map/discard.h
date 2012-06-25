/*!
 * This file defines a macro to discard an element from a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_DISCARD_H
#define JOY_MAP_DISCARD_H

#include <joy/map/core.h>
#include <joy/set/discard.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Remove a key:value pair from a map and return the map thus created.
 *
 * If the key is not in the map, nothing is done.
 */
#define JOY_MAP_DISCARD(map, key) \
    JOY_MAP_DISCARD_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_DISCARD_S(s, map, key)                                         \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_DISCARD_S(s,                                                   \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~)                         \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_MAP_DISCARD_H */
