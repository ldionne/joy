/*!
 * This file defines a macro to add an element in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_ADD_H
#define JOY_MAP_ADD_H

#include <joy/map/core.h>
#include <joy/set/add.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Add a key:value pair to a map and return the map thus created.
 *
 * If the key is already present in the map, the value associated to it is
 * updated with the new one.
 */
#define JOY_MAP_ADD(map, key, value) \
    JOY_MAP_ADD_S(CHAOS_PP_STATE(), map, key, value)

#define JOY_MAP_ADD_S(s, map, key, value)                                      \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_ADD_S(s,                                                       \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, value)                     \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_MAP_ADD_H */
