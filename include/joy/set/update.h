/*!
 * This file defines a macro to update the content of a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_UPDATE_H
#define JOY_SET_UPDATE_H

#include <joy/set/core.h>
#include <joy/set/value_cmp.h>
#include <joy/tree/update.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Update the content of a set with the content of another.
 */
#define JOY_SET_UPDATE(a, b) \
    JOY_SET_UPDATE_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_UPDATE_S(state, a, b)                                          \
    JOY_I_SET_SET_TREE(a,                                                      \
        JOY_TREE_UPDATE_S(state,                                               \
            JOY_I_SET_TREE(a),                                                 \
            JOY_I_SET_TREE(b),                                                 \
            JOY_SET_VALUE_CMP(a)                                               \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_SET_UPDATE_H */
