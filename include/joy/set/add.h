/*!
 * This file defines a macro to add an element to a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_ADD_H
#define JOY_SET_ADD_H

#include <joy/set/core.h>
#include <joy/set/value_cmp.h>
#include <joy/tree/insert.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Add an element to a set and return the new set.
 *
 * If the element is already present in the set, it is replaced with
 * the new one.
 */
#define JOY_SET_ADD(set, value) \
    JOY_SET_ADD_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_ADD_S(s, set, value)                                           \
    JOY_I_SET_SET_TREE(                                                        \
        set, JOY_TREE_INSERT_S(s,                                              \
            JOY_I_SET_TREE(set), value, JOY_SET_VALUE_CMP(set)                 \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_SET_ADD_H */
