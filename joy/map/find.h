/*!
 * This file defines a macro to find an element by its key in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_FIND_H
#define JOY_MAP_FIND_H

#include <joy/map/core.h>
#include <joy/set/find.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the value associated to a key in a map.
 *
 * If the key is not found in the map, default is returned.
 */
#define JOY_MAP_FIND(map, key, default) \
    JOY_MAP_FIND_S(CHAOS_PP_STATE(), map, key, default)

#define JOY_MAP_FIND_S(s, map, key, default)                                   \
    JOY_I_MAP_CELL_VALUE(                                                      \
        JOY_SET_FIND_S(s,                                                      \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~),                        \
                                                JOY_I_MAP_CELL(~, default)     \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_MAP_FIND_H */
