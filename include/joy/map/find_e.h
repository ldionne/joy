/*!
 * This file defines a macro to find an element by its key in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_FIND_E_H
#define JOY_MAP_FIND_E_H

#include <joy/map/core.h>
#include <joy/set/find_e.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the value associated to a key in a map.
 *
 * If the key is not found in the map, a preprocessor error is triggered.
 */
#define JOY_MAP_FIND_E(map, key) \
    JOY_MAP_FIND_E_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_FIND_E_S(s, map, key)                                          \
    JOY_I_MAP_CELL_VALUE(                                                      \
        JOY_SET_FIND_E_S(s,                                                    \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~)                         \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_MAP_FIND_E_H */
