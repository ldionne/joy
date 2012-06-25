/*!
 * This file defines a macro to count the number of elements in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_SIZE_H
#define JOY_MAP_SIZE_H

#include <joy/map/core.h>
#include <joy/set/size.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the number of elements in a map.
 */
#define JOY_MAP_SIZE(map) \
    JOY_MAP_SIZE_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_SIZE_S(s, map) \
    JOY_SET_SIZE_S(s, JOY_I_MAP_SET(map))

#endif /* !JOY_MAP_SIZE_H */
