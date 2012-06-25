/*!
 * This file defines a macro to discard an element from a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_DISCARD_H
#define JOY_SET_DISCARD_H

#include <joy/set/core.h>
#include <joy/set/value_cmp.h>
#include <joy/tree/remove.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Remove an element from a set and return the new set created.
 *
 * If the element is not found in the set, nothing happens.
 */
#define JOY_SET_DISCARD(set, value) \
    JOY_SET_DISCARD_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_DISCARD_S(s, set, value)                                       \
    JOY_I_SET_SET_TREE(                                                        \
        set, JOY_TREE_REMOVE_S(s,                                              \
            JOY_I_SET_TREE(set), value, JOY_SET_VALUE_CMP(set)                 \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_SET_DISCARD_H */
