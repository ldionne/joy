/*!
 * This file defines a macro to remove all the elements in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_CLEAR_H
#define JOY_MAP_CLEAR_H

#include <joy/map/core.h>
#include <joy/set/clear.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return a map with all elements removed from it.
 */
#define JOY_MAP_CLEAR(map) \
    JOY_MAP_CLEAR_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_CLEAR_S(s, map)                                                \
    JOY_I_MAP_SET_SET(                                                         \
        map, JOY_SET_CLEAR_S(s, JOY_I_MAP_SET(map))                            \
    )                                                                          \
/**/

#endif /* !JOY_MAP_CLEAR_H */
