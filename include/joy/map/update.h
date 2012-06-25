/*!
 * This file defines a macro to update the content of a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_UPDATE_H
#define JOY_MAP_UPDATE_H

#include <joy/map/core.h>
#include <joy/set/update.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Update the content of a map with the content of another.
 */
#define JOY_MAP_UPDATE(a, b) \
    JOY_MAP_UPDATE_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_UPDATE_S(state, a, b)                                          \
    JOY_I_MAP_SET_SET(a,                                                       \
        JOY_SET_UPDATE_S(state,                                                \
            JOY_I_MAP_SET(a),                                                  \
            JOY_I_MAP_SET(b)                                                   \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_MAP_UPDATE_H */
